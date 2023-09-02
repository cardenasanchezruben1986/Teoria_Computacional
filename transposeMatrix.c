#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void creaMatriz(float ***m, int ren, int col);
void imprimirMatriz(float ***m, int ren, int col);
void transponer(float ***m, float ***n, int ren, int col);

int main()
{
	int i,j;
	int ren=3,col=5;
	int rMax=100,rMin=-100;
	float **m,**n;
	printf("--- Matriz transpuesta ---\n");
	creaMatriz(&m,ren,col);
	creaMatriz(&n,col,ren);
	for(i=0;i<ren;i++)
	{
		for(j=0;j<col;j++)
			m[i][j]=((float)rand()/RAND_MAX)*(rMax-rMin)+rMin;
	}
	printf("(M)\n");
	imprimirMatriz(&m,ren,col);
	transponer(&m,&n,ren,col);
	printf("(N)\n");
	imprimirMatriz(&n,col,ren);
	return 0;
}

void creaMatriz(float ***m, int ren, int col)
{
	int i,j;
	*m=(float**)malloc(ren*sizeof(float*));
	for(i=0;i<ren;i++)
		(*m)[i]=(float*)malloc((col+1)*sizeof(float));
}

void imprimirMatriz(float ***m, int ren, int col)
{
	int i,j;
	for(i=0;i<ren;i++)
	{
	  for(j=0;j<col;j++)
			printf("%.2f\t",(*m)[i][j]);
		printf("\n");
	}
}

void transponer(float ***m, float ***n, int ren, int col)
{
	int i,j;
	for(i=0;i<ren;i++)
	{
	  for(j=0;j<col;j++)
			(*n)[j][i]=(*m)[i][j];
	}
}
