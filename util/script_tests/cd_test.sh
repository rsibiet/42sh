rm -rf test_lnk
rm -rf lnk
rm -rf test_no_access
cd ..
pwd
cd sh42
pwd
cd -P ..
pwd
cd -P sh42
pwd
cd -P ../sh42/includes/../////////
pwd
mkdir test_lnk
mkdir test_lnk/to_lnk
mkdir test_no_access
ln -s test_lnk/to_lnk lnk
cd lnk
pwd
cd ..
pwd
cd -P lnk
pwd
cd ../..///////////
pwd
cd /
pwd
cd -
pwd
cd /../..
pwd
cd -
pwd
cd /../../
pwd
cd -
pwd
cd
pwd
cd -
pwd
cd ~
pwd
cd -
pwd
cd test_no_access
pwd
chmod 000 .
cd ..
pwd
cd test_no_access
pwd
chmod 777 test_no_access
cd test_no_access
pwd
rm -rf ../test_no_access
cd .
pwd
cd ../test_no_access
pwd
cd ..
pwd
cd weghrsergr
pwd
cd -L qefwwegeaafer
pwd
cd -P ewfrgqergaerg
pwd
cd ~
pwd
cd /weghrsergr
pwd
cd -L /qefwwegeaafer
pwd
cd -P /ewfrgqergaerg
pwd
cd ~
pwd
cd /weghr/sergr
pwd
cd -L /qefw/wegeaafer
pwd
cd -P /ewfrg/qergaerg
pwd
cd ~
pwd
cd weghr/sergr
pwd
cd -L qefw/wegeaafer
pwd
cd -P ewfrg/qergaerg
pwd
cd ~
pwd
cd weghr/sergr/
pwd
cd -L qefw/wegeaafer/
pwd
cd -P ewfrg/qergaerg/
pwd
cd ~
pwd
cd weghrsergr/
pwd
cd -L qefwwegeaafer/
pwd
cd -P ewfrgqergaerg/
pwd
cd /.
pwd
cd ~
cd /.wrgewgrwerg
pwd
cd .
pwd
cd .ergwergewrg
cd
cd /
pwd
cd usr/
pwd
rm -rf test_no_access
rm -rf test_lnk
rm -rf lnk
exit
