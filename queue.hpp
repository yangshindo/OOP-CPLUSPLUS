#include <iostream>

class Queue {

  private:
    List *list = new List();

  public:
    Node *first() {
      return this->list->getBeginning();
    }

    void enqueue(int value) {
      this->list->insertAtTheEnd(value);
    }

    int dequeue() {
      return this->list->removeAt(0);
    }

    void print() {
      this->list->print();
    }
};
