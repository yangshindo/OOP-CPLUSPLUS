#include "lib.hpp"
#include <iostream>
using namespace std;

void stackDemonstration() {
  Stack *stack = new Stack();
  printf("Inserindo 10, 60 e 33 e imprimindo a pilha:\n");
  stack->stack(10);
  stack->stack(60);
  stack->stack(33);
  stack->print();
  printf("\n Removendo valor do topo... \n");
  stack->unstack();
  printf("\n Nova pilha: \n");
  stack->print();
}

void queueDemonstration() {
  int value;
  Queue *queue = new Queue();

  printf("Inserindo 10, 60 e 33 e imprimindo a fila:\n");
  queue->enqueue(10);
  queue->enqueue(60);
  queue->enqueue(33);
  printf("Fila: \n");
  queue->print();
  printf("\nRemovendo o primeiro elemento da fila...\n");
  queue->dequeue();
  printf("\nNova fila: \n");
  queue->print();
  printf("\n");
}

void listDemonstration() {
  List *list = new List();
  printf("\nInserindo os valores 10, 60 e 33: ");
  list->insertAtTheEnd(10);
  list->insertAtTheEnd(60);
  list->insertAtTheEnd(33);
  list->print();
  printf("\n\nInserindo no início o valor 26 \n");
  list->insertAtTheBeginning(26);
  printf("\nInserindo no fim o valor 49 \n");
  list->insertAtTheEnd(49);
  printf("\nRemovendo o valor 33 da lista: \n");
  list->removeItem(33);
  printf("\nNova lista:");
  list->print();
  printf("\n");
}

void overloadDemonstration() {
  printf("\nGerando sobrecarga de operadores\n");
  Node *firstNode = new Node(10);
  Node *secondNode = new Node(30);
  *firstNode + secondNode;
  std::cout << "First node: " << firstNode->getValue()
            << ", First node Next:" << firstNode->getNext()->getValue();
  printf("\n");
}

int main() {
  int operation, userInputValue;
  List *list = new List();

  while (1) {
    printf("\n1 - Pilha \n2 - Fila \n3 - Lista\n4- Sobrecarga \n0- Sair \n\n ");
    scanf("%d", &operation);

    switch (operation) {
    case 1:
      stackDemonstration();
      break;
    case 2:
      queueDemonstration();
      break;
    case 3:
      listDemonstration();
      break;
    case 4:
      overloadDemonstration();
    case 0:
      exit(0);
      break;
    default:
      if (operation != 0)
        printf("\nFavor selecionar uma opção válida (de 0 à 4)\n");
      break;
    }
  }
}
