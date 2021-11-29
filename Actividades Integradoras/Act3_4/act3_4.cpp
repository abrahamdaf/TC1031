/*
Act 3.4 - Actividad Integral de BST (Evidencia Competencia)


Diego Rosas A01634154
Alejandro Flores Madriz A01634167
Abraham De Alba Franco A01634133

Creado el 20/10/2021
Ultima edición 22/10/2021
*/
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;

template <class T> class Node {
    public:
        T data;
        int key;
        Node* left;
        Node* right;

        Node(T _data, int _key){
            data = _data;
            key = _key;
            this->left = NULL;
			this->right = NULL;
        }

        Node(){
          this->left = NULL;
			this->right = NULL;
        }
        
        Node(T new_data, int new_key, Node* left, Node* right){
            this->data = new_data;
            this->left = left;
			      this->right = right;
            key = new_key;
        }
        
        void set_right(Node* right){
            this->right = right;
        }

        void set_left(Node* left){
            this->left = left;
        }

        Node* get_left(){
          return this->left;
        }    

        Node* get_right(){
          return this->right;
        }       

        T get_data(){
            return this->data;
        }
        int get_key(){
            return this->key;
        }
};

template <class T> class Tree{
  public:
    Node<T>* root;

    Tree(){
      root = NULL;
    }
    //Función para añadir un nuevo nodo con complejidad O(log(n))
    void add(T dato, int key, Node<T>* aux){
      if(root == NULL){
        Node<T>* nuevo = new Node<T>;
        this->root = nuevo;
        root->data = dato;
        root->key = key;
        return;
      }
      if(key < aux->key){
        if(!aux->left){
          Node<T> *temp = new Node<T>;
          aux->left = temp;
          temp->data = dato;
          temp->key = key;
        }else{
          add(dato, key, aux->left);
        }
      }
      else{
        if(!aux->right){
          Node<T> *temp = new Node<T>;
          aux->right = temp;
          temp->data = dato;
          temp->key = key;
        }else{
          add(dato, key, aux->right);
        }
      }
    }
    //Función para eliminar un nodo con complejidad O(log(n))
    Node<T>* eliminar(Node<T> *node, int key){
        if (node == NULL){
            return node;
        }

        if (key < node->key){
            node->left = eliminar(node->left, key);
        }
    
        else if (key > node->key){
            node->right = eliminar(node->right, key);
        }
    
        else {
            if (node->left==NULL && node->right==NULL){
                return NULL;
            }
            else if (node->left == NULL){
                Node<T> *temp = new Node<T>;
                temp = node->right;
                if(node == root){
                    this->root = temp;
                }
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node<T> *temp = new Node<T>;
                temp = node->left;
                if(node == root){
                    this->root = temp;
                }
                delete node;
                return temp;
            }
    
            Node<T>* temp = min(node->right);
    
            node->key = temp->key;
    
            node->right = eliminar(node->right, temp->key);
        }
        return node;
    }
    //Función para obtener el nodo más pequeño del subarbol con complejidad O(log(n))
    Node<T>* min(Node<T> *node){
        while(node && node->left){
            node = node->left;
        }
        return node;
    }
}; 

template<class T>
void leerBitacora(Tree<T> &arbol){
    ifstream data;
    data.open("ipsPorAcceso.txt");
    if (data.is_open()){
        string line;
        while(getline(data, line)){
            stringstream ss(line);
            int accesos;
            string ip;
            ss >> ip >> accesos;
            arbol.add(ip, accesos, arbol.root);
        }
    }
}

//Función para desplegar los 5 mayores elementos con complejidad O(log(n))
template<class T>
void desplegar(Tree<T> tree){
    Node<T> *temp = new Node<T>;
    temp = tree.root;
    for(int i = 0; i < 5; i++){
        while(temp->right){
            temp = temp->right;
        }
        cout << temp->data << " Accesos: " << temp->key << endl;
        tree.eliminar(tree.root, temp->key);
        temp = tree.root;
    }
}

int main() {
    //Máxima cantidad de datos posibles de interpretar por restricciones de memoria:
    //           12995
    Tree<string> myTree;
    leerBitacora(myTree);
    desplegar(myTree);
}
