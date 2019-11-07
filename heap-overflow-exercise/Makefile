BASE = fastbin_dup malloc_playground first_fit
V2.25 = glibc_2.25/unsafe_unlink glibc_2.25/house_of_force glibc_2.25/house_of_force-exercise
V2.26 = glibc_2.26/unsafe_unlink
PROGRAMS = $(BASE) $(V2.25) $(V2.26)
CFLAGS += -std=c99 -g -no-pie

# Convenience to auto-call mcheck before the first malloc()
#CFLAGS += -lmcheck

all: $(PROGRAMS)
clean:
	rm -f $(PROGRAMS)
