#include <iostream>

class Stack {
  private:
    List *list = new List();

  public:
    Node *top() {
      return this->list->getEnd();
    };

    void stack(int value) {
      this->list->insertAtTheEnd(value);
    };

    int unstack() {
      return this->list->removeAt((list->getSize()) - 1);
    }

    void print() {
      return this->list->print();
    }

};
