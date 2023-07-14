/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
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
#define NumeroMaxJogos NumeroMaxTimes * NumeroMaxRodadas

typedef struct auxtime {
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

typedef struct auxjogo {
  char local[30];
  char visitante[30];
  int golslocal;
  int golsvisitante;
} jogo;

void lenometime(char * s) {
  int i;
  s[0] = '\0';
  char c;
  c = getchar();
  for(i = 0; c != ',' && i < 30;++i)
    {
      s[i] = c;
      c = getchar();
    }
  s[i] = '\0';
}

// Ordena por Pontos

void ordenaPontos(time * timescampeonato, int notimes)
{
  // Adicione seu código para ordenar em ordem decrescente de pontos ganhos
}

// Ordena por saldo de gols

void ordenaSaldoGols(time * timescampeonato, int notimes)
{
  // Adicione seu código para ordenar em ordem decrescente de saldo de gols
}

// Encontra se o time já está no arranjo de times do campeonato

int encontratime(time *timescampeonato, char * nome, int notimes) {
  // Retorna a posição do arranjo times de campeonato
  // Adicione seu código

  return -1; // retorna -1 se o time com o nome "nome" não existe
}

// Cria a lista de times do campeonato a partir dos nojogos

int crialistatimes(time * timescampeonato, jogo * dadosjogos, int numerojogos) {
  // Preenche o arranjo timescampeonato com os times
  // Adicione seu código

  return 0; // retorna o número de times. O zero é só para compilar
}

// Computa dados times

void computadadostimes(time * timescampeonato,int notimes,jogo * dadosjogos,int numerojogos) {
// Preenche os campos dos elementos do arranjo timescampeonato: Vitorias,
// GolsSofridos, GolsMarcados, Golsaverage, SaldoDeGols, PontosGanhos.
// Adicione seu código

 }

// Imprime classificação

void imprimeclassificacao(time * timescampeonato,int notimes){
 // Adicione seu código

}

// Salva os dados da classificação dos tipos em arquivo no disco

void salvaclassificacao(time * timescampeonato,int notimes, char * arquivo){
// Adicione seu código

}

int main() {
  time times[NumeroMaxTimes];
  jogo jogos[NumeroMaxJogos];
  int i, nojogos, golslocal = 0, golsvisitante = 0;
  char local[30],visitante[30];

  printf("Entre os jogos no formato \"time local, time visitante, golslocal, golsvisitante\" (gols local negativo encerra a entrada de dados)\n");
  for(i = 0; i < NumeroMaxJogos; ++i) {
    lenometime(local);
    lenometime(visitante);
    scanf("%d,%d",&golslocal,&golsvisitante);
    getchar(); 

    if (golslocal < 0)
      break; 

    if(strcmp(local,visitante) == 0)
      continue; 

    strncpy(jogos[i].local,local,30);
    strncpy(jogos[i].visitante,visitante,30);

    jogos[i].golslocal = golslocal;
    jogos[i].golsvisitante = golsvisitante;
  }
  nojogos = i;

  int notimes = crialistatimes(times,jogos,nojogos);

  computadadostimes(times,notimes,jogos,nojogos);

  imprimeclassificacao(times,notimes);
  
  salvaclassificacao(times,notimes,"campeonatoIP.dat");

}