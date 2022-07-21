# *********************************************************************************
# * Program name: pow                                                             *
# * Description :                                                                 *
# *********************************************************************************

#ifndef MACOS
.ifndef CODEGRADE
    .global main
    main: jmp my_main
.endif
#else
    .global _main
    _main: jmp my_main
    printf: jmp _printf
    scanf: jmp _scanf
    exit: jmp _exit
#endif

.text
# your strings here

.global my_main
.global my_pow


my_main:
        # IMPLEMENT ME

my_pow:
        # IMPLEMENT ME
