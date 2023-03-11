# Computer Organization Lab Framework

This is the framework for the mandatory assignments of the Computer Organization Lab.  

## Automated testing

We use automated testing on CodeGrade to check the validity of your program.  
In case of any unclarities, the expected results of the CodeGrade AutoTests shall be the binding specification for your program. You are hereby explicitly made aware of the fact that these AutoTests are subject to change until the respective assignment's deadline, and that it is your responsibility to ensure that your program passes the tests.

## Mac Setup

You do not need to build with gcc (i.e., the instructions regarding how to compile and run your program in this README do not apply). Please see Canvas for the details of how to setup the Xcode project provided with this framework.

## Framework files

You are required to use the framework file called `aX-frame.S` for all assignments for which we provide it.

## File endings

In order for the lab framework to work properly, all assembly files need to end in `.S` (note the capital S).

## Assignment 0 - Sieve of Eratosthenes Example Program

You can use this example assignment to familiarize yourself with x86\_64 Assembly and to test your setup.  
To compile, `cd` into the Assignment 0 directory (`a0-sieve` by default).  
`gcc -o sieve sieve.S -g` compiles the program.  
`./sieve` will run the compiled program.  
See the lab guide for more details.

## Assignment 1 - Hello World

For the first assignment, your task is to write a hello world program.  
Use the `a1-frame.S` file to get started.  
To compile, `cd` into the Assignment 1 directory (`a1-hello` by default).  
`gcc -o a1 a1-frame.S -g` compiles the program.  
`./a1` will run the compiled program.  
See the lab guide for detailed instructions.

## Assignment 2 - Inout

Make sure to use `my_main` instead of `main`. You **must** have a global subroutine `my_increment` that takes as input an integer, `n`, and returns as a result `n + 1`.  
You can use the `a2-frame.S` file to get started.  
To compile, `cd` into the Assignment 2 directory (`a2-inout` by default).  
`gcc -o a2 a2-frame.S -g` compiles the program.  
`./a2` will run the compiled program.  
See the lab guide for detailed instructions.

## Assignment 3 - Power

Make sure to use `my_main` instead of `main`. You **must** have a global subroutine `my_pow` that takes as input two integers, first the `base`, then the `exponent`, and returns as a result `base` to the power of `exponent`.  
You can use the `a3-frame.S` file to get started.  
To compile, `cd` into the Assignment 3 directory (`a3-pow` by default).  
`gcc -o a3 a3-frame.S -g` compiles the program.  
`./a3` will run the compiled program.  
See the lab guide for detailed instructions.

## Assignment 4 - Factorial

Make sure to use `my_main` instead of `main`. You **must** have a global subroutine `factorial` that takes as input an integer, `n`, and returns as a result `n` factorial.
You can use the `a4-frame.S` file to get started.  
To compile, `cd` into the Assignment 4 directory (`a4-fac` by default).  
`gcc -o a4 a4-frame.S -g` compiles the program.  
`./a4` will run the compiled program.  
See the lab guide for detailed instructions.

## Assignment 4plus - Fibonacci

Make sure to use `my_main` instead of `main`.

**Important**: You have to submit two separate files for part 1, and another file for part 2, with a specific naming convention as outlined above:

### Part 1

Filename Requirements Part 1:

1. for the recursive solution: \<your filename\>_rec.s
2. for the iterative solution: \<your filename\>_iter.s

You **must** have a global subroutine `fibonacci` that takes as input an integer, `n`, and returns as a result the `n`-th term of the fibonacci sequence.

### Part 2

Filename Requirements Part 2:

1. for the recursive solution: \<your filename\>_repl.s

You will have to write a (global) subtroutine `fibonacci` with the following function signature:  
`uint64_t *fibonacci(int n, int curr_max, uint64_t *addr);`

Hint: the automated tests will test the re-usability of this subroutine by calling it with different values for `addr`.

Argument Description:

1. `n` - integer, the term to calculate
2. `curr_max` - integer, the current maximum calculated term of the sequence
3. `addr` - pointer, the address of the current location of the calculated sequence.
<!-- 
If you want to use a different specification for the fibonacci function, please ask a TA to approve it first. -->

