#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void replace_word(const char *src, const char *word, const char *replacement, char *result) {
    char *pos, temp[MAX_LINE_LENGTH];
    int len = strlen(word);

    while ((pos = strstr(src, word)) != NULL) {
        strncpy(temp, src, pos - src);
        temp[pos - src] = '\0';
        sprintf(temp + (pos - src), "%s%s", replacement, pos + len);
        strcpy(src, temp);
    }
    strcpy(result, src);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: replace [filename] [word] [replacement]\n");
        exit(0);
    }

    FILE *fpt, *new_fpt;
    if ((fpt = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        exit(0);
    }

    char new_filename[100];
    snprintf(new_filename, sizeof(new_filename), "new_%s", argv[1]);
    if ((new_fpt = fopen(new_filename, "w")) == NULL) {
        printf("Unable to open %s for writing\n", new_filename);
        fclose(fpt);
        exit(0);
    }

    char line[MAX_LINE_LENGTH], result[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fpt) != NULL) {
        replace_word(line, argv[2], argv[3], result);
        fputs(result, new_fpt);
    }

    fclose(fpt);
    fclose(new_fpt);
    return 0;
}
