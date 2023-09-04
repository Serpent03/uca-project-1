cc = gcc
ccFlags = -Wall -g
bash = bash -c
libName = rlib

main: render.c rlib.a
	${cc} render.c -o main -L . ${libName}.a

rlib.a:	func_lib.c render.h
	${cc} ${ccFlags} -c func_lib.c
	${bash} "ar -rcs ${libName}.a *.o"

clean:
	${bash} "rm *.o ; rm *.a ; clear"

