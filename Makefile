all:
	gcc -o files files.c

run: all
	./files

clean:
	rm files
