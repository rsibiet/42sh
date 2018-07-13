/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 10:00:09 by mressier          #+#    #+#             */
/*   Updated: 2016/07/26 14:04:35 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int			cd_error(int err, char *path)
{
	if (access(path, F_OK) == -1)
	{
		ft_printf_fd(err, "cd: No such file or directory: %s\n", path);
		return (-1);
	}
	else if (is_directory(path) == 0)
	{
		ft_printf_fd(err, "cd: Is not a directory: %s\n", path);
		return (-1);
	}
	else if (access(path, X_OK) == -1)
	{
		ft_printf_fd(err, "cd: Permission denied: %s\n", path);
		return (-1);
	}
	return (0);
}

void		read_error(t_cmd_param *params, int err, t_shell *sh)
{
	ft_printf_fd(err, "42sh: read: %s: invalid option\n",
		params->args->param);
	ft_printf_fd(err, "read: usage: read [-r] var ...\n");
	change_status(sh, 1);
	goto_begin_args(&params);
	free_options_list(&params);
}

int			interrupt_read(char **line)
{
	if (interrupt(-1) == 1)
	{
		ft_strdel(line);
		return (1);
	}
	return (0);
}
