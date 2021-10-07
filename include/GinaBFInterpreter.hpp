#pragma once

#include <vector>
#include <string>
#include <map>

class Interpreter
{
    public:
        Interpreter ();

        // Executes the given expression.
        //
        // Parameters
        //      expression (string): The Brainfuck expression to execute.
        void executeExpression (std::string expression);
    private:
        std::vector<uint8_t> m_tape; // A tape where each cell is 8 bits or 1 byte.
        uint32_t m_pointer; // The pointer starts at 0.

        void incrementPointer ();
        void decrementPointer ();
        void increaseCellValue ();
        void descreaseCellValue ();
        void outputCell ();
        void readIntoCell ();
};
