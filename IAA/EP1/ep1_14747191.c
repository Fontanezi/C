// EACH USP - SISTEMAS DE INFORMAÇÃO - IAA - SEGUNDO SEMESTRE DE 2023 - EP1
// JOÃO PAULO FERNANDES FONTANEZI - 14747191

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILENAME 256

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Este programa exige dois argumentos: Um inteiro N (dimensão da matriz) e o nome do arquivo de entrada.\n");
        exit(1);
    }

    return 0;
}
{
    FILE *f = fopen(arquivo, "w");
    fileprint(f);
    fclose(f);
}