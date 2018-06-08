all: dynamic static
	./static
	./dynamic

#add the static lib and assemble the program
static: main.o libmathfuncsstat.a ranlib
	gcc -static main.o -L. -lmathfuncsstat -o static

#add the dynamic lib and assemble the program
dynamic: main.o libmathfuncsdyn.so
	gcc main.o -L. -lmathfuncsdyn -o dynamic

#add index to the static library
ranlib: libmathfuncsstat.a 
	ranlib libmathfuncsstat.a

#create a dynamic version of the library
libmathfuncsdyn.so: mathfuncs.o
	gcc -shared -o libmathfuncsdyn.so mathfuncs.o

#compile a static version of the library
libmathfuncsstat.a: mathfuncs.o
	ar rc libmathfuncsstat.a mathfuncs.o

#compile the library source into an object
mathfuncs.o: mathfuncs.cpp
	gcc -fPIC -c mathfuncs.cpp

#compile the program source into an object
main.o: main.cpp
	gcc -c main.cpp


#install the dynamic library
install: 
	install libmathfuncsdyn.so /usr/lib

#uninstall the dtnamic library
uninstall:
	rm /usr/lib/libmathfuncsdyn.so

#clean the old files
clean: 
	rm -rf *.o *.a *.so static dynamic 

