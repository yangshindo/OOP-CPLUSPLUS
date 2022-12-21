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

    //Insere no início da lista
    void insertAtTheBeginning() {
      Node *node = new Node(rand() % 999);
      if (this->size == 0) {
        this->beginning = node;
      } else {
        Node *helper = this->beginning;
        this->beginning = node;
        this->beginning->setNext(helper);
      }
      this->size++;
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
        printf("\nInício da Lista:\n");
        for (int i = 0; i < this->size; i++) {
            printf("\n%d", node->getValue());
          node = node->getNext();
        }
      } else {
        printf("Lista vazia.");
      }
    }
};
