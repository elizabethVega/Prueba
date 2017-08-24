#include <stdio.h>
#include <stdlib.h>

int numcomp=0;

/*Divide el arreglo desordenado en n subarreglos con solo 1 elemento*/
void mergeSort (int A[ ] , int inicio , int fin )
   {
           if( inicio < fin ) {
           int mid = (inicio + fin ) / 2 ; /*pivote*/
           mergeSort (A, inicio , mid ) ; /*ordena lado izquierdo*/
           mergeSort (A,mid+1 , fin ) ;   /*ordena lado derecho*/
          merge(A,inicio , mid , fin );     /*une ambas partes*/
   }
}

void merge(int A[ ] , int inicio, int mid, int fin) {
    int p = inicio;
    int q = mid+1;
    int arr[fin-inicio+1] , k=0;
    int x;

    for(x = inicio ;x <= fin ;x++) {
        if(comp(p,mid))
           arr[k++] = A[q++] ;

       else if (comp(q,fin))
           arr[k++] = A[p++];

       else if(comp(A[ q ],A[ p ]))
          arr[k++] = A[p++];

       else
          arr[k++] = A[q++];
     }
      for (p=0 ; p< k ;p ++) {
         A[inicio++] = arr[p] ;
      }
}

int comp(int a,int b){
numcomp++;
return a>b;
}

int main()
{
    int tam;
    scanf("%d",&tam);
    int i;
    int arr[tam];
    /*llenado arreglo con numeros alatorios*/
    for(i=0;i<tam;i++){
        arr[i]=rand();
    }
    mergeSort(arr,0,tam);
    int x;

    for(x=0;x<tam;x++){
    printf("%d ",arr[x]);
    }
    printf("\n**Comparaciones %d",numcomp);
}
