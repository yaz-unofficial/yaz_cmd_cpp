# yaz_cmd_cpp
## Requires 
* [http://zoom.z3950.org/bind/cplusplus/](http://zoom.z3950.org/bind/cplusplus/)
* [https://www.indexdata.com/resources/software/yazpp/](https://www.indexdata.com/resources/software/yazpp/)
  * [http://ftp.indexdata.dk/pub/yazpp/yazpp-1.6.5.tar.gz](http://ftp.indexdata.dk/pub/yazpp/yazpp-1.6.5.tar.gz)
    * `./buildconf.sh`
    * `./configure`
    * `make`
    * `sudo make install`
  * or
    * `./buildconf.sh`
    * `./configure --prefix=$HOME/myapps`
    * `make`
    * `make install`
    * ...
    * Add `export PATH="$HOME/myapps/bin:$PATH"` to `.bashrc`
    * (Reload file with `source ~/.bashrc`

* needs libyaz from yaz toolkit
  * [https://www.indexdata.com/resources/software/yaz/](https://www.indexdata.com/resources/software/yaz/)
  * [http://ftp.indexdata.dk/pub/yaz/yaz-5.27.1.tar.gz](http://ftp.indexdata.dk/pub/yaz/yaz-5.27.1.tar.gz)
    * `./buildconf.sh`
    * `./configure`
    * `make`
    * `sudo make install`
  * or
    * `./buildconf.sh`
    * `./configure --prefix=$HOME/myapps`
    * `make`
    * `make install`
    * ...
    * Add `export PATH="$HOME/myapps/bin:$PATH"` to `.bashrc`
    * (Reload file with `source ~/.bashrc`

## Building
* `cmake .`
* `make`

## Usage
`./yaz_cmd_cpp <host> <port> <databaseName> <user> <password> <syntax> <query>`  
`./yaz_cmd_cpp test <number_from_1-5>`  
Syntax is either `mab`or `usmarc`  
Query in ccl format  
