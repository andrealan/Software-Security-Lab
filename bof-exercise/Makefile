OV = exploit  stack call_shellcode 
PROGRAMS = $(OV)
CFLAGS += -no-pie -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -zexecstack

# Convenience to auto-call mcheck before the first malloc()
#CFLAGS += -lmcheck

all: $(PROGRAMS)
clean:
	rm -f $(PROGRAMS)

