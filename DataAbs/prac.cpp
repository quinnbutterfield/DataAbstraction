#include <cstdio>

int main(){
  FILE* f =fopen("testList1.bin", "w+");

  //write sentinel
  fseek(f, sizeof(T), SEEK_SET);
  int prev=0;
  fwrite(&prev, size(int), 1, f);
  int next =0;
  fwrite(&next, sizeof(int), 1, f);

  //write freelist
  int freelist = -1;
  fwrite(&freelist, sizeof(int), 1, f);
  //write sz
}
