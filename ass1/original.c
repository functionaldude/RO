#include <stdio.h>

int value;
int list[20];
int arrayctn = 0;

int main(int argc, const char * argv[]) {
  while (1) {
    scanf("%d", &value);
    if (value == 0) {
      return 0;
    } else if (value == -1) {
      printf("0\n");
      for (int ctn = 0; ctn < arrayctn; ++ctn) {
        printf("%x\n", list[ctn]);
      }
    } else {
      int pos = 0;
      while (pos < arrayctn && list[pos]<=value) {
        pos++;
      }

      int outer = arrayctn-1;
      while (outer >= pos) {
        list[outer+1] = list[outer];
        outer--;
      }
      list[pos] = value;
      arrayctn++;
    }
  }
}