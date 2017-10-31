all:
	gcc -o files files.c

run:
	./files

clean:
	rm files
