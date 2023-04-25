#include <stdio.h>
#include "mips.h"   //include mini MIPS-library

int mipsReg[5];

int main() {

    ADDI(T0, T1, 3);
    ADDI(T0, T0, 2);
    printf("%d\n", REG(T0));

    LI(T2, 55);
    printf("%d\n", REG(T2));

    MOVE(T1, T2);

    //print $t0 contents
    LI(V0, 1);
    MOVE(A0, T0);
    SYSCALL;

    //print $t1 contents
    LI(V0, 1);
    MOVE(A0, T1);
    SYSCALL;
}
