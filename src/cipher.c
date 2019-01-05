
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cipher.h"

char encryptLetter(char str, int key){
    char s = str;
    if(str >= 'a' && str <= 'z'){
        s = (((str+key) - 'a')%26)+'a';
    }else if( str >= 'A' && str <= 'Z'){
        s = (((str+key) - 'A')%26)+'A';
    }
    return s;
}

char decryptLetter(char str, int key){
    char s;
    if(str >= 'a' && str <= 'z'){
        s = (((str-key) - 'a')%26)+'a';
    }else if( str >= 'A' && str <= 'Z'){
        s = (((str-key) - 'A')%26)+'A';
    }
    return s;
}

char *encrypt(int key, char* fileName) {
    FILE *rFile;

    char *path = fileName;

    char *buffer = malloc(100 * sizeof(char)); // buffer di scrittura
    char *str = malloc(100 * sizeof(char));

    rFile = fopen(path, "r"); // Apro il file in sola lettura
    if (rFile == NULL) {
        printf("CC: No such file or directory\n");
        exit(EXIT_FAILURE);
    }

    while (rFile) {
        if (feof(rFile)) {
            fclose(rFile);
            break;
        }
        fread(str, 1, 100, rFile);
    }

    int i;
    for (i = 0; i < strlen(str); i++) {
        if (encryptLetter(str[i], key) != 0) buffer[i] = encryptLetter(str[i], key);
    }

    printf("\nEncrypted file: \n====================================\n%s\n", buffer);
    fclose(rFile);
    return buffer;
}

char *decrypt(int key, char* fileName) {
    FILE *rFile;
    char *path = fileName;
    char *buffer = malloc(100 * sizeof(char)); // buffer di scrittura
    char *str = malloc(100 * sizeof(char));
    rFile = fopen(path, "r"); // Apro il file in sola lettura

    if (rFile == NULL) {
        printf("CC: No such file or directory\n");
        exit(EXIT_FAILURE);
    }

    while (rFile) {
        if (feof(rFile)) {
            fclose(rFile);
            break;
        }
        fread(str, 1, 100, rFile);
    }

    int i;
    for (i = 0; i < strlen(str); i++) {
        if (decryptLetter(str[i], key) != 0) buffer[i] = decryptLetter(str[i], key);
    }
    printf("\nDecrypted file: \n====================================\n%s\n", buffer);

    return buffer;
}
