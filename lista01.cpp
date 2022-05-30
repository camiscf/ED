/*
 * @file lista01.cpp
 * @author Camila Caleones de Figueiredo
 * @dre 121080642 
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * INSTRUÇÕES: ./lista01 ordena -n [tamanho] -m [modo]
 * 
 *      modo:     m MERGE Sort
 *                b BUBBLE Sort
 *                q QUICK Sort
 * 
 *      e.g. ./lista01 -n 10 -m q
 */


#include <iostream>
using namespace std;

// ******** ALGORITMO DE ORDENAÇÃO DO MERGE SORT ********
void merge(int *v, int begin, int middle, int end){

    //liberando espaço para array temporarios
    int *temp_left = (int *) malloc((middle-begin)*sizeof(int));

    int *temp_right = (int *) malloc((end-middle)*sizeof(int));

    //passando para temporarios
    for(int count = 0; count < middle-begin; count++){
        temp_left[count] = v[count+begin];
    }
    for(int count = 0; count < end-middle; count++){
        temp_right[count] = v[count+middle];
    }

    //aqui começa o processo de analisar o número no topo de cada array
    int top_left = 0, top_right = 0;

    //vai comparar cada caso e ordenar
    for(int k = begin; k < end; k++){
        
        if (top_left >= middle-begin){
          v[k] = temp_right[top_right];
          top_right++;
        }
        else if (top_right >= end-middle){
          v[k] = temp_left[top_left];
          top_left++;
        }
        else{
          if(temp_left[top_left] < temp_right[top_right]){
            v[k] = temp_left[top_left];
            top_left++;
          }
          else{
            v[k] = temp_right[top_right];
            top_right++;
          }
        }
    }

}

void mergeSort(int *v, int begin, int end){
    
    if(end - begin > 1){
        int middle = (end + begin)/2;
        mergeSort(v, begin, middle);
        mergeSort(v, middle, end);
        merge(v, begin, middle, end);
    }
}

// ******** ALGORITMO DE ORDENAÇÃO DO BUBBLE SORT ********

// foi decidido passar dois parametros para definir o tamanho do vetor
void bubbleSort(int *v, int n){
    int size_v = n;
    // vai analisar por dupla e ir fazendo as trocas
    for (int k = 0; k < size_v; k++){
        for (int i = 0; i < size_v-1; i++){
            if (v[i] > v[i+1]){
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
    }
}   

// ******** ALGORITMO DE ORDENAÇÃO DO QUICK SORT ********

int partition(int *v, int begin, int end){
    int pivot = v[end];
    
    int i = begin-1;
    // por questão de praticidade e menos confusão no código foi implatado a função swap


    for(int j = begin; j<=end-1; j++){
        if(v[j]<=pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    
    swap(v[i+1],v[end]);
    
    return (i+1);
}

    //gerando o pivot aleatorio

int partition_random(int *v, int begin, int end){
    srand(time(NULL));

    int randompivot = begin + rand()%(end-begin);

    swap(v[randompivot], v[end]);
   
    return partition(v, begin, end);
}

void quicksort(int *v, int begin, int end){
    if(begin < end){
        int pivot = partition(v,begin,end);
        quicksort(v,pivot,end-1);
        quicksort(v,pivot+1,end);
    }
}

// ******** FUNÇÃO DE PRINTAR ********


void printarray(int *v, int n)
{
    for (int i = 0; i < n; i++)
        cout<<v[i]<<" ";
}

// ******** MAIN ********

int main(int argc, char** argv){

    if (argv[4] == string("m")){
        
        cout << "****** MERGE SORT ******" <<"\n";

        int n = atoi((argv[2]));
        int v[n];
        
        for(int i=0;i<n;i++){
            v[i]=rand();
        }
        mergeSort(v,0,n);
        printarray(v,n);

	}
    
	else if (argv[4] == string("q")){
        
        cout << "****** QUICK SORT ******" <<"\n";
        
        int n = atoi((argv[2]));
        int v[n];
        
        for(int i=0;i<n;i++){
            v[i]=rand();
        }

        quicksort(v, 0, n-1);
        printarray(v,n);
	}

	else if (argv[4] == string("b")){
        
        cout << "****** BUBBLE SORT ******" <<"\n";
        
        int n = atoi((argv[2]));
        int v[n];
        
        for(int i=0;i<n;i++){
            v[i]=rand();
        }

        bubbleSort(v,n);
        printarray(v,n);
        }


	else{
		cout << "função inexistente" << "\n";
	}


}
