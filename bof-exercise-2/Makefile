OV = bof1/bof1 bof2/bof2 bof3/main bof4/bof4 bof5/bof5 bof6/bof6 bof7/bof7
PROGRAMS = $(OV)
CFLAGS += -no-pie -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -zexecstack

# Convenience to auto-call mcheck before the first malloc()
#CFLAGS += -lmcheck

all: $(PROGRAMS)
clean:
	rm -f $(PROGRAMS)

