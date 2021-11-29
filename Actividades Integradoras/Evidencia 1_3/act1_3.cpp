/*
Act 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales (Evidencia Competencia)

En este código se aplicarán los conocimientos obtenidos previamente acerca de algoritmos de busqueda
ordenamiento

Diego Rosas A01634154
Alejandro Flores Madriz A01634167
Abraham De Alba Franco A01634133

Creado el 6/09/2021
Ultima edición 7/09/2021
*/

#include <iostream>
//#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>
using namespace std;
//Función para leer el documento bitacora y almacenar las fechas y eventos en vectores separados
void leerBitacora(vector<double> &fechas, vector<string> &eventos){
    ifstream data;
    data.open("bitacora.txt");
    if (data.is_open()){
        string line;
        while(getline(data, line)){
            eventos.push_back(line);
            stringstream ss(line), horaFormato, fechaFormato;
            double fechaInt;
            string mes, dia, hora, fecha;
            ss >> mes >> dia >> hora;
            if(mes == "Jan") mes = "101";
            if(mes == "Feb") mes = "102";
            if(mes == "Mar") mes = "103";
            if(mes == "Apr") mes = "104";
            if(mes == "May") mes = "105";
            if(mes == "Jun") mes = "106";
            if(mes == "Jul") mes = "107";
            if(mes == "Aug") mes = "108";
            if(mes == "Sep") mes = "109";
            if(mes == "Oct") mes = "110";
            if(mes == "Nov") mes = "111";
            if(mes == "Dec") mes = "112";
            if(dia.size()==1){
                dia = "0" + dia;
            }
            horaFormato << hora[0] << hora[1] << hora[3] << hora[4] << hora[6] << hora[7];
            horaFormato >> hora;
            fecha = mes + dia + hora;

            fechaFormato << fecha;
            fechaFormato >> fechaInt;

            fechas.push_back(fechaInt);            
        }
    }
}

// Funcion auxiliar merge para el algoritmo merge sort
void merge(vector<double> &vect, vector<string> &vectHijo, int izq, int mitad, int der){
    int tamIzq = mitad - izq + 1;
    int tamDer = der - mitad;
    vector<double> izquierda;
    vector<string> izquierdaHijo;
    vector<double> derecha;
    vector<string> derechaHijo;
    for(int i = 0; i < tamIzq; i++){
        izquierda.push_back(vect[izq + i]);
        izquierdaHijo.push_back(vectHijo[izq + i]);
    }
    for(int j = 0; j < tamDer; j++){
        derecha.push_back(vect[mitad + j + 1]);
        derechaHijo.push_back(vectHijo[mitad + j + 1]);
    }
    int a = 0;
    int b = 0;
    int c = izq;
    while(a < tamIzq && b < tamDer){
        if(izquierda[a] <= derecha[b]){
            vect[c] = izquierda[a];
            vectHijo[c] = izquierdaHijo[a];
            a++;
        }else{
            vect[c] = derecha[b];
            vectHijo[c] = derechaHijo[b];
            b++;
        }
        c++;
    }
    while(b < tamDer){
        vect[c] = derecha[b];
        vectHijo[c] = derechaHijo[b];
        b++;
        c++;
    }
    while(a < tamIzq){
        vect[c] = izquierda[a];
        vectHijo[c] = izquierdaHijo[a];
        a++;
        c++;
    }
}
/*Función de ordenamiento de menor a mayor basado en merge sort
la complejidad computacional del algoritmo es O(n log(n))*/
void ordenaMerge(vector<double> &vect, vector<string> &vectHijo, int izq, int der){
    int mitad = 0;
    if(izq < der){
        mitad = (izq + der) / 2;
        ordenaMerge(vect, vectHijo, izq, mitad);
        ordenaMerge(vect, vectHijo, mitad + 1, der);
        merge(vect, vectHijo, izq, mitad, der);
    }
}

//Funcion para la busquedda de la fecha ingresada con complejidad de O(n)
int busqSecuencial(vector<double> vect, double val){
    for(int i = 0; i < vect.size(); i++){
        if(val <= vect[i]){
            return i;
        }
    }
    return vect.size()-1;
}
//Funcion para transformar el dato de entrada de final recibido a un formato adecuado para la busqueda
double formatearFecha(string num){
    num = "1" + num;
    int digitos = num.size();
    for (int i = 0; i < 11 - digitos; i++){
        num += "0";
    }
    stringstream temp(num);
    double fechaFormateada;
    temp >> fechaFormateada;
    if(fechaFormateada < 10100000000 || fechaFormateada > 11231235959){
        cout <<"La fecha no es valida" << endl;
        return -1;
    }
    return fechaFormateada;
}
//Funcion para desplegar los eventos entre las fechas seleccionadas complejidad de O(n) 
void desplegarEventos(int inicio, int fin, vector<string> eventos){
    for(int i = inicio; i < fin; i++){
        cout << eventos[i] << endl;
    }
}
/*Funcion para escribir el resultado del ordenamiento de los datos a un documento de texto
Complejidad O(n)
*/
void escribirArchivo(vector<string> eventos){
    ofstream data("bitacoraOrganizada.txt");
    if(data.is_open()){
        //De mas antigua a mas reciente
        /*for(int i = 0; i < eventos.size();i++){
            data << eventos[i] << "\n";
        }*/
        //De mas reciente a mas antigua
        for(int i = eventos.size()-1; i >= 0; i--){
            data << eventos[i] << "\n";
        }
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    }
}

int main(){
    vector<double> fechas;
    vector<string> eventos;

    leerBitacora(fechas, eventos);
    ordenaMerge(fechas, eventos, 0, fechas.size()-1);
    string fechaInicioStr, fechaFinStr;
    cout << "Ingrese la fecha de inicio para la busqueda en formato MMDDHH" << endl;
    cout << "        M = Mes en formato numerico, D = Dia, H = hora en formato de 24H" << endl;
    cout << "        Se debe incluir un 0 previo si es un numero de un digito" << endl;
    cout << "        Es posible omitir la hora" << endl;
    cin >> fechaInicioStr;
    double inicio = 0;
    inicio = formatearFecha(fechaInicioStr);
    if(inicio == -1){
        return 0;
    }
    cout << "Ingrese la fecha de fin para la busqueda en formato MMDD" << endl;
    cout << "        M = Mes en formato numerico, D = Dia, H = hora en formatode 24H" << endl;
    cout << "        Se debe incluir un 0 previo si es un numero de un digito" << endl;
    cout << "        Es posible omitir la hora" << endl;
    cin >> fechaFinStr;
    double final = 0;
    final = formatearFecha(fechaFinStr);
    if(final == -1){
        return 0;
    }
    int indiceInicio = busqSecuencial(fechas, inicio);
    int indiceFinal = busqSecuencial(fechas, final);
    if(indiceInicio > indiceFinal){
        cout << "La fecha final que ingreso es antes de la fecha inicial" << endl;
    }else{
        desplegarEventos(indiceInicio, indiceFinal, eventos);
    }
    escribirArchivo(eventos);
}