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

    //Construtor
    Node(int intValue = 0) {value = intValue; next = nullptr;}

    //Gerando sobrecarga de operadores na classe
    void operator + (Node *node) {
        this->next = node;
    }

};