You can use the `a4plus-frame.S` file to get started.  
To compile, `cd` into the Assignment 4-plus directory (`a4plus-fib` by default).  
`gcc -o a4plus a4plus-frame.S -g` compiles the program.  
`./a4plus` will run the compiled program.  

Note: The provided test file here does not contain automated testing for Part 2 of the assignment. Feel free to extend this yourself.

See the lab guide for detailed instructions.

## Assignment 5A - Diff (excludes 5B)

You will have to write a function diff with the following function signature:  
`int diff(FILE *a, FILE *b, bool i_flag, bool B_flag);`

You can assume that no line is longer than 1024 characters.

You can use the `a5-diff-frame.S` file to get started.  
To compile, `cd` into the Assignment 5A - Diff directory (`a5-diff` by default).  
`gcc -o a5-diff a5-diff-main.c a5-diff-frame.S -g` compiles the program.  
`./a5-diff` will run the compiled program.  

## Assignment 5B - Hash (excludes 5A, not for Mac)

Unfortunately, this assignment only works on x86_64 machines. If you are using a Mac, please do Assignment 5A - Diff instead.  
You can use the `my-sha1-chunk.S` file to get started.  
To compile, `cd` into the Assignment 5B - Hash directory (`a5-hash` by default).  
`gcc -o test-a5-hash my-sha1-chunk.S ./sha1_test64.so -no-pie` compiles the program.  
`./test-a5-hash` will run the compiled program.  

## Assignment 6 - Printf

Make sure to use `my_main` instead of `main`. You **must** have a global subroutine `my_printf` that takes as input a variable number of arguments. Make sure to support any number of arguments.  
You can use the `a6-frame.S` file to get started.  
To compile, `cd` into the Assignment 6 directory (`a6-printf` by default).  
`gcc -o a6 a6-frame.S -g` compiles the program.  
`./a6` will run the compiled program.  
See the lab guide for detailed instructions.

## Automated testing, `MACOS` flag, and more  -- Framework Explanation

The automated tests on CodeGrade and the special setup required to compile x86_64 on macOS are the the reason you can find a snippet like the one below in all of the assignment frame files:

```
.ifndef CODEGRADE            # if the symbol CODEGRADE is not defined
.global main                 # define global main
main:
        jmp my_main          # just go to my_main
.endif


#ifndef MACOS                   # if the symbol MACOS is not defined
.ifndef CODEGRADE               # if the symbol CODEGRADE is not defined
    .global main                # define global main
    main: jmp my_main           # in main, unconditionally jump to my_main
.endif
#else                           # else (if MACOS is defined)
    .global _main               # define global _main (note the underscore)        
    _main: jmp my_main          # in _main, unconditionally jump to my_main
    printf: jmp _printf         # in printf, unconditionally jump to _printf
#endif
```

For example, if we are in the root directory of this framework and want to compile assignment 2 together with the provided `main.c` file, this can be achieved by running  
`gcc -o a2withmain a2-inout/a2-frame.S main.c -no-pie -Wa,--defsym,CODEGRADE=1 -g`  
The option `-Wa,--defsym,CODEGRADE=1` tells the assembler to define a symbol `CODEGRADE` that has the value `1`. This is equivalent to inserting the line  
`.equ CODEGRADE, 1`  
above the `.ifndef CODEGRADE` in your source file.  

The reason the assembly files all end in a capital `.S` is that, by default, `gcc` only invokes the C preprocessor (see also `man cpp`) on assembly files with an upper case file ending. The C preprocessor is needed for the `MACOS` flag; you don't need to concern yourself with it as the Xcode project already adds this flag for you.

The files `test_cc.c` provided for (almost) all assignments are simplified versions of the files we use for testing on CodeGrade. If you want to play around with them and explore how these things work, just compile `test_cc.c` and your assignment source file together and try running them.

## Online Compiler

Should you have no option to run code locally, there is an [online compiler](onlinegdb.com). Please note that this is not maintained by us and that we do explicitly not provide any support for issues that you may have when using the online compiler.
Your best bet when using the online compiler is to use the `aX-frame.S` files for each assignment. Should you want to pass a flag to the online compiler, you can do so by clicking the little cog in the top right, then clicking "extra compiler flags".
