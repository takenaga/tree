test:
	gcc bt.c compare.c insert.c test.c -o test

clean:
	rm -f test *.o
