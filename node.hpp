#include <iostream>
using namespace std;

class Node {
  protected:
    Node *next;
    int value;

  public:

    //GETTERS
    int getValue() {return this->value;}
    Node *getNext() {return this->next;}

    //SETTERS
    void setValue(int value) {this->value = value;}
    void setNext(Node *next) {this->next = next;}

    
    // Remover e limpar memória
    void remove() {
      Node *helper = this->next;
      if (this->next != nullptr) {
        this->next = this->next->getNext();
      } else {
        this->next = nullptr;
      }
      delete helper;
    }

    //Construtor
    Node(int intValue = 0) {value = intValue; next = nullptr;}

    //Gerando sobrecarga de operadores na classe
    void operator + (Node *node) {
        this->next = node;
    }

   //Gerando sobrecarga de operadores com função aberta
   //void operator + (Node *node1, Node *node2) { 
    // node1->next = node2;
    // }

};
