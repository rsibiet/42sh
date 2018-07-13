/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdugot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 14:40:52 by mdugot            #+#    #+#             */
/*   Updated: 2016/07/26 14:06:02 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

char	*read_one_line(int treat_backslash, t_shell *sh)
{
	char	*line;
	char	*tmp;
	char	*tmp2;
	int		status;

	line = NULL;
	init_signal(sh->edit->term, 1);
	status = get_next_line(0, &line);
	while (interrupt(-1) != 1 && (line[ft_strlen(line) - 1] == '\\' &&
				treat_backslash && status > 0))
	{
		line[ft_strlen(line) - 1] = '\0';
		tmp = line;
		status = get_next_line(0, &tmp2);
		line = ft_strjoin(tmp, tmp2);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	init_signal(sh->edit->term, 0);
	if (interrupt_read(&line))
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\\' && treat_backslash)
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

char	**split_read_line_default(int treat_backslash, int max, t_shell *sh)
{
	int		i;
	char	**split;
	char	*line;

	line = read_one_line(treat_backslash, sh);
	if (line == NULL)
		return (NULL);
	i = 0;
	if (treat_backslash)
		line = protect_backslash(line);
	while (line[i])
	{
		if (line[i] == '\t' || line[i] == '\n')
			line[i] = ' ';
		i++;
	}
	split = ft_strsplit_max(line, ' ', max);
	if (treat_backslash)
	{
		i = -1;
		while (split[++i])
			split[i] = unprotect(split[i]);
	}
	ft_strdel(&line);
	return (split);
}

void	add_all_variables(t_cmd_param *param,
		int treat_backslash, t_shell *sh, int err)
{
	int		i;
	char	**split;
	int		number_var;
	int		split_size;

	number_var = count_params(param);
	split = split_read_line_default(treat_backslash, number_var, sh);
	if (split == NULL)
		return ;
	split_size = ft_strsplit_size(split);
	param = param->args;
	i = 0;
	while (param)
	{
		if (is_correct_varname(param->param, err, "read"))
		{
			if (i < split_size)
				sh->local = env_add(sh->local, param->param, split[i]);
			else
				sh->local = env_add(sh->local, param->param, "");
			i++;
		}
		param = param->args;
	}
	ft_deltab(split, split_size);
}

int		input_error(t_command *c, int err)
{
	if (c->fd_in[CLOSED])
	{
		ft_printf_fd(err, "42sh: read: read error: 0: Bad file descriptor\n");
		return (1);
	}
	return (0);
}

void	do_read(t_command *cmd, t_shell *sh, int out, int err)
{
	int			treat_backslash;
	t_cmd_param *params;
	t_cmd_param *tmp;

	(void)out;
	if (input_error(cmd, err) || cmd->argc <= 1)
		return ;
	treat_backslash = 1;
	params = parse_arguments(cmd, "r", "");
	if (ft_strcmp(params->param, "fail") == 0)
	{
		read_error(params, err, sh);
		return ;
	}
	if (find_existing_param(&params, "r"))
		treat_backslash = 0;
	tmp = params;
	if (find_existing_param(&tmp, "other"))
		add_all_variables(tmp, treat_backslash, sh, err);
	goto_begin_args(&params);
	free_options_list(&params);
}
