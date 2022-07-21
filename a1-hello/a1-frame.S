# *********************************************************************************
# * Program name: Hello World                                                     *
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
#endif

.text
# your strings here

.global my_main                         # make my_main accessible globally

my_main:
	# IMPLEMENT ME    
