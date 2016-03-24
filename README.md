# Compilers_course
In this project you can find the exercises to create a simple compiler in the C language,these may be used to understand the issues 
of the C language

Stack_machine :
  We did a simple stack machine that support addition and subtraction with a stack.
  The stack machine supports 3 operation:
    - (s) this command swaps the first 2 elements of the stack 
    - (x) this command goes out from stack machine
    - (d) this command prints the stack of the stack machine
    - (e) if there is into the stack an mathematical operator like + or - 
          this commad evaluates the expression contained into the stack.
  
Interpreter:
  The interpreter takes a mathematical expression in normal form (1 + 2 - 3) and converts this expression into a expression for the
  stack machine (12+e3-e).
