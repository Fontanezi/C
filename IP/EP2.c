/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2023                          **/
/**   Prof. Marcos Lordello Chaim                                   **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   João Fontanezi                   14747191                     **/
/**                                                                 **/
/*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NumeroMaxTimes 20
#define NumeroMaxRodadas 38
#define NumeroMaxJogos NumeroMaxTimes *NumeroMaxRodadas

typedef struct auxtime
{
    int PontosGanhos;
    int GolsMarcados;
    int GolsSofridos;
    int SaldoDeGols;
    int Vitorias;
    int Empates;
    int Derrotas;
    float GolAverage;
    char nome[31];
} time;

typedef struct auxjogo
{
    char local[30];
    char visitante[30];
    int golslocal;
    int golsvisitante;
} jogo;

void lenometime(char *s)
{
    int i;
    s[0] = '\0';
    char c;
    c = getchar();
    for (i = 0; c != ',' && i < 30; ++i)
    {
        s[i] = c;
        c = getchar();
    }
    s[i] = '\0';
}

void ordenaPontos(time *timescampeonato, int notimes)
{
    int i, p, posMaior;
    for (i = 0; i < notimes - 1; i++)
    {
        posMaior = i;
        for (p = i + 1; p < notimes; p++)
        {
            if (timescampeonato[p].PontosGanhos > timescampeonato[posMaior].PontosGanhos)
            {
                posMaior = p;
            }
        }
        time aux = timescampeonato[i];
        timescampeonato[i] = timescampeonato[posMaior];
        timescampeonato[posMaior] = aux;
    }
}

void ordenaSaldoGols(time *timescampeonato, int notimes)
{
    int i, p, posMaior;
    for (i = 0; i < notimes - 1; i++)
    {
        posMaior = i;
        for (p = i + 1; p < notimes; p++)
        {
            if (timescampeonato[p].SaldoDeGols > timescampeonato[posMaior].SaldoDeGols)
            {
                posMaior = p;
            }
        }
        time aux = timescampeonato[i];
        timescampeonato[i] = timescampeonato[posMaior];
        timescampeonato[posMaior] = aux;
    }
}

int encontratime(time *timescampeonato, char *nome, int notimes)
{
    for (int i = 0; i < notimes; i++)
    {
        if (strcmp(nome, timescampeonato[i].nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

int crialistatimes(time *timescampeonato, jogo *dadosjogos, int numerojogos)
{

    int pos = 0, notimes = 0;
    for (int i = 0; i < numerojogos; i++)
    {
        if (encontratime(timescampeonato, dadosjogos[i].local, notimes) == -1)
        {
            strcpy(timescampeonato[pos].nome, dadosjogos[i].local);
            pos++;
            notimes++;
        }
        if (encontratime(timescampeonato, dadosjogos[i].visitante, notimes) == -1)
        {
            strcpy(timescampeonato[pos].nome, dadosjogos[i].visitante);
            pos++;
            notimes++;
        }
    }
    return notimes;
}

void computadadostimes(time *timescampeonato, int notimes, jogo *dadosjogos, int numerojogos)
{
    for (int i = 0; i < numerojogos; i++)
    {

        timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].PontosGanhos = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].GolsMarcados = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].GolsSofridos = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].SaldoDeGols = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].Vitorias = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].Empates = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].Derrotas = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].GolAverage = 0;

        timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].PontosGanhos = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].GolsMarcados = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].GolsSofridos = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].SaldoDeGols = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].Vitorias = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].Empates = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].Derrotas = 0;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].GolAverage = 0.000;
    }
    for (int i = 0; i < numerojogos; i++)
    {

        timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].GolsMarcados += dadosjogos[i].golslocal;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].GolsSofridos += dadosjogos[i].golsvisitante;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].SaldoDeGols = timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].GolsMarcados - timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].GolsSofridos;
        if (dadosjogos[i].golslocal > dadosjogos[i].golsvisitante)
        {
            timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].Vitorias += 1;
        }
        else if (dadosjogos[i].golslocal == dadosjogos[i].golsvisitante)
        {
            timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].Empates += 1;
        }
        else
        {
            timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].Derrotas += 1;
        }

        if (timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].GolsSofridos == 0)
        {
            timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].GolAverage = 0;
        }
        else
        {
            timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].GolAverage = (float)timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].GolsMarcados / timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].GolsSofridos;
        }

        timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].PontosGanhos = (timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].Vitorias * 3) + (timescampeonato[encontratime(timescampeonato, dadosjogos[i].local, notimes)].Empates);

        timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].GolsMarcados += dadosjogos[i].golsvisitante;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].GolsSofridos += dadosjogos[i].golslocal;
        timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].SaldoDeGols = timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].GolsMarcados - timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].GolsSofridos;
        if (dadosjogos[i].golsvisitante > dadosjogos[i].golslocal)
        {
            timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].Vitorias += 1;
        }
        else if (dadosjogos[i].golsvisitante == dadosjogos[i].golslocal)
        {
            timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].Empates += 1;
        }
        else
        {
            timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].Derrotas += 1;
        }

        if (timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].GolsSofridos == 0)
        {
            timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].GolAverage = 0;
        }
        else
        {
            timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].GolAverage = (float)timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].GolsMarcados / timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].GolsSofridos;
        }

        timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].PontosGanhos = (timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].Vitorias * 3) + (timescampeonato[encontratime(timescampeonato, dadosjogos[i].visitante, notimes)].Empates);
    }
}

void imprimeclassificacao(time *timescampeonato, int notimes)
{
    ordenaPontos(timescampeonato, notimes);
    ordenaSaldoGols(timescampeonato, notimes);
    printf("Posicao,Nome,Pontos Ganhos,Vitorias,Empates,Derrotas,Saldo de Gols,Gol Average\n");
    for (int i = 0; i < notimes; i++)
    {
        printf("%i,%s,%i,%i,%i,%i,%i,%2.3f\n", i + 1, timescampeonato[i].nome, timescampeonato[i].PontosGanhos, timescampeonato[i].Vitorias, timescampeonato[i].Empates, timescampeonato[i].Derrotas, timescampeonato[i].SaldoDeGols, timescampeonato[i].GolAverage);
    }
}

void salvaclassificacao(time *timescampeonato, int notimes, char *arquivo)
{
    FILE *f;
    f = fopen("CampeonatoIP.txt", "w");

    for (int i = 0; i < notimes; i++)
    {
        fprintf(f, "%i,%s,%i,%i,%i,%i,%i,%2.3f\n", i + 1, timescampeonato[i].nome, timescampeonato[i].PontosGanhos, timescampeonato[i].Vitorias, timescampeonato[i].Empates, timescampeonato[i].Derrotas, timescampeonato[i].SaldoDeGols, timescampeonato[i].GolAverage);
    }

    fclose(f);
}

int main()
{
    time times[NumeroMaxTimes];
    jogo jogos[NumeroMaxJogos];
    int i, nojogos, golslocal = 0, golsvisitante = 0;
    char local[30], visitante[30];

    printf("Entre os jogos no formato \"time local, time visitante, golslocal, golsvisitante\" (gols local negativo encerra a entrada de dados)\n");
    for (i = 0; i < NumeroMaxJogos; ++i)
    {
        lenometime(local);
        lenometime(visitante);
        scanf("%d,%d", &golslocal, &golsvisitante);
        getchar();

        if (golslocal < 0)
        {
            break;
        }

        if (strcmp(local, visitante) == 0)
        {
            continue;
        }

        strncpy(jogos[i].local, local, 30);
        strncpy(jogos[i].visitante, visitante, 30);

        jogos[i].golslocal = golslocal;
        jogos[i].golsvisitante = golsvisitante;
    }
    nojogos = i;

    int notimes = crialistatimes(times, jogos, nojogos);

    computadadostimes(times, notimes, jogos, nojogos);

    imprimeclassificacao(times, notimes);

    salvaclassificacao(times, notimes, "campeonatoIP.dat");
}