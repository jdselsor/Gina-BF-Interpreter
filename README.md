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

The program has added 5 to 2 with the result stored in c0,
but because the value is not ascii encoded it can not be printed.
The value of the cell must be encoded.

++++ ++++ c1 = 8
[
    < +++ +++ add 6 to c0
    > - subtracts 1 from c1
]
< . prints the value of c0 which has the value of 55 which is the ascii value of "7".
```

## Basic Mode
**Basic Mode** is traditional Brainfuck where the only valid commands are the [**Seven Basic Commands**](#The Seven Basic Commands). This will be the starting point for the interpreter. **Basic Mode** is a subset of **Advanced Mode** so and code written with basic mode commands only will run in the **Advanced Mode** with the exception of an non-command text being comments. If you run the interpreter in **Advanced Mode** to run **Basic Mode** code you will have to use the comment command.

## Advanced Mode
Advanced mode is a set of additional commands to add functionality and ease of use to the language.

| Command | Description |
| ----------- | ----------- |
| `!text!` | Any text between the symbol(`!`) will be treated as comments |
| `mov(C)` | Moves the pointer to the cell `C`. |
| `add(N)` | Adds the value `N` to the current cell. |
| `sub(N)` | Subtracts the value `N` from the current cell. |
| `print(C)` | Prints the value of the cell or set of cells `C`. |
| `{}` | Conditional block. The `{}` marks the conditional. Expressions in the `{}` will only be run if the current cell's value is `0`. Code separated by the &#124; will divided into `if` `else` where the left hand expression will be executed if the current cell is 0 and the right hand expression will be executed if not. |
| `V` | While not a traditional command is a quick hand for what ever the value of the current cell is. So for example `sub(V)` would set what ever the current cell is to 0. |

### Referencing Cells
The user can reference a cell by using the dollar operator `$`. An example use is `$0` this would reference cell 0. The user can also reference a set of cells using the same dollar operator. An example use is `$0...5` this would reference cells 0 though cell 5 for a total of 6 cells. **NOTE:** This language is 0 indexed so the first cell is cell 0.

### Functions
Advanced mode should support functions. This should act as an separate ribbon that upon completion the value of the function's written to the current cell. It should be written as `func (name / expression)`. This should remove repeated code. To call a function type the `name` followed by `(parameters / cells to write to)`. `parameter` is what the initial cells of the function will be and `cells to write to` are the set of cells to be written to.

#### Example
Function creation
```
!Converts the current cell to an ascii value!
func(convert_to_ascii / ++++ ++++ [< +++ +++ > -])
```
Function call
```
convert_to_ascii ($c3 / $c5)
```

## Interpreter API
This should allow for an API so I can link it in with a website and have the user type script and execute it in the browser.

## Task List
- [ ] Implement "Basic Mode"
    - [x] Seven Basic commands implemented
- [ ] Implement "Advanced Mode"
    - [ ] Tokenization and lexing
    - [ ] Cell value referencing `V`
    - [ ] Cell/Cell Set referencing
    - [ ] Comments, move, add, subtract, print commands implemented
    - [ ] Conditional blocks implemented
    - [ ] Functions implemented
- [ ] File reading
- [ ] Interpreter settings (tape length, cell size, etc.)
- [ ] Interpreter API
