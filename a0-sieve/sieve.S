# ************************************************************************
# * Program name : sieve                                                 *
# * Description  : this program prints all the prime numbers below 1000  *
# ************************************************************************

#ifndef MACOS
.ifndef CODEGRADE
    .global main
    main: jmp my_main
.endif
#else
    .global _main
    _main: jmp my_main
    printf: jmp _printf
    exit: jmp _exit
#endif

.data
.comm NUMBERS, 1000, 1          # memory space for the number table

.text
formatstr:  .asciz "%d\n"       # format string for number printing

.global my_main
# ************************************************************************
# * Subroutine  : my_main                                                   *
# * Description : application entry point                                *
# ************************************************************************
my_main:
	pushq   %rbp                # store the caller's base pointer
	movq    %rsp, %rbp          # initialize the base pointer

	subq	$16, %rsp           # align stack to 16 bytes
	movq 	$2, -8(%rbp)        # initialize 'number' to 2 on stack   
	
# Initialize the number table:
	movq    $0, %rbx            # initialize 'i' to 0.
loop1:
	leaq    NUMBERS(%rip), %rax # load address of NUMBERS table into rax
	movb    $1, (%rax, %rbx)    # set number table entry 'i' to 'true'
	incq    %rbx                # increment 'i'                      
	cmpq    $1000, %rbx         # while 'i' < 1000                   
	jl      loop1               # go to start of loop1               

# The sieve algorithm:
loop2:
	movq    -8(%rbp), %rbx      # load 'number' into a register
	leaq    NUMBERS(%rip), %rax # load address of NUMBERS table into rax
	cmpb    $1, (%rax, %rbx)   # compare NUMBERS[number] to '1'
	jne     lp2end              # if not equal, jump to end of loop 2
	leaq    formatstr(%rip), %rdi    # first argument: formatstr
	movq    %rbx, %rsi          # second argument: the number
	movq	$0, %rax            # no vector arguments
	call    printf              # print the number
	movq    -8(%rbp), %rbx      # 'multiple' := 'number'
	shlq    $1, %rbx            # multiply 'multiple' by 2

loop3:
	cmpq     $1000, %rbx        # compare 'multiple' to 1000
	jge     lp2end              # goto end of loop2 if greater/equal
	leaq    NUMBERS(%rip), %rax # load address of NUMBERS table into rax
	movb    $0, (%rax, %rbx)    # set number table entry 'i' to 'false'
	addq    -8(%rbp), %rbx      # add another 'number' to 'multiple'
	jmp     loop3               # jump to the beginning of loop 3
lp2end:
	movq    -8(%rbp), %rbx      # load 'number' into a register
	incq    %rbx                # increment 'number' by one
	movq    %rbx, -8(%rbp)      # store 'number' on the stack
	cmpq    $1000, %rbx         # compare 'number' to 1000
	jl      loop2               # if smaller, repeat loop2

end:
	mov     $0, %rdi            # load program exit code
	call    exit                # exit the program

