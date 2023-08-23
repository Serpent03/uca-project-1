gcc -Wall -g -c ./func_lib.c
ar -rcs rlib.a *.o
gcc render.c -o main -L . rlib.a
rm *.o
rm *.a
clear
./main.exe