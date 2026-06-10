/*============================================================================
|
| Author: Neil Zambrano
| Language: c
|
| Note:
| All input files are simple 8 bit ASCII input
| All execute commands above have been tested on Eustis
|
+===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 10000
#define MAX_N 9

int readKey(const char *filename, int key[MAX_N][MAX_N]) {
    FILE *fp = fopen(filename, "r");
    int n;
    int i;
    int j;

    if (fp == NULL) {
        return -1;
    }
    if (fscanf(fp, "%d", &n) != 1) {
        fclose(fp);
        return -1;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (fscanf(fp, "%d", &key[i][j]) != 1) {
                fclose(fp);
                return -1;
            }
        }
    }

    fclose(fp);
    return n;
}
int readPlaintext(const char *filename, char text[]) {
    FILE *fp = fopen(filename, "r");
    int ch;
    int len = 0;

    if (fp == NULL) {
        return -1;
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha((unsigned char) ch)) {
            text[len++] = (char) tolower((unsigned char) ch);
        }
    }
    text[len] = '\0';
    fclose(fp);
    return len;
}
void padPlaintext(char text[], int n) {
    int len = (int) strlen(text);

    while (len % n != 0) {
        text[len++] = 'x';
    }
    text[len] = '\0';
}
void encryptText(int key[MAX_N][MAX_N], int n, const char plaintext[], char ciphertext[]) {
    int len = (int) strlen(plaintext);
    int i, j, k;
    int plainVec[MAX_N];
    int sum;
    int out = 0;

    for (i = 0; i < len; i += n) {
        for (j = 0; j < n; j++) {
            plainVec[j] = plaintext[i + j] - 'a';
        }
        for (j = 0; j < n; j++) {
            sum = 0;
            for (k = 0; k < n; k++) {
                sum += key[j][k] * plainVec[k];
            }
            ciphertext[out++] = (char)((sum % 26) + 'a');
        }
    }
    ciphertext[out] = '\0';
}

void printMatrix(int key[MAX_N][MAX_N], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", key[i][j]);
        }
        printf("\n");
    }
}

void print80(const char text[]) {
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        if ((i + 1) % 80 == 0) {
            putchar('\n');
        }
    }
    if (i % 80 != 0) {
        putchar('\n');
    }
}
int main(int argc, char **argv) {
    int key[MAX_N][MAX_N];
    int n;
    char plaintext[MAX_TEXT];
    char ciphertext[MAX_TEXT];

    if (argc != 3) {
        return 1;
    }

    n = readKey(argv[1], key);
    if (n == -1) {
        return 1;
    }

    if (readPlaintext(argv[2], plaintext) == -1) {
        return 1;
    }

    padPlaintext(plaintext, n);
    encryptText(key, n, plaintext, ciphertext);

    printf("\nKey matrix:\n");
    printMatrix(key, n);

    printf("\nPlaintext:\n");
    print80(plaintext);

    printf("\nCiphertext:\n");
    print80(ciphertext);

    return 0;
}

/*=============================================================================
|      I, Neil Zambrano, affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/