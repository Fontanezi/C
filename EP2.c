/*********************************************************************/
/**   ACH2001 - Introdução à Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2023                          **/
/**   Turma 02 - Prof. Marcos Lordello Chaim                        **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   João Paulo Fernandes Fontanezi                  14747191      **/
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

time times[NumeroMaxTimes];
jogo jogos[NumeroMaxJogos];
int i, nojogos, golslocal = 0, golsvisitante = 0;
int notimes = 0;
char local[30], visitante[30];

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
  int i, j;
  time holder;

  for (i = 0; i < notimes - 1; i++)
  {
    for (j = 0; j < notimes - i - 1; j++)
    {
      if (timescampeonato[j].PontosGanhos < timescampeonato[j + 1].PontosGanhos ||
          (timescampeonato[j].PontosGanhos == timescampeonato[j + 1].PontosGanhos &&
           timescampeonato[j].SaldoDeGols < timescampeonato[j + 1].SaldoDeGols))
      {

        holder = timescampeonato[j];
        timescampeonato[j] = timescampeonato[j + 1];
        timescampeonato[j + 1] = holder;
      }
    }
  }
}

int encontratime(time *timescampeonato, char *nome)
{
  for (int i = 0; i < notimes; i++)
  {
    if (strcmp(timescampeonato[i].nome, nome) == 0)
    {
      return 0;
    }
  }
  return 1;
}

int findTeam(time *timescampeonato, char *nome, int notimes)
{
  for (int i = 0; i < notimes; i++)
  {
    if (strcmp(timescampeonato[i].nome, nome) == 0)
    {
      return i;
    }
  }
  return 1;
}

void newTeam(char *nome)
{
  strcpy(times[notimes].nome, nome);
  times[notimes].PontosGanhos = 0;
  times[notimes].GolsMarcados = 0;
  times[notimes].GolsSofridos = 0;
  times[notimes].SaldoDeGols = 0;
  times[notimes].Vitorias = 0;
  times[notimes].Empates = 0;
  times[notimes].Derrotas = 0;
  times[notimes].GolAverage = 0;
  notimes++;
}

int crialistatimes(time *timescampeonato, jogo *dadosjogos, int numerojogos)
{
  for (int i = 0; i < numerojogos; i++)
  {
    int verifyDuplicate;
    verifyDuplicate = encontratime(timescampeonato, dadosjogos[i].local);
    if (verifyDuplicate == 1)
    {
      newTeam(dadosjogos[i].local);
    }
    verifyDuplicate = encontratime(timescampeonato, dadosjogos[i].visitante);
    if (verifyDuplicate == 1)
    {
      newTeam(dadosjogos[i].visitante);
    }
  }
  return notimes;
}

void computadadostimes(time *timescampeonato, int notimes, jogo *dadosjogos, int numerojogos)
{
  int local, visitante;

  for (int i = 0; i < numerojogos; i++)
  {
    local = findTeam(timescampeonato, dadosjogos[i].local, notimes);
    visitante = findTeam(timescampeonato, dadosjogos[i].visitante, notimes);

    timescampeonato[local].GolsMarcados += dadosjogos[i].golslocal;
    timescampeonato[visitante].GolsMarcados += dadosjogos[i].golsvisitante;

    timescampeonato[local].GolsSofridos += dadosjogos[i].golsvisitante;
    timescampeonato[visitante].GolsSofridos += dadosjogos[i].golslocal;

    if (dadosjogos[i].golslocal > dadosjogos[i].golsvisitante)
    {
      timescampeonato[local].Vitorias++;
      timescampeonato[local].PontosGanhos += 3;
      timescampeonato[visitante].Derrotas++;
    }
    else if (dadosjogos[i].golsvisitante > dadosjogos[i].golslocal)
    {
      timescampeonato[visitante].Vitorias++;
      timescampeonato[visitante].PontosGanhos += 3;
      timescampeonato[local].Derrotas++;
    }
    else
    {
      timescampeonato[local].Empates++;
      timescampeonato[local].PontosGanhos++;
      timescampeonato[visitante].Empates++;
      timescampeonato[visitante].PontosGanhos++;
    }
  }

  for (int i = 0; i < notimes; i++)
  {
    int resultAverage;
    if (timescampeonato[i].GolsSofridos == 0)
    {
      timescampeonato[i].GolAverage = timescampeonato[i].GolsMarcados;
    }
    else
    {
      timescampeonato[i].GolAverage = timescampeonato[i].GolsMarcados / (float)timescampeonato[i].GolsSofridos;
    }
  }
}

void imprimeclassificacao(time *timescampeonato, int notimes)
{
  printf("\n");
  printf("Posicao,Nome,Pontos Ganhos,Vitorias,Empates,Derrotas,Saldo de Gols,Gol Average\n");
  for (i = 0; i < notimes; ++i)
  {
    printf("%d,%s,%d,%d,%d,%d,%d,%.3f\n", (i + 1), timescampeonato[i].nome, timescampeonato[i].PontosGanhos, timescampeonato[i].Vitorias, timescampeonato[i].Empates, timescampeonato[i].Derrotas, timescampeonato[i].SaldoDeGols, timescampeonato[i].GolAverage);
  }
}

void fileprint(FILE *str)
{
  fprintf(str, "Posicao,Nome,Pontos Ganhos,Vitorias,Empates,Derrotas,Saldo de Gols,Gol Average\n");
  for (i = 0; i < notimes; ++i)
  {
    fprintf(str, "%d,%s,%d,%d,%d,%d,%d,%.3f\n", (i + 1), times[i].nome, times[i].PontosGanhos, times[i].Vitorias, times[i].Empates, times[i].Derrotas, times[i].SaldoDeGols, times[i].GolAverage);
  }
}

void salvaClassificacao(char *arquivo)
{
  FILE *f = fopen(arquivo, "w");
  fileprint(f);
  fclose(f);
}

int main()
{
  printf("Entre os jogos no formato \"time local, time visitante, golslocal, golsvisitante\" (gols local negativo encerra a entrada de dados)\n");
  for (i = 0; i < NumeroMaxJogos; ++i)
  {
    lenometime(local);
    lenometime(visitante);
    scanf("%d,%d", &golslocal, &golsvisitante);
    getchar();

    if (golslocal < 0)
      break;

    if (strcmp(local, visitante) == 0)
      continue;

    strncpy(jogos[i].local, local, 30);
    strncpy(jogos[i].visitante, visitante, 30);

    jogos[i].golslocal = golslocal;
    jogos[i].golsvisitante = golsvisitante;
  }
  nojogos = i;

  int notimes = crialistatimes(times, jogos, nojogos);

  computadadostimes(times, notimes, jogos, nojogos);

  ordenaPontos(times, notimes);

  imprimeclassificacao(times, notimes);

  salvaClassificacao("campeonatoIP.dat");
}