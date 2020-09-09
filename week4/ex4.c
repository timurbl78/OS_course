#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char line[100];
    char *argv[100];
    while(1) {
        fgets(line, 100, stdin);

        int i;
        for (int i = 0; i < 100; i++) {
            if (line[i] == '\n') {
                line[i] = '\0';
            }
        }

        int index = 0;
        argv[index] = strtok(line, " ");

        while (argv[index] != NULL) {
            index++;
            argv[index] = strtok(NULL, " ");
        }

        int pid = getpid();
        fork();
        if (getpid() != pid) {
            execvp(argv[0], argv);
        }
    }
}
