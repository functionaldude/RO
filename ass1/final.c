#include <stdio.h>

#define BP(i) (i>0)
#define BZ(i) (i==0)

int R0 = 0;
int R1;
int R8;
int R2;
int R3[20];
int R4; //arrayctn
int R5;
int R6;
int R7; //tmp

int main(int argc, const char * argv[]) {
          R1 = 1;
          R4 = 0;
          R8 = R0 - R1;
L_MAIN:   scanf("%d", &R2);
          if (BZ(R2)) goto L_RET;
          R7 = R2 - R8;
          if (BZ(R7)) goto L_PRINT;
          goto L_INSERT;

L_RET:    return 0; //hlt

L_PRINT:  printf("0\n");
          R6 = 0;
L_L1:     R7 = R6 - R4;
          if (BZ(R7)) goto L_MAIN;
          R7 = *(R3+R6);
          printf("%x\n", R7);
          R6 = R6 + R1;
          goto L_L1;

L_INSERT: R5 = 0;
L_L2:     R7 = R5 - R4;
          if (BP(R7)) goto L_L5; //(R5 >= R4)
          if (BZ(R7)) goto L_L5;
          R7 = *(R3+R5) - R2;
          if (BP(R7)) goto L_L5; //(*(R3+R5) > R2)
          R5 = R5 + R1;
          goto L_L2;

L_L5:     R6 = R4-1;
L_L4:     R7 = R6 - R5;
          if (BP(R7)) goto L_L3; //(R6 >= R5)
          if (BZ(R7)) goto L_L3; //(R6 >= R5)
          *(R3+R5) = R2;
          R4 = R4 + R1;
          goto L_MAIN;

L_L3:     *(R3+R6+1) = *(R3+R6);
          R6 = R6 - R1;
          goto L_L4;
}
