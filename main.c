//Projeto: Samsung UFAM Projeto para Educação e Pesquisa - SUPER
//Projeto Super – ICT Jr.
//Tipo de Projeto: Ensino e Pesquisa
//Tema do Trabalho de ICT-Jr: Introdução a Programação
//Orientador: João Marcos Cavalcanti
//Discente: Sebastião Bicharra Neto

/*Problema: Desenvolva um programa que implementa um vetor com 100.000 (cem mil) elementos do tipo
inteiro, com valores aleatórios desordenados. Ordene o vetor usando as cinco técnicas listadas:
1 - Bolha
2 - Inserção Direta
3 - Seleção Direta
4 - Merge Sort
5 - Quick Sort

Execute cada algoritmo de ordenação 30 vezes, gerando novos valores para o vetor a cada uma
das 30 rodadas. Em cada rodada, use o mesmo vetor (com os mesmos valores) para cada uma das
cinco técnicas de ordenação (atenção para não usar o vetor ordenado pela execução anterior).
Calcule e mostre o tempo para cada execução de cada algoritmo de ordenação e a média entre as
30 execuções para cada algoritmo.

*/





#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

void mergeSort2();
void merge();
#define tamanhoVetor 100

/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/

//copiar elementos de um vetor para outro

void copiaVetor(int destino[],int origem[], int n){
    int i;
    for(i=0;i<n+1;i++){
        destino[i]=origem[i];
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/

//verifica se o vetor esta ordenado

int VerificarVetorOrdenado(int vet[], int tamanhoVet){
    int i;
    for(i=0;i<=tamanhoVet;i++){
        if(vet[i]>vet[i+1]){
            return 0; //
        }
    }
    return 1; //
}

/*--------------------------------------------------------------------------------------------------------------------*/

//verifica se o vetor esta ordenado

int verifica2(int v[],int tamV){
    int x,y,aux;
    for(x=0;x<=tamV;x++){
        for(y=x;y<=tamV;y++){
            aux=v[x];
            v[x]=v[y];
            v[y]=aux;
        }
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/

//MergeSort2

void mergeSort2(int v[], int primeiro, int ultimo){
    int x;

    if(primeiro<ultimo){
        x = (primeiro+ultimo)/2;
        mergeSort2(v,primeiro,x);
        mergeSort2(v,x+1,ultimo);
        merge(v,primeiro,x,ultimo);

    }
}

void merge(int v[],int primeiro, int x, int ultimo){
    int b[tamanhoVetor];
    int i,j,k;
    i=primeiro;
    j=x+1;
    k=primeiro;
    while(i<=x && j<= ultimo){
        if(v[i]<=v[j])
            b[k++]=v[i++];
        else
            b[k++]=v[j++];
    }
    if(i>x){
        while(j<=ultimo)
            b[k++]=v[j++];
    }
    else{
        while(i<=x)
            b[k++]=v[i++];
    }
    for(i=primeiro;i<=ultimo;i++)
        v[i]=b[i];
}
/*--------------------------------------------------------------------------------------------------------------------*/

//QuickSort

int particionar(int vetor[],int esquerda, int direita){
    int aux; //troca de posicoes
    int i;

    int cont = esquerda;

    for(i=esquerda+1;i<=direita;i++){
        if(vetor[i]<vetor[esquerda]){
            cont++; //manipula a posicao a ser trocada
            aux=vetor[i];
            vetor[i]=vetor[cont];//manipula a posicao a ser trocada
            vetor[cont]=aux;//manipula a posicao a ser trocada

        }
    }
    aux=vetor[esquerda];
    vetor[esquerda]=vetor[cont];
    vetor[cont]=aux;

    return cont;
}

void quick(int vetor[],int esquerda, int direita){
    int posicao,i;

    if(esquerda<direita){
        posicao=particionar(vetor,esquerda,direita);
        quick(vetor,esquerda,posicao-1);
        quick(vetor,posicao+1,direita);
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/

//BubbleSort

void bubbleSort(int *a)
{
    int i, j, tmp;

    for(i = 0; i <= tamanhoVetor; i++)
    {
        for(j = i+1; j <= tamanhoVetor; j++)
        {
            if(a[j] < a[i])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}


/*--------------------------------------------------------------------------------------------------------------------*/

//insertion_Sort

int insertion_Sort(int v[]){
    int i,j,aux;
    for(i=1;i <= tamanhoVetor;i++)
    {
        aux = v[i];
        j = i-1;
        while((j>=0) && (aux < v[j])){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] =aux;
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/

//SelectionSort

void selection_Sort (int *V, int n) {
    int troca, menor;

    for (int i = 0; i < n - 1; i++) {
        menor = i;
        for (int j = i + 1; j < n; j++) {
            if (V[j] < V[menor]) {
                menor = j;
            }
        }

        if (i != menor) {
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/

int main() {
     int vetA[tamanhoVetor]; //vetor sera ordenado por QuickSort
     int vetB[tamanhoVetor];//vetor sera ordenado por MergeSort
     int vetC[tamanhoVetor];//vetor sera ordenado por BubbleSort
     int vetD[tamanhoVetor];//vetor sera ordenado por InsertionSort
     int vetE[tamanhoVetor];//vetor sera ordenado por SelectionSort
     int i;


     //gera valores aletorios para o vetor
    for(i=0;i<=tamanhoVetor;i++){
        vetA[i]= rand() % tamanhoVetor;
    }

    /*for(i=0;i<=tamanhoVetor;i++){
        printf("Elementos do Vetor A antes da ordenacao - [%d] %d \n",i, vetA[i]);
    }*/

    printf("\n");


    //copiando elementos do vetor A para o vetor B
    copiaVetor(vetB,vetA,tamanhoVetor);
    //copiando elementos do vetor B para o vetor C
    copiaVetor(vetC,vetB,tamanhoVetor);
    //copiando elementos do vetor C para o vetor D
    copiaVetor(vetD,vetC,tamanhoVetor);
    //copiando elementos do vetor D para o vetor E
    copiaVetor(vetE,vetD,tamanhoVetor);


    //chamando ordenacao do vetor A e calculando seu tempo de execução
    struct timeval  tv1, tv2;
    gettimeofday(&tv1, NULL);
    quick(vetA,0,tamanhoVetor);
    gettimeofday(&tv2, NULL);

    printf ("Total time Ordenacao Quick_Sort = %f seconds\n",
            (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
            (double) (tv2.tv_sec - tv1.tv_sec));

    printf("\n");

    /*for(i=0;i<=tamanhoVetor;i++){
        printf("Elementos do vetor A apos Ordenacao [%d] %d \n",i, vetA[i]);
    }*/

    printf("\n");

    if(VerificarVetorOrdenado(vetA,tamanhoVetor)){
        printf("Ordenacao QuickSort Funcionando  - Vetor Ordenado \n");
    }

    printf("\n");

    /*for(i=0;i<=tamanhoVetor;i++){
        printf("Elementos do Vetor B antes da Ordenacao - [%d] %d \n",i, vetB[i]);
    }*/

    printf("\n");

    //chamando ordenacao do vetor B e calculando seu tempo de execução
    struct timeval  tv01, tv02;
    gettimeofday(&tv01, NULL);
    mergeSort2(vetB,0,tamanhoVetor);
    gettimeofday(&tv02, NULL);

    printf ("Total time ordenacao Merge_Sort = %f seconds\n",
            (double) (tv02.tv_usec - tv01.tv_usec) / 1000000 +
            (double) (tv02.tv_sec - tv01.tv_sec));

    printf("\n");

    /*for(i=0;i<tamanhoVetor+1;i++){
        printf("Elementos do vetor B apos Ordenacao [%d] %d \n",i, vetB[i]);
    }*/

    printf("\n");

    if(verifica2(vetB,tamanhoVetor)){
        printf("Ordenacao MergeSort Funcionando - Vetor Ordenado\n");
    }

    printf("\n");

    /*for(i=0;i<=tamanhoVetor;i++){
        printf("Elementos do Vetor C antes da Ordenacao - [%d] %d \n",i, vetB[i]);
    }*/

    printf("\n");

    //chamando ordenacao do vetor C e calculando seu tempo de execução
    struct timeval  tv001, tv002;
    gettimeofday(&tv001, NULL);
    bubbleSort(vetC);
    gettimeofday(&tv002, NULL);

    printf ("Total time ordenacao Bubble_Sort = %f seconds\n",
            (double) (tv002.tv_usec - tv001.tv_usec) / 1000000 +
            (double) (tv002.tv_sec - tv001.tv_sec));

    printf("\n");

    /*for(i=0;i<tamanhoVetor+1;i++){
        printf("Elementos do vetor C apos Ordenacao [%d] %d \n",i, vetC[i]);
    }*/

    printf("\n");

    if(verifica2(vetC,tamanhoVetor)){
        printf("Ordenacao Bubble Sort Funcionando - Vetor Ordenado\n");
    }


    printf("\n");

    /*for(i=0;i<=tamanhoVetor;i++){
        printf("Elementos do Vetor D antes da Ordenacao - [%d] %d \n",i, vetD[i]);
    }*/

    printf("\n");

    //chamando ordenacao do vetor D e calculando seu tempo de execução
    struct timeval  tv0001, tv0002;
    gettimeofday(&tv0001, NULL);
    insertion_Sort(vetD);
    gettimeofday(&tv0002, NULL);

    printf ("Total time ordenacao Insertion_Sort = %f seconds\n",
            (double) (tv0002.tv_usec - tv0001.tv_usec) / 1000000 +
            (double) (tv0002.tv_sec - tv0001.tv_sec));

    printf("\n");

    /*for(i=0;i<tamanhoVetor+1;i++){
        printf("Elementos do vetor D apos Ordenacao [%d] %d \n",i, vetD[i]);
    }*/

    printf("\n");

    if(verifica2(vetD,tamanhoVetor)){
        printf("Ordenacao Insertion Sort Funcionando - Vetor Ordenado\n");
    }

    printf("\n");

    /*for(i=0;i<=tamanhoVetor;i++){
        printf("Elementos do Vetor E antes da Ordenacao - [%d] %d \n",i, vetE[i]);
    }*/

    printf("\n");

    //chamando ordenacao do vetor E e calculando seu tempo de execução
    struct timeval  tv00001, tv00002;
    gettimeofday(&tv00001, NULL);
    selection_Sort(vetE,tamanhoVetor);
    gettimeofday(&tv00002, NULL);

    printf ("Total time ordenacao Selection_Sort = %f seconds\n",
            (double) (tv00002.tv_usec - tv00001.tv_usec) / 1000000 +
            (double) (tv00002.tv_sec - tv00001.tv_sec));

    printf("\n");

    /*for(i=0;i<=tamanhoVetor;i++){
        printf("Elementos do Vetor E depois da Ordenacao - [%d] %d \n",i, vetE[i]);
    }*/

}
