#include <stdio.h>

void one_line() {
    FILE *fp;

    char line[81];

    fp = fopen("one_line.txt", "r");

    /*
     * fread(void *ptr
     *       size_t size_of_elements
     *       size_t number_of_elements
     *       FILE *fp)
     */

    fread(line, sizeof(char), sizeof(line)-1, fp);

    printf("This is what we read: %s", line);

    // We're done with the file.
    fclose(fp);
}

void three_lines() {
    FILE *fp;

    char line[81];

    fp = fopen("three_lines.txt", "r");

    while(!feof(fp)) {
        fread(line, sizeof(char), sizeof(line)-1, fp);
        printf("%s\n", line);
    }

    fclose(fp);
}

int main(void) {
}
