#include "debug.h"
#include "chunk.h"
#include <cstdio>

static int simpleInstruction(const char* name, int offset){
    std::printf("%s\n", name);
    return offset + 1;
}

static int constInstruction(const char* name, Chunk& chunk, int offset){
    auto constant = chunk.code[offset+1];
    std::printf("%-16s %4d '", name, constant);
    printValue(chunk.constants.values[constant]);
    std::printf("'\n");
    return offset + 2;
}

void disassembleChunk(Chunk &chunk, const char *name){
    std::printf("== %s ==\n",name);
    for (int offset = 0; offset < chunk.count; ){
        offset = disassembleInstruction(chunk, offset);
    }
}

int disassembleInstruction(Chunk &chunk, int offset){
    std::printf("%04d ", offset);
    if (offset > 0 && chunk.lines[offset] == chunk.lines[offset - 1]) {
        std::printf("   | ");
    }else {
        std::printf("%4d ", chunk.lines[offset]);
    }
    uint8_t instruction = chunk.code[offset];
    switch (instruction) {
        case OpCode::OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        case OpCode::OP_CONSTANT:
            return constInstruction("OP_CONSTANT", chunk, offset);
        // binary operation
        case OpCode::OP_ADD:
            return simpleInstruction("OP_ADD", offset);
        case OpCode::OP_SUBTRACT:
            return simpleInstruction("OP_SUBTRACT", offset);
        case OpCode::OP_MULTIPLY:
            return simpleInstruction("OP_MULTIPLY", offset);
        case OpCode::OP_DIVIDE:
            return simpleInstruction("OP_DIVIDE", offset);
        
        // negative sign
        case OpCode::OP_NEGATE:
            return simpleInstruction("OP_NEGATE", offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}
