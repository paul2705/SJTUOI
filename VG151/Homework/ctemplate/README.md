# README

Author: ENGR151-21 teaching group

Date  : October 2021

This is a template for students to complete your homework.
You should follow the instructions carefully.
Failing to do so WILL lead to deduciton.
The graceful period has past, guys and girls.
This file is also a sample README for you.

## USAGE

First, READ THE CODE!

Write your corresponding exercise in ex1.c, ex2.c, etc.
Each file contains functions for the corresponding assignment.
These source file should always include "assignment.h"
Declare the function for your exercise in "assignment.h"
If the assignment contains less then 4 exercises,
Delete the extra file. (And declaration in "assignment.h")

## COMPILING
For command line, run 

`gcc -Wall -Wextra -pedantic -Werror main.c ex1.c ex2.c ex3.c ex4.c -o out`

For IDE users:

Figure out where the compiler options can be adjusted and make sure you include at 
least `-Wall -Wextra -pedantic -Werror`

## RUNNING
Run your output executable. Either (in command line) with

`./out.exe -exi` or `./out -exi`

For exercise i, or (For IDEs) click "Run" then input the exercise number
(an integer) into program to run a specific exercise.

## Extra information

Keep assignment source files named in this form.
Meaning:
1. Readme file should be README, or README.md.
2. Each exercise named as "exi.c". all lower case letters.
3. Only push the cource code (`.c` and `.h` files) to git, never include `.exe, .o, .out` files. If in rare cases you need to upload other files than `c` and `.h` files, please state it clearly in your homework README.
