#include <stdio.h>

int rom[16] = {5,6,2,3,0,0,0,0,0,0,0,0,0,0,0,0};
int ram[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int romCounter = 0;
int pos;
int outer;

int main(int argc, const char * argv[]) {

  while (romCounter < 16 && rom[romCounter] != 0) {
    //if (rom[romCounter] == 0) break;
    pos = 0;

    while (pos < romCounter && ram[pos] <= rom[romCounter]) {
      pos++;
    }

    outer = romCounter - 1;
    while (outer >= pos) {
      ram[outer+1] = ram[outer];
      outer--;
    }
    ram[pos] = rom[romCounter];
    romCounter++;
  }

  printf("{");
  for (int i = 0; i < 16; i++) {
    printf("% d ", ram[i]);
  }
  printf("}\n");
  return 0;
}
