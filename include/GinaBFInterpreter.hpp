#pragma once

#include <vector>
#include <string>

// Stores the structure for a loop.
// Onces the interpreter reaches the "[" symbol the loop structure is pushed
// back in the loop vector.
//
// Maybe this should be removed, but incase more information needs to be added
// to the loop structure.
struct LoopStructure
{
    uint32_t beginningCell;
};

class Interpreter
{
    public:
        // The default constructor for the interpreter. Initializes the tape to a length
        // of 30000 cells.
        Interpreter ();
        Interpreter (uint32_t tapeLength);

        // Executes the given Brainfuck program.
        //
        // Parameters
        //      expression (string): The Brainfuck program to execute.
        void executeProgram (std::string expression);

        // Reads the Brainfuck program from the file at the path.
        //
        // Parameters
        //      path (string): The path to the Brainfuck program/script.
        std::string readProgramFromfile (std::string path);

        std::vector<std::string> getOutputs ();
    private:
        std::vector<uint8_t> m_tape; // A tape where each cell is 8 bits or 1 byte.
        uint32_t m_pointer; // The pointer starts at 0.
        std::vector<LoopStructure> m_loops;
        std::vector<std::string> m_outputs;

        void incrementPointer ();
        void decrementPointer ();
        void increaseCellValue ();
        void descreaseCellValue ();
        void outputCell ();
        void readIntoCell ();
        void beginLoop (uint32_t expressionIndex);
};
