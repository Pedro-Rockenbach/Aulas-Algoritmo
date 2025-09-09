#include <stdio.h>
#include <stdlib.h>

int main()
{
	//variaveis
	int *V; // representa o vetor dinamico
	int n; // tamanho do vetor ou colunas da matriz dinamica

	int **M; // matriz dinamica
	int m; // numero de linhas da matriz dinamica

	// ler o tamanho desejado
	printf("Qual o tamanho do vetor? >> ");
	scanf("%d", &n);

	// tentar alocar o vetor
	V = (int*)malloc(n*sizeof(int));
	if (V == NULL)
	{
		printf("Erro 1: memoria insuficiente.\n");
		return 1;
	}
	// manipula o vetor
	for (int i = 0; i < n; i++) {
		V[i] = i + 2;
	}
	// escreve o vetor
	for (int i = 0; i < n; i++) {
		printf("%d ", V[i]);
	}
	free(V); //desaloca o vetor

	printf("Quantas linhas ? >>");
	scanf("%d", &m);

	printf("Quantas colunas ? >>");
	scanf("%d", &m);

	// aloca cada linha da matriz dinamica
	M = (int**)malloc(m*sizeof(int*));
	if (M == NULL)
	{
		printf("Erro 2: memoria insuficiente.\n");
		return 2;
	}

	//aloca cada linha
	for (int i = 0; i < m; i++)
	{
		M[i] = (int*)malloc(n*sizeof(int));
		if (M[i] == NULL)
		{
			printf("Erro 3: memoria insuficiente.\n");
			return 3;
		}
	}
	//criar matriz
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			M[i][j] = i + j;
		}
	}
	//escrever matriz
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("\t%d", M[i][j]);
		}
	}
	//
	for (int i = 0; i < m; i++)
	{
	  free(M[i]);
	}
	free(M);
	return 0;
}