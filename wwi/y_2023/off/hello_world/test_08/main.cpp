// WITHOUT 'T'
main() {
    asm(
        "movl $11, %%edx \n"
        "movq $0, %%rcx \n"
        "movq $1, %%rax \n"
        "movq $1, %%rdi \n"
        "movq %0, %%rsi \n"
        "syscall \n"
        :
        : "r" ("Hello world")
        : "%rax", "%rdi", "%rsi", "%rdx", "%rcx"
    );

}