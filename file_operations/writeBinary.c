#include <stdio.h>
#include <string.h>


int main(){

  char text[80];
  char *prt;
  FILE *stream;

 prt = &text;
  //copy text into the array.
  strcpy(prt, "kiswahili kipenzi.\n");

  //open the file for writing.
  stream = fopen("kiswahile.txt", "w");

  //write into the file.
  fwrite(prt, sizeof(char), strlen(text), stream);

  fclose(stream);

  return 0;
}

