#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, char* argv[]) {

    // vm 初始化
    VM vm = VM();

    // chunk 初始化
    Chunk chunk = Chunk();
    int constant = chunk.addConstant(1.2);
    chunk.write_chunk(OpCode::OP_CONSTANT,123);
    chunk.write_chunk(constant,123);

    constant = chunk.addConstant(3.4);
    chunk.write_chunk(OpCode::OP_CONSTANT, 123);
    chunk.write_chunk(constant, 123);

    chunk.write_chunk(OpCode::OP_ADD, 123);

    constant = chunk.addConstant(5.6);
    chunk.write_chunk(OpCode::OP_CONSTANT, 123);
    chunk.write_chunk(constant, 123);

    chunk.write_chunk(OpCode::OP_DIVIDE, 123);

    // chunk.write_chunk(OpCode::OP_NEGATE, 123);
    chunk.write_chunk(OpCode::OP_RETURN,123);
    
    // 反汇编chunk
    disassembleChunk(chunk, "test chunk");
    
    // vm解释
    vm.interpret(&chunk);
    
    return 0;

}