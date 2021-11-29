#include <iostream>

using namespace std;

template <class T> class Node {
    public:
        T data; // The object information
        Node* next; // Pointer to the next node element
        Node* prev;

        void set_data(T new_data){
            this->data = new_data;
        }

        void set_next(Node *next_node){
            this->next = next_node;
        }
        void set_prev(Node *prev_node){
            this->prev = prev_node;
        }
};


template <class T> class CustomLinkedList{
    Node<T> *head;
    Node<T> *tail;

    public:
        CustomLinkedList(){
            head = NULL;
            tail = NULL;
        }

        ~CustomLinkedList(){

        }

        // Method adds info to the end of the list
        void add_end(T info){
            if(head == NULL){ //if our list is currently empty
                head = new Node<T>; //Create new node of type T
                this -> tail = this -> head;
                head->set_data(info);
                head->set_next(NULL);
                head->set_prev(NULL);
            }
            else{ //if not empty add to the end and move the tail
                Node<T>* temp = new Node<T>;
                this -> tail = temp;
                temp->set_data(info);
                temp->set_next(NULL);
                temp->set_prev(NULL);

                Node<T>* current_node = this->head;
                while (current_node->next != NULL){
                    current_node = current_node->next;
                }
                
                current_node->next = temp;
                temp->set_prev(current_node);
            }
        }

        // Method adds info to the begining of the list
        void add_begin(T info){
            Node<T>* temp = new Node<T>;
            temp->set_data(info);
            temp->set_next(head);
            temp->set_prev(NULL);
            if(temp->next == NULL){
                this -> tail = temp;
            }
            
            this->head = temp;
        }


        void add_after_node(T value_insert, T value_after){
            Node<T>* currentNode = new Node<T>;
            currentNode = head;
            while(currentNode!=NULL){
                if(currentNode->data==value_after){
                    Node<T>* aux = new Node<T>;
                    aux->set_data(value_insert);
                    aux->set_next(currentNode->next);
                    (aux->next)->set_prev(aux);
                    aux->set_prev(currentNode);
                    currentNode->set_next(aux);
                    if(aux->next==NULL){
                        this -> tail = aux;
                    }
                    return;
                }
                currentNode = currentNode->next;
            }
        }

        void delete_node(T value){
            if(!this->head){
                // Empty linked list, no values to delete
                return;
            }
            
            // Check if the node to delete is the head
            if(this->head->data == value){
                this->head = this->head->next;
                return;
            }

            Node<T>* current_node = this->head;
            // Search for the node to delete
            while ( current_node && current_node->next->data != value){
                current_node = current_node->next;
            }

            // current node is empty the node wasn't found 
            if(!current_node){
                return;
            }

            Node<T>* node_to_delete = current_node->next;

            current_node->next = node_to_delete->next;
            if(node_to_delete->next!=NULL){
                (node_to_delete -> next) -> prev = current_node;
            }else{
                this -> tail = current_node;
            }
            if(current_node->prev == NULL){
                this -> head = current_node;
            }
            delete node_to_delete;
        }

        void print_list(){
            Node<T>* current_node = this->head;
            while (current_node != NULL){
                cout << current_node ->data << " <-> ";

                current_node = current_node->next;
            }
            cout << endl;
        }

        void print_reverse(){
            Node<T>* current_node = this->tail;
            while (current_node != NULL){
                cout << current_node ->data << " <-> ";

                current_node = current_node->prev;
            }
            cout << endl;
        }

        
};



int main(){
    CustomLinkedList<int> firstList;
    firstList.add_end(31);
    firstList.add_end(32);
    firstList.add_end(33);
    firstList.add_end(34);
    firstList.add_after_node(20,33);
    firstList.add_end(35);
    firstList.print_list();

    firstList.delete_node(35);
    firstList.print_list();

    firstList.delete_node(34);
    firstList.print_list();
    firstList.print_reverse();

    return 0;
}