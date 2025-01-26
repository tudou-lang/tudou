#ifndef chunk_h
#define chunk_h

#include "common.h"
#include "value.h"
#include <vector>

enum OpCode: uint8_t {
    // constant variable
    OP_CONSTANT,
    // binary operation
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,

    OP_NEGATE,
    // return
    OP_RETURN,
};

class Chunk{
    public:
    std::vector<uint8_t> code;
    std::vector<int> lines;
    int count = 0;
    ValueArray constants;

    // 初始化
    Chunk() = default;
    // 销毁
    ~Chunk() = default;

    // 写入到chunk
    void write_chunk(uint8_t byte, int line){
        code.push_back(byte);
        lines.push_back(line);
        count += 1;
    }

    // 返回add后const的索引
    int addConstant(Value value){
        constants.writeValueArray(value);
        return constants.count - 1;
    }
};

#endif