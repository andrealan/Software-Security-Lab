simple-rop: simple-rop.c
	gcc -m32 -O0 -g -static -fno-stack-protector $^ -o $@

.PHONY: clean

clean:
	rm -rf simple-rop
