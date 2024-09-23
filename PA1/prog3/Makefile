all: prog3

prog3: prog3.c
	gcc -g -std=gnu99 prog3.c -o prog3 -lm
prog3_32: prog3.c
	gcc -g -m32 -std=gnu99  prog3.c -o prog3_32 -lm
prog3_64: prog3.c
	gcc -g -m64 -std=gnu99 prog3.c -o prog3_64 -lm
clean:
	rm -rf prog3 prog3_32 prog3_64

