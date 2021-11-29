#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
    public:
        vector<Node*> salidas;
        int key;

        Node(int _key){
            key =  _key;
        }

        Node(){

        }

        void addSalida(Node* salida){
            salidas.push_back(salida);
        }
};
//Complejidad computacional O(n)
void loadGraph(int n, int m, vector<Node*> &lista){
    for (int i = 0; i < n; i++){
        int temp;
        cout << "Ingrese llave del nodo" << endl;
        cin >> temp;
        lista.push_back(new Node(temp));
    }
    for (int i = 0; i < m; i++){
        cout << "Ingrese la llave del nodo principal y la llave del nodo a dirigir" << endl << "a->b, separados por un espacio" << endl;
        int a, b;
        cin >> a >> b;
        Node* node_a = NULL;
        Node* node_b = NULL;
        for(int k = 0; k < n; k++){
            if(lista[k]->key == a){
                node_a = lista[k];
            }else if(lista[k]->key == b){
                node_b = lista[k];
            }
        }
        if(node_a && node_b){
            node_a->addSalida(node_b);
        }else{
            cout << "Una llave no ha sido encontrada" << endl;
            i--;
        }
    }
}
//Complejidad computacional O(n^2)
void printLista(vector<Node*> lista){
    for(int i = 0; i < lista.size(); i++){
        cout << lista[i]->key;
        for(int k = 0; k < lista[i]->salidas.size(); k++){
            cout << " -> " << lista[i]->salidas[k]->key;
        }
        cout << endl;
    }
}
//Complejidad computacional O(n^2)
Node* findHead(vector<Node*> lista){
    vector<Node*> accedidos;
    vector<Node*> noAccedidos;
    for (int i = 0; i < lista.size(); i++){
        for (int k = 0; k < lista[i]->salidas.size(); k++){
            accedidos.push_back(lista[i]->salidas[k]);
        }
    }
    for(int i = 0; i < lista.size(); i++){
        bool acceso = false;
        for(int k = 0; k < accedidos.size(); k++){
            if(lista[i]->key == accedidos[k]->key){
                acceso = true;
            }
        }
        if(acceso == false){
            noAccedidos.push_back(lista[i]);
        }
    }

    if(noAccedidos.size() != 1){
        return NULL;
    }else{
        return noAccedidos[0];
    }
}
//Complejidad computacional O(n(log(n)))
bool recorrer(Node* nodo, vector<int> &accedidos){ 
    if(nodo->salidas.size() > 0){
        if(accedidos.size() != 0){
            for(int i = 0; i < accedidos.size(); i++){
                if(nodo->key==accedidos[i]){
                    accedidos.push_back(nodo->key);
                    return false;
                }
            }
            accedidos.push_back(nodo->key);
        }else{
            accedidos.push_back(nodo->key);
        }
        for(int i = 0; i < nodo->salidas.size(); i++){
            recorrer(nodo->salidas[i], accedidos);
        }
    }
    else{
        accedidos.push_back(nodo->key);
        return false;
    }
    return false;
}


// Funcion auxiliar merge para el algoritmo merge sort
void merge(vector<int> &vect, int izq, int mitad, int der){
    int tamIzq = mitad - izq + 1;
    int tamDer = der - mitad;
    vector<int> izquierda;
    vector<int> derecha;
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
        if(izquierda[a] <= derecha[b]){
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
void ordenaMerge(vector<int> &vect, int izq, int der){
    int mitad = 0;
    if(izq < der){
        mitad = (izq + der) / 2;
        ordenaMerge(vect, izq, mitad);
        ordenaMerge(vect, mitad + 1, der);
        merge(vect, izq, mitad, der);
    }
}
//Función que verifica si un grafo es un árrbol con complejidad de O(n(log(n))) ya que usa la función recorrer, siendo esta el peor caso de complejidad
bool isTree(vector<Node*> lista, int n, int m){
    Node* head = findHead(lista);
    if(head){
        vector<int> accedidos;
        recorrer(head, accedidos);
        ordenaMerge(accedidos,0,accedidos.size()-1);
        bool duplicados = adjacent_find(accedidos.begin(), accedidos.end()) != accedidos.end();
        if(duplicados){
            return false;
        }else{
            return true;
        }
    }else{
        return false;
    }
}
//No se listan casos de prueba, ya que como se mencionó en clase, este programa utiliza entrada del usuario
int main(){
    int n, m;
    vector<Node*> lista;
    cout << "Ingrese cantidad de vertices" << endl;
    cin >> n;
    cout << "Ingrese cantidad de arcos" << endl;
    cin >> m;
    loadGraph(n,m,lista);
    cout << endl;
    printLista(lista);
    cout << "El grafo es un arbol?" << endl;
    if(isTree(lista, n, m)){
        cout << "SI" << endl;
    }else{
        cout << "NO" << endl;
    }
}