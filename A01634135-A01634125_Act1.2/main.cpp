/*
Programa que resuelve un problema de cambio de monedas implementando Programacion Dinamica.
Autores: Maria Fernanda Elizalde Macias A01634135 - Sofia del Pilar Batiz Martinez A01634125
Fecha: 23 de agosto de 2022
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
Complejidad computacional: O(n)
Funcion que imprime las monedas segun su cantidad, cada una por linea
Recibe un vector con las monedas usadas y la cantidad a regresar
Imprime los valores del vector las veces correspondientes para llegar a la cantidad
*/
void printCoins(vector<int> _monedasUsadas, int _cantidad){
    int moneda = _cantidad;
    while (moneda > 0){
        int newMoneda = _monedasUsadas[moneda];
        cout << newMoneda << endl;
        moneda -= newMoneda;
    }
}

/*
Complejidad computacional: O(n*m)
Funcion que implementa la Programacion Dinamica para obtener las monedas minimas necesarias para el cambio
Recibe un vector con el minimo de monedas por denominacion, un vector indicando las monedas utilizadas, el vector de las denominaciones y la cantidad a regresar
Regresa un vector<int> con las monedas usadas para dar el cambio 
*/
vector<int> obtieneMonedas(vector<int> _minimoMonedas, vector<int> _monedasUsadas, vector<int> _denominaciones, int _cantidad){
    for(int i = 0; i < _cantidad + 1; i++){
        int count = i; //cantidad de monedas
        int moneda = 1; //tipo de moneda

        for(int j = 0; j < _denominaciones.size(); j++){
            int k = _denominaciones[j];
            if(k <= i && _minimoMonedas[i - k] + 1 < count){
                count = _minimoMonedas[i - k] + 1;
                moneda = k;
            }
        }

        _minimoMonedas[i] = count; //minimo de monedas necesarias para el cambio
        _monedasUsadas[i] = moneda; //monedas usadas para el cambio
    }
    return _monedasUsadas;
}

int main(){
    //Lectura de archivo
    string fileName = "prueba.txt";
    string line;
    ifstream myFile(fileName);

    getline(myFile, line);
    int n = stoi(line); //Guarda la primera linea en n
    vector<int> denominaciones(n + 2);
    int count = 0;

    while(!myFile.eof()){ //Guarda el resto de las lineas
        getline(myFile, line);
        denominaciones[count] = stoi(line);
        count++;
    }

    //Guarda los ultimos dos valores
    int p = denominaciones[n];
    int q = denominaciones[n + 1];
    int cantidad = q - p; //cantidad a regresar
    //Los elimina del vector<int>
    denominaciones.pop_back();
    denominaciones.pop_back();

    vector<int> cantidadMonedas(cantidad + 1, 0); //cantidad de monedas por cada denominacion
    vector<int> minimoMonedas(cantidad + 1, 0); //minimo de monedas para el cambio
    vector<int> monedasUsadas(cantidad + 1, 0); //monedas usadas para el cambio

    cout << "Cambio a regresar: " << cantidad << endl;
    cout << "Monedas: " << endl;

    vector<int> monedas = obtieneMonedas(minimoMonedas, monedasUsadas, denominaciones, cantidad);
    printCoins(monedas, cantidad);

    return 0;
}