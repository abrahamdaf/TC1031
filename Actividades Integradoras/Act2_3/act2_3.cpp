/*
Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)


Diego Rosas A01634154
Alejandro Flores Madriz A01634167
Abraham De Alba Franco A01634133

Creado el 12/10/2021
Ultima edición 18/10/2021
*/

#include <iostream>
//#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include "Eventos.h"
using namespace std;
//Función para leer el documento bitacora y almacenar las fechas y eventos en vectores separados
void leerBitacora(vector<Eventos> &eventos){
    ifstream data;
    data.open("bitacora.txt");
    if (data.is_open()){
        string line;
        while(getline(data, line)){
            stringstream ss(line), horaFormato, fechaFormato;
            double fechaInt;
            string mes, mesNuevo, dia, hora, horaNueva, fecha, ip, descripcion;
            ss >> mes >> dia >> hora >> ip;
            if(mes == "Jan") mesNuevo = "101";
            if(mes == "Feb") mesNuevo = "102";
            if(mes == "Mar") mesNuevo = "103";
            if(mes == "Apr") mesNuevo = "104";
            if(mes == "May") mesNuevo = "105";
            if(mes == "Jun") mesNuevo = "106";
            if(mes == "Jul") mesNuevo = "107";
            if(mes == "Aug") mesNuevo = "108";
            if(mes == "Sep") mesNuevo = "109";
            if(mes == "Oct") mesNuevo = "110";
            if(mes == "Nov") mesNuevo = "111";
            if(mes == "Dec") mesNuevo = "112";
            if(dia.size()==1){
                dia = "0" + dia;
            }
            horaFormato << hora[0] << hora[1] << hora[3] << hora[4] << hora[6] << hora[7];
            horaFormato >> horaNueva;
            fecha = mesNuevo + dia + horaNueva;

            fechaFormato << fecha;
            fechaFormato >> fechaInt;
            getline(ss, descripcion);
            descripcion.erase(descripcion.begin());
            Eventos temp;
            temp.setFechaFormato(fechaInt);
            temp.setFecha(mes + " " + dia + " " + hora);
            temp.setIp(ip);
            temp.setDescripcion(descripcion);

            eventos.push_back(temp);         
        }
    }
}

// Funcion auxiliar merge para el algoritmo merge sort O(n)
void merge(vector<Eventos> &vect, int izq, int mitad, int der){
    int tamIzq = mitad - izq + 1;
    int tamDer = der - mitad;
    vector<Eventos> izquierda;
    vector<Eventos> derecha;
    for(int i = 0; i < tamIzq; i++){
        izquierda.push_back(vect[izq + i]);
    }
    for(int j = 0; j < tamDer; j++){
        derecha.push_back(vect[mitad + j + 1]);
    }
    int a = 0;
    int b = 0;
    int c = izq;
    while(a < tamIzq && b < tamDer){
        if(izquierda[a].getFechaFormato() <= derecha[b].getFechaFormato()){
            vect[c] = izquierda[a];
            a++;
        }else{
            vect[c] = derecha[b];
            b++;
        }
        c++;
    }
    while(b < tamDer){
        vect[c] = derecha[b];
        b++;
        c++;
    }
    while(a < tamIzq){
        vect[c] = izquierda[a];
        a++;
        c++;
    }
}
/*Función de ordenamiento de menor a mayor basado en merge sort
la complejidad computacional del algoritmo es O(n log(n))*/
void ordenaMerge(vector<Eventos> &vect, int izq, int der){
    int mitad = 0;
    if(izq < der){
        mitad = (izq + der) / 2;
        ordenaMerge(vect, izq, mitad);
        ordenaMerge(vect, mitad + 1, der);
        merge(vect, izq, mitad, der);
    }
}

// Funcion auxiliar merge para el algoritmo merge sort para IPs O(n)
void mergeIp(vector<Eventos> &vect, int izq, int mitad, int der){
    int tamIzq = mitad - izq + 1;
    int tamDer = der - mitad;
    vector<Eventos> izquierda;
    vector<Eventos> derecha;
    for(int i = 0; i < tamIzq; i++){
        izquierda.push_back(vect[izq + i]);
    }
    for(int j = 0; j < tamDer; j++){
        derecha.push_back(vect[mitad + j + 1]);
    }
    int a = 0;
    int b = 0;
    int c = izq;
    while(a < tamIzq && b < tamDer){
        if(izquierda[a].getIpNum() <= derecha[b].getIpNum()){
            vect[c] = izquierda[a];
            a++;
        }else{
            vect[c] = derecha[b];
            b++;
        }
        c++;
    }
    while(b < tamDer){
        vect[c] = derecha[b];
        b++;
        c++;
    }
    while(a < tamIzq){
        vect[c] = izquierda[a];
        a++;
        c++;
    }
}
/*Función de ordenamiento de menor a mayor basado en merge sort
la complejidad computacional del algoritmo es O(n log(n))*/
void ordenaMergeIp(vector<Eventos> &vect, int izq, int der){
    int mitad = 0;
    if(izq < der){
        mitad = (izq + der) / 2;
        ordenaMergeIp(vect, izq, mitad);
        ordenaMergeIp(vect, mitad + 1, der);
        mergeIp(vect, izq, mitad, der);
    }
}

