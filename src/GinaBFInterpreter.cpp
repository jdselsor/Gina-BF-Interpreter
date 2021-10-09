#include <string>
#include <iostream>
#include <stdio.h>

#include "GinaBFInterpreter.hpp"

Interpreter::Interpreter ()
{
    // Sets the tape and pointer. The tape is 30000 cells long.
    m_tape = std::vector<uint8_t>(30000, 0);
    m_loops = std::vector<LoopStructure> ();

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
            case '[':
                beginLoop(std::distance(expression.begin(), it));
                break;
            case ']':
                LoopStructure lastLoop = m_loops.back();

                if (m_tape[m_pointer] == 0)
                {
                    m_loops.pop_back();
                }
                else
                {
                    it = expression.begin() + lastLoop.beginningCell - 1;
                }
                break;
        }
    }
}

void Interpreter::incrementPointer()
{
    m_pointer++;
}

void Interpreter::decrementPointer()
{
    m_pointer--;
}

void Interpreter::increaseCellValue ()
{
    m_tape[m_pointer]++;
}

void Interpreter::descreaseCellValue ()
{
    m_tape[m_pointer]--;
}

void Interpreter::outputCell ()
{
    putchar(m_tape[m_pointer]);
}

void Interpreter::readIntoCell()
{
    std::cin >> m_tape[m_pointer];
}

void Interpreter::beginLoop (uint32_t expressionIndex)
{
    LoopStructure loop;

    loop.beginningCell = expressionIndex + 1;
    loop.conditionalCell = m_pointer;

    m_loops.push_back (loop);
}
