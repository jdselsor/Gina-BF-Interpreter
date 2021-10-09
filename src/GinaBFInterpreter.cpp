#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

#include "GinaBFInterpreter.hpp"

Interpreter::Interpreter ()
{
    // Sets the tape and pointer. The tape is 30000 cells long.
    m_tape = std::vector<uint8_t>(30000, 0);
    m_loops = std::vector<LoopStructure> ();

    m_pointer = 0;
}

Interpreter::Interpreter(uint32_t tapeLength)
{
    m_tape = std::vector<uint8_t>(tapeLength, 0);
    m_loops = std::vector<LoopStructure> ();

    m_pointer = 0;
}

void Interpreter::executeProgram (std::string expression)
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
                // TODO: Need to convert this into a method.
                LoopStructure lastLoop = m_loops.back();

                if (m_tape[m_pointer] == 0)
                {
                    m_loops.pop_back();
                }
                else
                {
                    it = expression.begin() + lastLoop.beginningCell;
                }
                break;
        }
    }

    std::string line;
    std::getline(std::cin, line);
    m_outputs.push_back (line);
}
std::string Interpreter::readProgramFromfile (std::string path)
{
    std::string program;

    std::ifstream file (path);
    std::string line;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            program += line;
        }

        file.close();
    }
    else
    {
        std::cout << "Unable to open file at " << path << std::endl;
    }

    return program;
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
    // TODO: change this from c style to what ever the best way to do this in
    //       c++.
    putchar(m_tape[m_pointer]);
}

void Interpreter::readIntoCell()
{
    // std::cout << "Input Value: ";
    // std::cin >> m_tape[m_pointer];
    m_tape[m_pointer] = getchar();
}

void Interpreter::beginLoop (uint32_t expressionIndex)
{
    LoopStructure loop;

    loop.beginningCell = expressionIndex;

    m_loops.push_back (loop);
}
