#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirVector(int vec[5][5],int n);
void Insercion(int vec[5][5], int n);
void llenarVector(int vec[5][5],int n);
void Seleccion(int vec[5][5],int n);
int existe(int vec[5][5],int n,int num);
void ordernarMatriz (int vec[5][5],int n);

int main()
{
    int vec[5][5];
    int n=5;

    llenarVector(vec,n);
    imprimirVector(vec,n);
    ordernarMatriz(vec,n);
    printf("\n");
    imprimirVector(vec,n);

    return 0;
}


void imprimirVector(int vec[5][5],int n)
{
    int i;
    int j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d \t",vec[i][j]);
        }
        printf("\n");
    }

    return;
}

/*void Insercion(int vec[],int n)
{
    int pasada;
    int j;
    int temp;

    for(pasada=1;pasada<n;pasada++)
    {
        temp=vec[pasada];
        j=pasada-1;
        while(temp>vec[j] && j>=0)
        {
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=temp;
    }
}
*/
void llenarVector(int vec[5][5],int n)
{
    int i;
    int j;
    int num;
    srand(time(NULL));

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            num=rand()%100;
            while(existe(vec,n,num)== 0)
            {
                vec[i][j]=num;
            }

        }
    }

    return;
}

int existe(int vec[5][5],int n,int num)
{
    int i;
    int j;
    int existe=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(num==vec[i][j])
                existe=1;
        }
    }

    return existe;
}

/*void Seleccion(int vec[30][30],int n)
{
    int ordenados;
    int j,posMin;
    int temp;

    for(ordenados=0;ordenados<n-1;ordenados++)
    {
        posMin=ordenados;
        for(j=ordenados;j<n;j++)
        {
            if(vec[j]<vec[posMin])
                posMin=j;
        }

        temp=vec[posMin];
        vec[posMin]=vec[ordenados];
        vec[ordenados]=temp;
    }
}*/

void ordernarMatriz (int vec[5][5],int n)
{
    int i;
    int j;
    int aux;
    int c;
    int f;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(c=0;c<n;c++)
            {
                for(f=0;f<n;f++)
                {
                    if(vec[i][j]<vec[c][f])
                        {
                            aux=vec[i][j];
                            vec[i][j]=vec[c][f];
                            vec[c][f]=aux;
                        }
                }
            }
        }
    }
    return;
}
