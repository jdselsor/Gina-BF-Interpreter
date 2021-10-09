#include <iostream>
#include <string>

#include "GinaBFInterpreter.hpp"

int main ()
{
    Interpreter interpreter;

    std::string program = interpreter.readProgramFromfile("./scripts/cellsize.bf");
    interpreter.executeProgram(program);


    return 0;
}
