#include <stdio.h>
#include <string.h>

int main(){

  FILE *file;
  char text[80];

  strcpy(text, "bob anasumbua.\n");
  file = fopen("data.txt", "w");
  fwrite(text,1, 15, file);

  printf("%s\n", text);
  fclose(file);
  return 0;

}


