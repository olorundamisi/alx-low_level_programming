#!/bin/bash
gcc -c -Wall -Werror -Wextra *.c
ar -r liball.a *.o
ranlib liball.a
