# Buffer Overflow Vulnerability

This is a short tutorial on running a simple buffer overflow on a virtual machine
running Ubuntu. It shows how one can use a buffer overflow to obtain a root 
shell.  This tutorial leverages the paper written by alephOne on buffer overflows:
<http://cecs.wright.edu/~tkprasad/courses/cs781/alephOne.html>

## Initial Setup of the Virtual Machine

```
su root 
sysctl -w kernel.randomize_va_space=0
```

A confirmation of the variable's value is printed `kernel.randomize_va_space = 0`
by the terminal. Such command is used to disable the randomization mechanism used 
to protect the machine against the memory errors attack.

## Example of a Shellcode

The file `call_shellcode.c` containes an example shellcode, which allows one to 
store a `char` in a buffer and then call the shell by a buffer overflow. To run
the shell, we can compile `call_shellcode.c` using the executable stack option
in `gcc`. Running the program `./call_shellcode` from the terminal starts a
shell, which can for instance be used to run programs (e.g., `vim`).

This shellcode was however not injected so this example does not really
correspond to a realistic threat model. Instead, we now show how one can inject
the buffer using a file loaded by a vulnerable program. 

## Vulnerable Program

The vulnerable program is provided in the `stack.c` file. It needs to be made
a set-root-uid in order for the adversary exploiting the buffer overflow to be
able to gain access to a root shell. For that purpose, we compile the file using
root privileges. Furthermore, if `GCC>4.3.3` is used, since the Stack Guard
option is enabled by default, one needs to disable it at compile time (cf. 
below). Note that we also use the executable stack option (to be able to run 
our shellcode from the buffer). Finally, to make the file executable, we `chmod`
the permissions to `4755` on the compiled program `stack`.  

```
su root 
gcc -o stack -z execstack -fno-stack-protector stack.c
chmod 4755 stack 
```

Such compile command is used to disable the data protection execution and the 
canaries. 


## Exploiting the Vulnerability: Demonstration of the Buffer Overflow Attack

We now need to craft the `badfile` file that will be read by this vulnerable
program 'stack' and stored in the buffer, which will be overflowed. The file
`exploit.c` contains code that dumps the buffer that will be read by the
vulnerable program. The code is well commented and should be fairly
understandable and leverages sample code provided in the paper by alephOne. 

To demonstrate the buffer flow attack, we run the following commands:

```
gcc -o exploit exploit.c 
./exploit
./stack
```

This simply compiles and runs the exploit file. The exploit file evaluates the 
stack pointer and crafts a buffer (with the stack pointer and the shellcode) 
and saves it to `badfile`. The vulnerable program `stack` is then executed, it 
reads the file `badfile` and loads the buffer, which triggers the buffer overflow
and executes the shellcode, thus giving us a root shell (designated by `#`). 

Note that the root shell we have obtained is still using our user ID, as proved
by running the `id` command. To solve this and have both the real and effective 
user ids set to root, one can run the included `set_uid_root.c` file.

## Address Randomization: a first defense

One can set Ubuntu's address randomization back on using:

```
$ su root
# /sbin/sysctl -w kernel.randomize_va_space=2
```

Running the attack described in the previous section gives a 
`segmentation fault (core dumped)` error because the address is randomized each
time the program is executed. Therefore, the stack pointer is different and the
`exploit.c` program will not set the address properly anymore for the buffer
flow to run the shellcode. 

## Stack Guard: a second defense

To analyze one defense at a time, it is best to first turn off again address
randomization, as performed in the initial setup. One can then repeat the
buffer overflow attack but this time compiling the vulnerable program `stack`
with the Stack Guard protection mechanism (i.e. removing the flag previously
used: `-fno-stack-protector`). 

```
su root 
gcc -o stack -z execstack stack.c
```