void mergeHijo(vector<int> &vect, vector<double> &vectHijo, vector<string> &vectHijo2, int izq, int mitad, int der){
    int tamIzq = mitad - izq + 1;
    int tamDer = der - mitad;
    vector<int> izquierda;
    vector<int> derecha;
    vector<double> izquierdaHijo;
    vector<double> derechaHijo;
    vector<string> izquierdaHijo2;
    vector<string> derechaHijo2;
    for(int i = 0; i < tamIzq; i++){
        izquierda.push_back(vect[izq + i]);
        izquierdaHijo.push_back(vectHijo[izq + i]);
        izquierdaHijo2.push_back(vectHijo2[izq + i]);
    }
    for(int j = 0; j < tamDer; j++){
        derecha.push_back(vect[mitad + j + 1]);
        derechaHijo.push_back(vectHijo[mitad + j + 1]);
        derechaHijo2.push_back(vectHijo2[mitad + j + 1]);
    }
    int a = 0;
    int b = 0;
    int c = izq;
    while(a < tamIzq && b < tamDer){
        if(izquierda[a] >= derecha[b]){
            vect[c] = izquierda[a];
            vectHijo[c] = izquierdaHijo[a];
            vectHijo2[c] = izquierdaHijo2[a];
            a++;
        }else{
            vect[c] = derecha[b];
            vectHijo[c] = derechaHijo[b];
            vectHijo2[c] = derechaHijo2[b];
            b++;
        }
        c++;
    }
    while(b < tamDer){
        vect[c] = derecha[b];
        vectHijo[c] = derechaHijo[b];
        vectHijo2[c] = derechaHijo2[b];
        b++;
        c++;
    }
    while(a < tamIzq){
        vect[c] = izquierda[a];
        vectHijo[c] = izquierdaHijo[a];
        vectHijo2[c] = izquierdaHijo2[a];
        a++;
        c++;
    }
}
/*Función de ordenamiento de menor a mayor basado en merge sort
la complejidad computacional del algoritmo es O(n log(n))*/
void ordenaMergeHijos(vector<int> &vect, vector<double> &vectHijo, vector<string> &vectHijo2, int izq, int der){
    int mitad = 0;
    if(izq < der){
        mitad = (izq + der) / 2;
        ordenaMergeHijos(vect, vectHijo, vectHijo2, izq, mitad);
        ordenaMergeHijos(vect, vectHijo, vectHijo2, mitad + 1, der);
        mergeHijo(vect, vectHijo, vectHijo2, izq, mitad, der);
    }
}

//Funcion para la busqueda de la fecha ingresada con complejidad de O(n)
int busqBinaria(vector<Eventos> vect, double val){
    int izq = 0;
    int der = vect.size()-1;
    int mitad = (der + izq)/2;
    
    while(izq <= der){
        mitad = (der + izq)/2;
        if(val == vect[mitad].getFechaFormato()){
            return mitad;
        }else if(val < vect[mitad].getFechaFormato()){
            der = mitad - 1;
        }else{
            izq = mitad + 1;
        }
    }
    return izq;
}

//Funcion para transformar el dato de entrada de final recibido a un formato adecuado para la busqueda O(1)
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
//Funcion para desplegar los eventos entre las fechas seleccionadas complejidad de O(nlog(n)) 
void desplegarEventos(int inicio, int fin, vector<Eventos> eventos){
    vector<Eventos> eventosBusq;
    vector<double> ips;
    vector<string> ipsOriginales;
    vector<int> accesos;
    for (int i = inicio; i < fin; i++){
        eventosBusq.push_back(eventos[i]);
    }
    ordenaMergeIp(eventosBusq, 0, eventosBusq.size()-1);
    ips.push_back(eventosBusq[0].getIpNum());
    ipsOriginales.push_back(eventosBusq[0].getIp());
    accesos.push_back(1);

    for (int i = 1; i < eventosBusq.size(); i++){
        if(eventosBusq[i].getIpNum() == eventosBusq[i-1].getIpNum()){
            accesos.back()++;

        }else{
            ips.push_back(eventosBusq[i].getIpNum());
            ipsOriginales.push_back(eventosBusq[i].getIp());
            accesos.push_back(1);

        }
    }
    ofstream data("ipsPorAcceso.txt");
    if(data.is_open()){
        for(int i = 0; i < ips.size();i++){
            data << ipsOriginales[i] << " " << accesos[i] << "\n";
        }
    }
    
    ordenaMergeHijos(accesos, ips, ipsOriginales, 0, accesos.size()-1);
    
    for(int i = 0; i < accesos.size(); i++){
        double actual = ips[i];
        cout << accesos[i] << " Registros de la direccion ip: " << ipsOriginales[i] << endl;
    }
    
}
/*Funcion para escribir el resultado del ordenamiento de los datos a un documento de texto
Complejidad O(n)
*/
void escribirArchivo(vector<Eventos> eventos){
    ofstream data("bitacoraOrganizada.txt");
    if(data.is_open()){
        //De mas antigua a mas reciente
        /*for(int i = 0; i < eventos.size();i++){
            data << eventos[i] << "\n";
        }*/
        //De mas reciente a mas antigua
        for(int i = eventos.size()-1; i >= 0; i--){
            data << eventos[i].getFecha() << " " << eventos[i].getIp() << " " << eventos[i].getDescripcion() << "\n";
        }
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    }
}

int main(){
    vector<Eventos> eventos;

    leerBitacora(eventos);
    ordenaMerge(eventos, 0, eventos.size()-1);
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
    int indiceInicio = busqBinaria(eventos, inicio);
    int indiceFinal = busqBinaria(eventos, final);
    if(indiceInicio > indiceFinal){
        cout << "La fecha final que ingreso es antes de la fecha inicial" << endl;
    }else{
        desplegarEventos(indiceInicio, indiceFinal, eventos);
    }
    escribirArchivo(eventos);
   eventos[0].getIpNum();
}