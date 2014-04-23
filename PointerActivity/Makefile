test_pointers: main.o read_data.o
	gcc -o test_pointers main.o read_data.o
main.o: main.c
	gcc -c main.c
read_data.o: read_data.c read_data.h
	gcc -c read_data.c
clean:
	rm -f *. *~* *.exe

