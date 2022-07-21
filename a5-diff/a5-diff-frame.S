# *********************************************************************************
# * Program name: diff                                                            *
# * Description : Line-by-line diff                                               *
# *********************************************************************************

#ifdef MACOS
    .global _diff
    _diff: jmp diff
    fgets: jmp _fgets
    fread: jmp _fread
    fprintf: jmp _fprintf
    fscanf: jmp _fscanf
    printf: jmp _printf
    strcasecmp: jmp _strncasecmp
    strcmp: jmp _strcmp
    strcpy: jmp _strcpy
    strlen: jmp _strlen
    strncasecmp: jmp _strncasecmp
    strncmp: jmp _strncmp 
    strncpy: jmp _strncpy
    strnlen: jmp _strnlen
#endif


.text

changestring: 
            .ascii "%dc%d\n"
		    .ascii "< %s\n"
		    .ascii "---\n"
		    .asciz "> %s\n"


# ************************************************************************
# * Subroutine: diff
# * Description: A simplified line-by-line implementation of diff
# * Specification: int diff(FILE *a, FILE *b, bool i_flag, bool B_flag);         
# ************************************************************************
diff:
	# IMPLEMENT ME


