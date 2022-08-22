/*
Programa que resuelve un problema de cambio de monedas implementando Programacion Dinamica.
Autores: Maria Fernanda Elizalde Macias A01634135 - Sofia del Pilar Batiz Martinez A01634125
Fecha: 21 de agosto de 2022
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*

*/
int dynamic(vector<int> coins, int num, int n){
    vector<int> vec(num + 1, num + 1);
    vec[0] = 0;
    
    for(int i = 1; i < vec.size(); i++){
        for(int j = 0; j < n; j++){
            if (coins[j] <= i){
                vec[i] = min(vec[i], vec[i - coins[j]] + 1);
            }
        }
    }

    if (vec[num] == (num + 1)){
        return -1;
    }
    else{
        return vec[num];
    }
    
}       



int main(){
    /*
    string fileName = argv[1];
    string line;
    ifstream myFile(fileName);

    getline(myFile, line);
    int n = stoi(line); //Guarda la primera linea en la variable n
    vector<int> myVector(n);

    int count = 0;
    while(!myFile.eof() && count == n - 1){ //Lee el resto de las lineas
        getline(myFile, line);
        myVector[count] = stod(line);
        count++;
    }

    getline(myFile, line);
    int p = stoi(line);
    getline(myFile, line);
    int q = stoi(line);
    */
    int n, q, p, cambio;
    n = 4;
    q = 100;
    p = 93;
    cambio = q - p;
    vector<int> myVector = {10, 5, 2, 1};

    //funcion
    cout << dynamic(myVector, cambio, n);
    
    return 0;
}


