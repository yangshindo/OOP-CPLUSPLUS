#include <iostream>
using namespace std;

class List {
  private:

    Node *beginning;
    Node *end;
    int size;

  public:

    //GETTERS
    Node *getBeginning() {return this->beginning;}
    Node *getEnd() {return this->end;}
    int getSize() {return this->size;}

    //Insere no início da lista
    void insertAtTheBeginning(int value) {
      Node *node = new Node(value);
      if (this->size == 0) {
        this->beginning = node;
      } else {
        Node *helper = this->beginning;
        this->beginning = node;
        this->beginning->setNext(helper);
      }
      this->size++;
    }


    //Insere no fim da lista
    void insertAtTheEnd(int value) {
      Node *node = new Node(value);
      if (this->size == 0) {
        this->beginning = node;
        this->end = node;
      } else {
        this->end->setNext(node);
        this->end = node;
      }
      this->size++;
    }

  

    //Remove de uma posição específica
    int removeAt(int position) {

      if (this->size == 0) {
        return -1;
      }

      if (this->size == 1) {
        Node *helper = this->beginning;
        this->beginning = nullptr;
        this->end = nullptr;
        delete helper;
        this->size--;
      }

      // link previous deleted node to next one
      Node *lastNode;
      Node *node = this->beginning;
      for (int i = 0; i < this->size; i++) {
        if (i == position) {
          int value = node->getValue();
          
          if (i == 0) {
            this->beginning = currentNode->getNext();
          } else {
            previousNode->setNext(currentNode->getNext());
          }
        }
          delete node;
          this->size--;
          return value;
        }
        lastNode = node;
        node = node->getNext();
      }
      return -1;
    }


    //Remove valor específico
    int removeItem(int item) {
      Node *previousNode;
      Node *node = this->beginning;
      int i = 0;

      while (node->getValue() != item && node->getNext() != nullptr) {
        previousNode = node;
        node = node->getNext();
        i++;
      }

      if (!node->getNext() != NULL && node->getValue() != item) {
        return -1;
      }

      int value = node->getValue();

      if (i == 0) {
        this->beginning = node->getNext();
        } else {
          previousNode->setNext(node->getNext());
        }
      delete node;
      this->size--;

      return value;
    }

    //PRINT
    void print() {
      if (this->size > 0) {
        Node *node = this->beginning;
        for (int i = 0; i < this->size; i++) {
            printf("\n%d", node->getValue());
          node = node->getNext();
        }
      } else {
        printf("Não há elementos.");
      }
    }
};
