#include <stdio.h>
#include <stdlib.h>

typedef char *string;
typedef char Cor;

#define PRETO '0'
#define BRANCO '1'
#define MISTO 'm'

char matriz[1024][1024];
int tamanhoImagem;
int majorBranco[16];
int majorPreto[16];

void processar(string, string);
void leImagem(string);
void printarImagem();
Cor corDoQuadrado(int, int, int, int);
void printarTamanho();
void saida();

int main(int argc, string argv[])
{
    string tamanhoString = argv[1];
    string nomeDoArquivo = argv[2];
    processar(tamanhoString, nomeDoArquivo);
}

void processar(string tamanhoString, string nomeDoArquivo)
{
    tamanhoImagem = strtol(tamanhoString, NULL, 10);
    leImagem(nomeDoArquivo);
    Cor cor = corDoQuadrado(0, 0, tamanhoImagem, 0);
    if (cor == BRANCO)
    {
        majorBranco[0]++;
    }
    if (cor == PRETO)
    {
        majorPreto[0]++;
    }
    // leImagem(nomeDoArquivo); //printarImagem();
    // corDoQuadrado(0,0, tamanhoImagem,0); printarTamanho();
    saida();
}

Cor corDoQuadrado(int linha, int coluna, int tamanho, int profundidade)
{
    if (tamanho == 1)
    {
        return matriz[linha][coluna];
    }
    else
    {
        int tamanhoDoQuadrante = tamanho / 2;
        Cor corTopLeft = corDoQuadrado(linha, coluna, tamanhoDoQuadrante, profundidade + 1);
        Cor corTopRight = corDoQuadrado(linha, coluna + tamanhoDoQuadrante, tamanhoDoQuadrante, profundidade + 1);
        Cor corBottomLeft = corDoQuadrado(linha + tamanhoDoQuadrante, coluna, tamanhoDoQuadrante, profundidade + 1);
        Cor corBottomRight = corDoQuadrado(linha + tamanhoDoQuadrante, coluna + tamanhoDoQuadrante, tamanhoDoQuadrante, profundidade + 1);
        if (corTopLeft == corTopRight && corTopRight == corBottomLeft && corBottomLeft == corBottomRight)
        {
            return corTopLeft;
        }
        else
        {
            if (corTopLeft == BRANCO)
            {
                majorBranco[profundidade + 1]++;
            }
            if (corTopLeft == PRETO)
            {
                majorPreto[profundidade + 1]++;
            }
            if (corTopRight == BRANCO)
            {
                majorBranco[profundidade + 1]++;
            }
            if (corTopRight == PRETO)
            {
                majorPreto[profundidade + 1]++;
            }
            if (corBottomLeft == BRANCO)
            {
                majorBranco[profundidade + 1]++;
            }
            if (corBottomLeft == PRETO)
            {
                majorPreto[profundidade + 1]++;
            }
            if (corBottomRight == BRANCO)
            {
                majorBranco[profundidade + 1]++;
            }
            if (corBottomRight == PRETO)
            {
                majorPreto[profundidade + 1]++;
            }
            return MISTO;
        }
    }
}

void printarTamanho()
{
    int tamanho = tamanhoImagem;
    int prof = 0;
    while (tamanho >= 1)
    {
        int branco = majorBranco[prof];
        int preto = majorPreto[prof];
        // printf("%ix%i, %i, %i \n",tamanho, tamanho, branco,preto);
        prof++;
        tamanho /= 2;
    }
}

void printarImagem()
{
    for (int i = 0; i < tamanhoImagem; i++)
    {
        for (int j = 0; j < tamanhoImagem; j++)
        {
            // printf("%c", matriz[i][j]); }
            // printf("\n"); }
        }
    }
}

void leImagem(string nomeDoArquivo)
{
    // ler imagem d arquivo
    FILE *arquivo = fopen(nomeDoArquivo, "r");
    for (int i = 0; i < tamanhoImagem; i++)
    {
        char buffer[1050];
        fgets(buffer, 1050, arquivo);
        // LER CADA LETRA DA LINHA

        for (int j = 0; j < tamanhoImagem; j++)
        {
            matriz[i][j] = buffer[j];
        }
        // printf("Linha %i: %s", i, buffer); ); }
    }
}

void saida()
{
    FILE *arquivo = fopen("saida.txt", "w");
    int tamanho = tamanhoImagem;
    int prof = 0;
    while (tamanho >= 1)
    {
        int branco = majorBranco[prof];
        int preto = majorPreto[prof];
        fprintf(arquivo, "%ix%i, %i, %i \n", tamanho, tamanho, branco, preto);
        prof++;
        tamanho /= 2;
    }
    fclose(arquivo);
}