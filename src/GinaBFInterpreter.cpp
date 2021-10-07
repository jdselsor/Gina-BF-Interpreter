#include <string>
#include <iostream>
#include <iterator>
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
                endLoop(it);
                break;
            default:
                break;
        }

        std::cout << "END OF FOR LOOP ITERATION" << std::endl;
    }
}

void Interpreter::incrementPointer()
{
    ++m_pointer;
}

void Interpreter::decrementPointer()
{
    --m_pointer;
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
    //putchar(m_tape[m_pointer]);
    std::cout << std::to_string(m_tape[m_pointer]);
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

void Interpreter::endLoop (std::string::iterator &it)
{
    // Get the last element in the loop vector.
    // Check to see if the conditionalCell is 0.
    // If the conditionalCell is 0 continue marching though the expression.
    // Else return to the beginning cell and continue marching though the
    //      expression.

    LoopStructure lastLoop = m_loops.back();
    std::cout << std::to_string(m_tape[m_pointer]) << std::endl;

    if (m_tape[m_pointer] == 0)
    {
        m_loops.pop_back();
        std::cout << "Breaking out of loop" << std::endl;
    }
    else
    {
        it = std::prev (it, lastLoop.beginningCell);
    }
}
