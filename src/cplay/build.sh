gcc $(python3.8-config --cflags) -fPIE -c hello_full_program.c -o hello.o
gcc hello.o $(python3.8-config --ldflags) -lpython3.8 -o test
