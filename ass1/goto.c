#include <stdio.h>

int value;
int list[20];
int arrayctn = 0;
int pos;
int ctn;

int main(int argc, const char * argv[]) {
L_MAIN:   scanf("%d", &value);
          if (value == 0) goto L_RET;
          if (value == -1) goto L_PRINT;
          goto L_INSERT;

L_RET:    return 0;

L_PRINT:  printf("0\n");
          ctn = 0;
L_L1:     if (ctn == arrayctn) goto L_MAIN;
          printf("%x\n", list[ctn]);
          ++ctn;
          goto L_L1;

L_INSERT: pos = -1;
L_L2:     pos++;
          if (pos < arrayctn && list[pos]<=value) goto L_L2;
          ctn = arrayctn-1;
L_L4:     if (!(ctn < pos)) goto L_L3;
          list[pos] = value;
          arrayctn++;
          goto L_MAIN;

L_L3:     list[ctn+1] = list[ctn];
          ctn--;
          goto L_L4;
}