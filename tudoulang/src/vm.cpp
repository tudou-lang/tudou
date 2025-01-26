#include "vm.h"
#include "debug.h"
#include "value.h"

template <typename T>
void DEBUG_TRACE_EXECUTION(VM &vm){
    std::printf("          ");
    std::stack<T> temp = vm.stack;

    while (!temp.empty()) {
        std::printf("[ ");
        printValue(temp.top());
        temp.pop();
        std::printf(" ]");
    }

    std::printf("\n");
    disassembleInstruction(vm.chunk, static_cast<int>(vm.ip-vm.chunk->code.data()));
}
