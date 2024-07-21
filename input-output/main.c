#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//global stream object.
FILE *stream;

void writeFile(char filePath[]){

    const char data[] = "Why Use size_tPortability: Using size_t ensures that \n"
                  "your code is portable across different platforms and architectures,\n"
                  "as it will automatically adjust to the appropriate size for the system.\n"
                  "Correctness: Since size_t is unsigned, it is less likely to cause errors related\n"
                  "to negative values when dealing with sizes and counts, which should always be \n"
                  "non-negative.In summary, size_t is an unsigned integer type specifically designed \n"
                  "for representing sizes and counts in a portable and platform-independent way, making \n"
                  "it a crucial part of writing robust and portable C code.\n";

    //open a stream to write in a file.
    stream = fopen(filePath,"w");

    //check for errors during the stream creation.
    if (stream == NULL){
        perror("Unable to create stream object.\n");
        exit(1);
    }

    //write the text into the file
    //The function returns the number of characters written tot he file.
    const size_t writenCharacters = fwrite(data, sizeof(char), strlen(data), stream);

    //check for error during data writting.
    if (writenCharacters != strlen(data)){
        perror("Error writing data into the file.\n");
        exit(2);
    }
}


int main(void){
   const char filePath[] = "../text-files/sample.txt";
    writeFile(filePath);

    return 0;
}
