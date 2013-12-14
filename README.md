필요한 Framework 및 설정
-------------------------------------

**필요한 Framework**

* ACE-6.2.2 Framework - http://download.dre.vanderbilt.edu/previous_versions/ACE-6.2.2.tar.gz

**목적**

ACE Framework로 동기/비동기 서버 기능 테스트.

** 사전에 설치해야할 것들. **

* **아래는 설치 순서대로 기술한다.**

```
$ wget http://download.dre.vanderbilt.edu/previous_versions/ACE-6.2.2.tar.gz
$ tar xvfz ACE-6.2.2.tar.gz
$ vi ~/.bash_profile
ACE_ROOT=/home/vagrant/ACE_wrappers; export ACE_ROOT

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ACE_ROOT/ace:$ACE_ROOT/lib:/usr/local/lib:/usr/lib; export LD_LIBRARY_PATH

PATH=$PATH:.:$JAVA_HOME/bin:$HOME/bin; export PATH

$ source ~/.bash_profile
$ cd ACE_wrappers
$ cd ace
$ ln -s config-linux.h config.h
$ cd $ACE_ROOT/include/makeinclude
$ ln -s platform_linux.GNU platform_macros.GNU
$ cd $ACE_ROOT
$ make
$ cd /home/vagrant/ACE_wrappers/examples/Threads
$ make
$ ./task_one
(140169006995200) in iteration 1
(140169006995200) in iteration 2
(140169006995200) in iteration 3
(140169006995200) in iteration 4
(140169006995200) in iteration 5
(140169031112480) done
```

** 소스 컴파일 **

```
git clone https://github.com/mimul/aceServer.git
cd aceServer/src
make server
make asyncserver
```
