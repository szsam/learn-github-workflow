.PHONY: run clean

a.out: hello.c
	gcc hello.c -o a.out

run:
	./a.out

clean:
	rm -rf a.out
