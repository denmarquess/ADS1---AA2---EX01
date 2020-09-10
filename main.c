#include <stdio.h>
#include <stdlib.h>
#define tam 10
#include <locale.h>
int achar(int vetor[],int num, int valor)
{	int j;
	int tem = 0;
	int i = 0, achou;
		for(j=0;j<num;j++)
		{
			if(valor!=vetor[j])//valor diferente de veto na posicao j
			{
				tem ++;//cada vez que for diferente +1
			}
			
		}
		if(tem == num)//quer dizer que nenhum numero igual foi achado
			{
				achou =1;
			}
			else 
				if(tem!=num)//quer dizer que foi achado 1 ou mais vezes
				{
					achou = 0;
				}
return achou;	
}
//FUNCAO QUE RETORNA QUALQUER VETOR SEM NUMEROS REPETIDOS
void imprimesrepeticao(int vet[],int n)
{
    //VAI ESCREVENDO POR CIMA DOS VALORES REPETIDOS
int k, j, i;
for (i = 0; i < n; i++)
{
      for (j = i + 1; j < n;)
        {
         if (vet[j] == vet[i])
            {
                for (k = j; k < n; k++)
                {
                    vet[k] = vet[k + 1];
                }
                n--;
            }
         else
            j++;
      }

}
for(i=0;i<n;i++)
      {
          printf("%d\n",vet[i]);
      }

}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int valor;
    int tamanhointer=0;
	int tamanhodiferenca=0;
    int A[10], B[10], Uniao[20], Inter[10], Dif[10];
    int i, j, k;

//Preencher vetor A
puts("-----Preenchendo vetor A----- \n\n");
for(i=0;i<tam;i++)
{
    printf("Entre com o valor do vetor A na  %dº posicao: \n", i+1);
    scanf("%d", &A[i]);
     fflush(stdin);
    Uniao[i]=A[i];//metade vetor UNIAO
}
//Preencher vetor B
puts("\n\n");
puts("-----Preenchendo vetor B-----\n");
for(i=0;i<tam;i++)
{
    printf("Entre com o valor do vetor B na %dº posicao: \n", i+1);
    scanf("%d", &B[i]);
     fflush(stdin);
    Uniao[i+10]=B[i];//Segunda metade do vetor UNIAO
}
int x=0;
i = 0;
do
{//INTERSECÇAO
	valor = A[i];
	int aux = achar(B,10,valor);
	if(aux==0)
	{
		Inter[x]= A[i];
		x++;
		tamanhointer ++;
	}
i++;	
}while(i<10);
int y=0;
j = 0;
do
{//DIFERENCA
	valor = A[j];
	int auxiliar = achar(B,10,valor);
		if(auxiliar == 1)
		{
			Dif[y] = A[j];
			y++;
			tamanhodiferenca++;
		}
j++;	
}while(j<10);
puts("\n\n");
puts("\t======VETOR UNIÃO======");
imprimesrepeticao(Uniao,20);
puts("\n\n");
puts("\t======VETOR INTERSECÇÃO======");
imprimesrepeticao(Inter,tamanhointer);
puts("\n\n");
puts("\t======VETOR DIFERENÇA======");
imprimesrepeticao(Dif,tamanhodiferenca);
    return 0;
}
