# Gina Brainfuck Interpreter
## About
The Gina Brainfuck Interpreter is a [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) interpreter written in C++. It has two modes Simple and Advanced Mode. Simple Mode is where only the seven basic commands are valid and Advanced Mode has additional commands included. The goal of this project is to be used to interface with a website and be used on my portfolio.

## Brainfuck Basics
Brainfuck is a Turing complete esoteric language. Imagine a large ribbon of paper divided into cells. There is a pen at the very start of the ribbon. This pen can traverse the ribbon as well as write values to the cell.
### The Seven Basic Commands
| Command | Description |
| ----------- | ----------- |
| `>` | Increments the pointer by 1 cell.|
| `<` | Decrements the pointer by 1 cell. |
| `+` | Add 1 to the value of the cell the pointer is located at. |
| `-` | Subtracts 1 to the value of the cell the pointer is located at. |
| `.` | Outputs the value of the cell he pointer is located at. |
| `,` | Allows the user to input one byte of data and store its value in the byte at the data pointer.|
| `[]` | Loop the expression on the inside until the initial cell the pointer was at is 0. |
All other text is considered comments.
#### Example Program
```
[->+<] ensures the starting cell is 0.
++ cell 0 is 2 (c0 = 2).
> +++++ c1 = 5
[
    < + adds 1 to c0
    > - subtracts 1 from c1
]

The program has added 5 to 2 with the result stored in c0, but because the value is not ascii encoded it can not be printed. The value of the cell must be encoded.

++++ ++++ c1 = 8
[
    < +++ +++ add 6 to c0
    > - subtracts 1 from c1
]
< . prints the value of c0 which has the value of 55 which is the ascii value of "7".
```
