# *********************************************************************************
# * Program name:                                                                 *
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
    putchar: jmp _putchar
    exit: jmp _exit
#endif

.global my_main

my_main:
        # IMPLEMENT ME
