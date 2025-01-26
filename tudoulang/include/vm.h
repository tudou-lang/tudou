#ifndef vm_h
#define vm_h 

#include "chunk.h"
#include <cstdint>
#include <cstdio>
#include <stack>
#include "value.h"
#include "debug.h"
#include <stdexcept>

enum InterpretResult{
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} ;


template<typename T>
T BINARY_OP(T a, T b, char op){
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw std::invalid_argument("Division by zero!");
            }
            return a / b;
        default:
            throw std::invalid_argument("Invalid operation!");
    }
}


// 虚拟机
class VM {
    public:
    Chunk* chunk ;
    uint8_t* ip ;
    std::stack<Value> stack ;

    // 初始化
    VM() : chunk(nullptr), ip(nullptr) {}
    // 释放
    ~VM() = default;

    // 解释
    InterpretResult interpret(Chunk* newchunk){
        chunk = newchunk;
        ip = newchunk->code.data();
        return run();
    }

    // 入栈
    void push(Value value){
        stack.push(value);
    }

    // 弹出栈
    Value pop(){
        Value top = stack.top();
        stack.pop();
        return top;
    }

    // 运行
    InterpretResult run(){
        while (true) {
            // read_byte()
            uint8_t instruction = *ip++;
            switch (instruction) {
                case OpCode::OP_ADD:{
                    push(BINARY_OP(pop(), pop(), '+'));
                    break;
                }
                case OpCode::OP_SUBTRACT:{
                    push(BINARY_OP(pop(), pop(), '-'));
                    break;
                }
                case OpCode::OP_MULTIPLY:{
                    push(BINARY_OP(pop(), pop(), '*'));
                    break;
                }
                case OpCode::OP_DIVIDE:{
                    push(BINARY_OP(pop(), pop(), '/'));
                    break;
                }

                case OpCode::OP_NEGATE:{
                    push(-pop());
                    break;
                }
                case OpCode::OP_RETURN:{
                    // 打印弹出的元素
                    printValue(pop());
                    std::printf("\n");
                    return InterpretResult::INTERPRET_OK;
                }
                case OpCode::OP_CONSTANT:{
                    // read_constant() 不用宏
                    uint8_t constantIndex = *ip++;
                    Value constant = chunk->constants.values[constantIndex];
                    // 入栈
                    push(constant);
                    printValue(constant);
                    std::printf("\n");
                    break;
                }
            }
        }
    }
};

template <typename T>
void DEBUG_TRACE_EXECUTION(VM& vm);


#endif