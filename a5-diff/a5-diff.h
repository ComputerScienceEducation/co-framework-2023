#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ERR_MSG_SIZE 1024
#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE 32768

void zero_newlines(char *);
int diff(FILE *, FILE *, bool, bool);
