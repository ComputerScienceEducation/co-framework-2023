# *********************************************************************************
# * Program name: my_printf                                                       *
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

.text
# your strings here

.global my_main
.global my_printf


my_main:
        # IMPLEMENT ME

my_printf:
        # IMPLEMENT ME
