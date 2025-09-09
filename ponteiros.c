#include <stdio.h>
#include <stdlib.h>

int main()
{
  //variaveis
  int *V; // representa o vetor dinamico
  int n; // tamanho do vetor
  
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
}