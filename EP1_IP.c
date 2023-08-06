#include <stdio.h>
#include <stdlib.h>
int mesDias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int diasRestantes = 365;

void contador(int d, int m, int a)
{
	int i;
	for (i = 1; i <= diasRestantes; i++)
	{
		d++;
		if (d > mesDias[m - 1])
		{
			d = 1;
			m++;
		}
		if (i % 60 == 0)
		{
			printf("%d/%d/%d\n", d, m, a);
		}
	}
}

int verificaDataValida(int d, int m, int a) // Se houver algum dado inválido, retorna 1;
{
	if (a < 0 || m < 1 || m > 12)
	{
		return 0;
	}

	if (a % 4 == 0) // Se o ano for bissexto
	{
		mesDias[1] = 29; // Muda os dias de Fevereiro na array pra 29
	}

	if (d > mesDias[m - 1] || d < 1) // Verifica se o dia for maior que os dias do mês na array ou se é negativo
	{
		return 0;
	}
	// verifica se o ano é bissexto
	if (a % 4 == 0)
	{
		mesDias[1] = 29;

		// calcula quantos dias restam até o fim do ano
		diasRestantes += 1;
	}

	for (int i = 0; i < m - 1; i++)
	{
		diasRestantes -= mesDias[i];
	}
	diasRestantes -= d;

	return 1; // Se tudo der certo, a função retorna verdadeiro
}

int main()
{
	int dia, mes, ano;

	printf("Entre com a data de inicio do ano letivo:\n");
	printf("Entre com o dia: ");
	scanf("%d", &dia);
	printf("Entre com o mes: ");
	scanf("%d", &mes);
	printf("Entre com o ano: ");
	scanf("%d", &ano);

	if (!verificaDataValida(dia, mes, ano))
	{
		printf("Dados incorretos\n");
		exit(1); // Esta função aborta a execução do programa.
	}

	printf("Data de inicio do ano letivo: %d/%d/%d\n", dia, mes, ano);

	printf("Proximos dias de encontro de todos os clubes:\n");

	// Mostra os próximos encontros até Dezembro
	contador(dia, mes, ano);
}