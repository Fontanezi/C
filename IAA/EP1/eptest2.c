struct quadrante
{
    int cor;
    int maximal;
};

struct quadrante contarQuadrantes(int dimensaoMax, int dimensao, int expDimensao, int **matriz, int linha, int coluna, int **matrizResposta)
{
    struct quadrante q_max;
    // printf("Tamanho: %d | exp: %d\n", dimensao, expDimensao);

    if (dimensao == 1)
    {
        if (matriz[linha][coluna] == 0)
        {
            q_max.cor = 0;
        }
        else
        {
            q_max.cor = 1;
        }
        q_max.maximal = 1;
    }
    else
    {
        int tamanho = dimensao / 2;

        expDimensao = expDimensao - 1;

        struct quadrante topL = contarQuadrantes(dimensaoMax, tamanho, expDimensao, matriz, linha, coluna, matrizResposta);
        struct quadrante topR = contarQuadrantes(dimensaoMax, tamanho, expDimensao, matriz, linha, coluna + tamanho, matrizResposta);
        struct quadrante bottomL = contarQuadrantes(dimensaoMax, tamanho, expDimensao, matriz, linha + tamanho, coluna, matrizResposta);
        struct quadrante bottomR = contarQuadrantes(dimensaoMax, tamanho, expDimensao, matriz, linha + tamanho, coluna + tamanho, matrizResposta);

        printf("%d %d\n", topL.cor, topR.cor);
        printf("%d %d\n", bottomL.cor, bottomR.cor);

        if (topR.cor == topL.cor && topL.cor == bottomR.cor && bottomR.cor == bottomL.cor)
        {
            if (dimensaoMax == dimensao)
            {
                if (topR.cor == 0)
                    matrizResposta[expDimensao + 1][2] += 1;
                else if (topR.cor == 1)
                    matrizResposta[expDimensao + 1][1] += 1;
            }
            else
            {
                q_max.cor = topR.cor;
                q_max.maximal = 1;
                printf("oq está sendo armazenadao: %d %d %d\n", matrizResposta[expDimensao][0], matrizResposta[expDimensao][1], matrizResposta[expDimensao][2]);
                printf("tamanho: (%d) || QMAX || cor: %d | max: %d\n", (dimensao / 2), q_max.cor, q_max.maximal);
            }
        }
        else
        {
            // fazer para cada caso de quadrante cima/baixo/direita/esquerda
            if (topR.maximal == 1)
            {
                if (topR.cor == 0)
                    matrizResposta[expDimensao][2] += 1;
                else if (topR.cor == 1)
                    matrizResposta[expDimensao][1] += 1;
            }
            if (topL.maximal == 1)
            {
                if (topL.cor == 0)
                    matrizResposta[expDimensao][2] += 1;
                else if (topL.cor == 1)
                    matrizResposta[expDimensao][1] += 1;
            }
            if (bottomR.maximal == 1)
            {
                if (bottomR.cor == 0)
                    matrizResposta[expDimensao][2] += 1;
                else if (bottomR.cor == 1)
                    matrizResposta[expDimensao][1] += 1;
            }
            if (bottomL.maximal == 1)
            {
                if (bottomL.cor == 0)
                    matrizResposta[expDimensao][2] += 1;
                else if (bottomL.cor == 1)
                    matrizResposta[expDimensao][1] += 1;
            }
            q_max.cor = -1;
            q_max.maximal = 0;
            printf("oq está sendo armazenadao: %d %d %d\n", matrizResposta[expDimensao][0], matrizResposta[expDimensao][1], matrizResposta[expDimensao][2]);
            printf("tamanho: (%d) || QMAX || cor: %d | max: %d\n", (dimensao / 2), q_max.cor, q_max.maximal);
        }
    }

    return q_max;
}