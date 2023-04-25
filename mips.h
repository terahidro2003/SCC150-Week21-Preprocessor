//
// Created by Hellstone on 2023-04-24.
//

#ifndef SCC150_PREPROCESSOR_MIPS_H
#define SCC150_PREPROCESSOR_MIPS_H

//Temp registers:
#define T0 0
#define T1 0
#define T2 0
#define T3 0
#define T4 0

//Registers to enable simple syscalls
#define V0 0
#define A0 0

//REG function-like macro: returns register's value
#define REG(register) mipsReg[register]

//ADDI function-like macro: simulates MIPS addi instruction
#define ADDI(to, op, imm) mipsReg[to] = mipsReg[op] + imm

//LI function-like macro: simulates MIPS li instruction
#define LI(reg, imm) mipsReg[reg] = imm

//MOVE function-like macro: simulates MIPS move instruction
#define MOVE(to, from) mipsReg[to] = mipsReg[from]

//LW function-like macro: simulates MIPS lw instruction
#define LW(to, label) mipsReg[to] = label

//SW function-like macro: simulates MIPS sw instruction
#define SW(from, label) label = mipsReg[from]

//SYSCALL function-like macro: simulates system kernel calls
#define SYSCALL \
if(REG(V0) == 10) return 0;                \
 else if(REG(V0) == 1) printf("%d\n", REG(A0)); \
 else if(REG(V0) == 4) printf("%c\n", REG(A0));

#endif //SCC150_PREPROCESSOR_MIPS_H
