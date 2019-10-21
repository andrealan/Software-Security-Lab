OV = uaf-example uaf0
PROGRAMS = $(OV)
CFLAGS += -g -fno-stack-protector -zexecstack

# Convenience to auto-call mcheck before the first malloc()
#CFLAGS += -lmcheck

all: $(PROGRAMS)
clean:
	rm -f $(PROGRAMS)

