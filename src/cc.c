
#include <stdio.h>
#include <getopt.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cipher.h"

static struct option const long_opts[];
void createFile(char *path, char *buffer);
void printUsage();
void getHelp();
int main(int argc, char *argv[]);

static struct option const long_opts[] =
        {
                {"encrypt", required_argument, NULL, 'e'},
                {"decrypt", required_argument, NULL, 'd'},
                {"help", no_argument, NULL, 'h'},
                {NULL, 0, NULL, 0} // required
        };

void createFile(char *path, char *buffer){
    FILE *wFile;
    wFile = fopen(path, "wb+"); // Creo il file da scrivere
    fwrite(buffer, sizeof(char), 100, wFile);
    fclose(wFile);
}

void printUsage(){
    printf("Usage: CC [OPTION] [SOURCE] [KEY]\n");
    printf("Try 'CC --help' for more information.\n");
    exit(EXIT_SUCCESS);
}

void getHelp(){
    printf("Usage: CC [OPTION] [SOURCE] [KEY]\n");
    printf("Example: CC -e file.txt 5\n\n");
    printf("  -e                        encrypt file\n");
    printf("  -d                        decrypt file\n");
    printf("  -h                        show help\n\n");
    printf("Cesar Cipher developed by Davide Monnati\n\n");
}

int main(int argc, char *argv[]) {
    int c;
    char *buffer = (char*)malloc(sizeof(char));

    if(argc < 2) printUsage();

    while (( c = getopt_long(argc, argv, "edh", long_opts, NULL)) != -1 )
    {
        switch (c){
            case 'e':
                buffer = encrypt(atoi(argv[3]), argv[2]);
                createFile(argv[2], buffer);
                break;

            case 'd':
                buffer = decrypt(atoi(argv[3]), argv[2]);
                createFile(argv[2], buffer);
                break;

            case 'h':
                getHelp();
                break;
        }
    }

    free(buffer);
    return 0;
}
