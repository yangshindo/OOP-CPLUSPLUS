#include "lib.hpp"
#include <iostream>
using namespace std;

int main() {
  int operation, userInputValue;
  List *linkedList = new List();

  printf("\nGerando sobrecarga de operadores\n");

  Node *firstNode = new Node(10);
  Node *secondNode = new Node(30);
  *firstNode + secondNode;
  std::cout << "First node: " << firstNode->getValue()
            << ", First node Next:" << firstNode->getNext()->getValue();

  printf("\n");

  while (1) {
    printf("\n1 - Inserir no início\n2 - Remover um valor da lista \n3- "
           "Imprimir Lista \n0- Sair\n");
    scanf("%d", &operation);

    switch (operation) {
    case 1:
      linkedList->insertAtTheBeginning();
      break;
    case 2:
      printf("\nQual valor você deseja excluir da lista?\n");
      scanf("%d", &userInputValue);
      linkedList->removeItem(userInputValue);
      break;
    case 3:
      linkedList->print();
      printf("\n");
      break;
    case 0:
      exit(0);
      break;
    default:
      if (operation != 0)
        printf("\nFavor selecionar uma opção válida (de 0 à 3)\n");
      break;
    }
  }
}
