/*
Programa que implementa el algoritmo MergeSort utilizando la tecnica de "Divide y venceras".
Autores: Maria Fernanda Elizalde Macias A01634135 - Sofia del Pilar Batiz Martinez A01634125
Fecha: 11 de agosto de 2022
*/

#include <iostream>
using namespace std;

/*
Funcion que ordena los valores de un arreglo de mayor a menor
Recibe un arreglo de valores double, y los indices del primer valor, el ultimo valor y el valor medio
Crea un nuevo arreglo con los valores ordenados y se copia al arreglo original
*/
void merge(double arr[], int left, int middle, int right){
    double newArr[right + 1];
    int i = left, j = middle + 1, k = left;
    while(i <= middle && j <= right){
        if(arr[i] > arr[j]){
            newArr[k++] = arr[i++];
        }
        else{
            newArr[k++] = arr[j++];
        }
    }
    while(i <= middle){
        newArr[k++] = arr[i++];
    }
    while(j <= right){
        newArr[k++] = arr[j++];
    }
    for(int j = left; j <= right; j ++){
        arr[j] = newArr[j];
    }
}

/*
Funcion que implementa el algoritmo MergeSort con la tecnica de "Divide y Venceras"
Recibe un arreglo de valores double, y los indices del primer valor y el ultimo valor
Implementa recursivamente el algoritmo (diviendo los arreglos hasta llegar al caso base) y combina el arreglo ordenado
*/
void mergeSort(double arr[], int left, int right){
    if(left < right){
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main(){
    
    return 0;
}
