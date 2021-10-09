#pragma once

#include <vector>
#include <string>

#define DEBUG true

// Stores the structure for a loop.
// Onces the interpreter reaches the "[" symbol the loop structure is pushed
// back in the loop vector.
struct LoopStructure
{
    uint32_t beginningCell;
    uint32_t conditionalCell;
};

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
        std::vector<LoopStructure> m_loops;

        void incrementPointer ();
        void decrementPointer ();
        void increaseCellValue ();
        void descreaseCellValue ();
        void outputCell ();
        void readIntoCell ();
        void beginLoop (uint32_t expressionIndex);
        void endLoop (std::string::iterator it);
};
