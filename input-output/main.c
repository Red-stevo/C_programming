#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//global stream object.
FILE *stream;

void writefile(char filepath[]){

    const char data[] = "Why Use size_tPortability: Using size_t ensures that \n"
                  "your code is portable across different platforms and architectures,\n"
                  "as it will automatically adjust to the appropriate size for the system.\n"
                  "Correctness: Since size_t is unsigned, it is less likely to cause errors related\n"
                  "to negative values when dealing with sizes and counts, which should always be \n"
                  "non-negative.In summary, size_t is an unsigned integer type specifically designed \n"
                  "for representing sizes and counts in a portable and platform-independent way, making \n"
                  "it a crucial part of writing robust and portable C code.\n";

    //open a stream to write in a file.
    stream = fopen(filepath,"w");

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

void readfile(char filepath[]){

    char *data = NULL;
    size_t len = 0;


    //stream to open the file reading.
    stream = fopen(filepath, "r");

    //check and print error.
    if (stream == NULL){
        perror("Unable to create a stream.\n");
        exit(1);
    }


    while (getline(&data, &len, stream) != -1)
        puts(data);

}

void customebuffer(char filepath[]){
    stream = fopen(filepath, "r");
    char buffer[200];
    int mode = _IOLBF;
    size_t size = sizeof(buffer);

    if(setvbuf(stream, buffer, mode, size) == 0)
        puts(buffer);
    else
        perror("error reading file.");

    fread(buffer, sizeof(char), sizeof(buffer), stream);

    puts(buffer);
}

int main(void){
    //path for the new file.
   const char filepath[] = "../text-files/sample.txt";

    writefile(filepath);

    //readfile(filepath);

    //customebuffer(filepath);

    return 0;
}
