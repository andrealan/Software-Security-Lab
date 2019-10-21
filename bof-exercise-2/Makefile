OV = bof1/bof1 bof2/bof2 bof3/main
PROGRAMS = $(OV)
CFLAGS += -g -fno-stack-protector -zexecstack

# Convenience to auto-call mcheck before the first malloc()
#CFLAGS += -lmcheck

all: $(PROGRAMS)
clean:
	rm -f $(PROGRAMS)

