#include <string>
#include <iostream>

#include "GinaBFInterpreter.hpp"

Interpreter::Interpreter ()
{
    // Sets the tape and pointer.
    m_tape = std::vector<uint8_t>(30000, 0);

    m_pointer = 0;
}

void Interpreter::executeExpression (std::string expression)
{
    for (std::string::iterator it = expression.begin(); it != expression.end(); ++it)
    {
        switch (*it)
        {
            case '>':
                incrementPointer();
                break;
            case '<':
                decrementPointer();
                break;
            case '+':
                increaseCellValue();
                break;
            case '-':
                descreaseCellValue();
                break;
            case '.':
                outputCell();
                break;
            case ',':
                readIntoCell();
                break;
            default:
                break;
        }
    }
}

void Interpreter::incrementPointer() { ++m_pointer; }
void Interpreter::decrementPointer() { --m_pointer; }
void Interpreter::increaseCellValue () { m_tape[m_pointer]++; }
void Interpreter::descreaseCellValue () { m_tape[m_pointer]--; }
void Interpreter::outputCell () { std::cout << std::to_string(m_tape[m_pointer]); }
void Interpreter::readIntoCell() { std::cin >> m_tape[m_pointer]; }
