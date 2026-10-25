main: main.c commands.c commands.h
	clang -arch x86_64 -o main main.c commands.c

asm: main.s

main.s: main.c
	clang -arch x86_64 -S main.c -o main.s

clean:
	rm -rf main main.s

run:
	$(MAKE) clean
	$(MAKE) main
	./main

.PHONY: asm clean run
