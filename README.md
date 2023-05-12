 <h1 align="center">C - Stacks, Queues - LIFO, FIFO</h1>

![](https://dc722jrlp2zu8.cloudfront.net/media/featured_images/blog-programacion-bit-bit-variables-operadores.jpg)

<hr></hr>

## 📖 Table of Contents
- [Description](#description)
- [Flowchart](#flowchart)
- [Requirements](#requirements)
- [Usage](#usage)
- [Examples](#examples)
- [Description files](#description-files)
- [Contributors](#contributors)

## 📙 Description

+ For this project, we created an interpreter for Monty ByteCodes. The interpreter reads a bytecode file and executes the bytecode commands.
+ The [Monty language Monty](https://montyscoconut.github.io/) 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python).
+ Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.
+ Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account)

## Flowchart

<p align="center">
    <img src="https://res.cloudinary.com/djvwjnzxw/image/upload/v1683841752/monty_wgkwzp.png" alt="Flowchart">
</p>

## 📝 Requirements
To compile hsh you need to intall these tools:
+ `gcc` - For Linux check [this](https://gcc.gnu.org/install/) and for windows check [this](https://www.digitalocean.com/community/tutorials/c-compiler-windows-gcc) 

## Usage

To use this function, 
+ 📥 First clone the repository:
```bash
git clone https://github.com/Ghelder/holbertonschool-monty.git
```
 
+ Go into directory you've clone with `cd`: 
```bash 
cd ./holbertonschool-monty
```
+ Then compile the code with `gcc` and some flags: 
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## Examples

+ push - pall
```bash
root@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
root@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
root@ubuntu:~/monty$
```
+ pint
```bash
root@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
root@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
root@ubuntu:~/monty$ 
```
+ pop
```bash
root@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
root@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
root@ubuntu:~/monty$ 
```
+ swap
```bash
root@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
root@ubuntu:~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
root@ubuntu:~/monty$
```
+ add
```bash
root@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

root@ubuntu:~/monty$ ./monty bytecodes/12.m 
3
2
1
5
1
root@ubuntu:~/monty$
```
## 📁 Description files

| File | Description |
| ------------ | ------------ |
| *main.c* | The main function that runs our interpreter `monty`|
| *monty.h* | All prototypes and includes|
| *aux_functions.c* | Auxiliary functions |
| *arith_modify_stack.c* | Arithmetic functions opcodes |
| *support_functions.c* | Support functions to use in other functions |
| *modify_stack.c* | Functions that modify our stack |
| *keep_stack.c* | Functions that does not modify our stack |

<hr></hr>

<div align="center">
  <h1><strong>Contributors</strong></h1>
</div>

+ Josue Cerrón [@xiayudev](https://github.com/xiayudev)
+ Sharif Abuhadba [@SharifAli645](https://github.com/SharifAli645)
+ Helder Guevara [@Ghelder](https://github.com/Ghelder)
