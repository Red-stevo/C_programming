#include <stdio.h>
#include <string.h>

void readfile(char* filepath){
    char data[41];
    size_t linesize = 0;

    FILE* stream = fopen(filepath, "r");


    if (stream == NULL){
        perror("Error Opening The File.");
        return;
    }

    fread(data, 1, 40, stream);
    printf("Content : %s\n done\n", data);

    fgets(data, 40, stream);
    puts(data);

    fscanf(stream, "%s",data);
    puts(data);

    /*while (getline(&data,&linesize , stdin) > 0){
        printf("File Content: %s\n", data);
    }*/

    fclose(stream);
}

int main(int argc, char* argv[]){

    if (argc != 2){
        printf("Usage: %s <filepath>\n", argv[0]);
        return 1;
    }

    char name[100];

    printf("File path: %s\n", argv[1]);

    strcpy(name, argv[1]);

    readfile(name);

    return 0;
}
