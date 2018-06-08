# testlib-cpp
Simple program using a static and dynamic library with math functions 

Tested on Ubuntu 17.10 and 18.04.

## Build

### Compile and bind

``` bash
#compile
gcc -c main.cpp mathfuncs.cpp
#bind
gcc main.o mathfuncs.o -o result
#run
./result
```

### Compile and link a static library

``` bash
#compile 
gcc -c main.cpp mathfuncs.cpp
#create a static version of the library
ar rc libmathfuncsstat.a mathfuncs.o
#add index
ranlib libmathfuncsstat.a
#add the library to the program
gcc main.o -L. -lmathfuncsstat -o static
#or in case you already created a dynamic library
gcc -static main.o -L. -lmathfuncsstat -o static
#run
./static
```

### Compile and link a dynamic library

``` bash
#compile the program 
gcc -c main.cpp
#compile the library
gcc -fPIC -c mathfuncs.cpp
#create a dynamic version of the library
gcc -shared -o libmathfuncsdyn.so mathfuncs.o
#add the library to the program 
gcc main.o -L. -lmathfuncsdyn -o tdynamic
# add the local path to the environment path (see next section)
#run
./dynamic
```

## To use the dynamic library in Linux, add the local path to the cloned repo to the environment var:

``` bash 
LD_LIBRARY_PATH=/path-to-the-cloned-repo:${LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
```
e.g.
``` bash
LD_LIBRARY_PATH=/home/username/projects/testlib-cpp:${LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
```
## Use the makefile for process automation

### Static lib
``` bash 
make static
./static
```

### Dynamic lib
``` bash
make dynamic
make install
./dynamic
```
\
Tip: don't forget to uninstall the lib after testing via ```make uninstall```.


### Clean old files
```make clean```
