all: lib bin

lib:
	gcc -shared -fpic src/lib/lib.c -o libtest.so

bin:
	gcc -fpic src/bin/reverse_str.c -o reverse_str

clean:
	rm libtest.so reverse_str
