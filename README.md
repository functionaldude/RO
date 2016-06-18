# RO
This repo contains my RO assignements

# About the course
RO is a course at TUGraz. In this course we study logic design and computer organisation. We learn to model synchronous digital systems at functional layer as well as structural layer by using the hardware-design language Verilog. Based on this, we discuss typical concepts found in computer organisation: The fetch/execute algorithm, instruction sets, input and output, the stack, interrupt, handshake, memory technologies, direct memory access, virtual memory, and pipelines.

# Assignement 1
The task was to develop a program which takes numbers from stdin and saves it in an ordered list on the stack. The program had to be implemented in C then rewritten to TOY assembly. (For more info about TOY click [here](http://www.pcengines.ch/toy2.htm)
```
[1-9] -> save the value
0     -> exit
-1    -> print the values in the list
```
## Part 1: C code
The first part of the task is to implement the program in C. After that, I replaced the ```for``` and ```while``` loops with ```if``` and ```goto```. Then I prepared the C code so that it would be easy to rewrite to TOY assembly.

## Part 2: Rewrite
If you take a look at **final.c**, you can see that the C code is very assembly like. The only challenge was to access the array. Here is a quick example how to create and access an array in TOY.
```
                ; Create
A   DUP 20      ; Array A is created

                ; Get the 3rd element
LDA R1  A       ; Load the address of A in R1
LDA R2  2       ; Load 2 in R2 because we want to access the 3rd element
ADD R3  R1  R2  ; Calculate the addres of the 3rd element and save it in R3
LDI R4  R3      ; Load the value in R4

                ; Save 7 in the 3rd place
LDA R1  A       ; Load the address of A in R1
LDA R2  2       ; Load 3 in R2 because we want to access the 3rd element
ADD R3  R1  R2  ; Calculate the addres of the 3rd element and save it in R3
LDA R4  7       ; Load the value 7 in R4
STI R4  R3      ; Store R4 at the address R3
```
# Assignement 2
The task was to implement the same program from **assignement 1** in [Logisim](http://www.cburch.com/logisim/).
