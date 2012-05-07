#fileOpen
fileOpen:fileOpen.o
	gcc -o fileOpen fileOpen.o
fileOpen.o:fileOpen.c
	gcc -c fileOpen.c
#fileRead
fileRead:fileRead.o
	gcc -o fileRead fileRead.o
fileRead.o:fileRead.c
	gcc -c fileRead.c
#fileWrite
fileWrite:fileWrite.o
	gcc -o fileWrite fileWrite.o
fileWrite.o:fileWrite.c
	gcc -c fileWrite.c
#main
main:main.o
	gcc -o main main.o
main.o:main.c
	gcc -c main.c
#clean
clean:
	rm main.o main fileOpen.o fileOpen fileRead.o fileRead fileWrite fileWrite.o
