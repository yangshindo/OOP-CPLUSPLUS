#include <iostream>
#include <string>
using std::string;

// Classe nó
class Node {
public:
  int Value;
  Node *Next;

  // Construtor
  Node(int value, Node *next) {
    value = Value;
    next = Next;
  }

  // Setters
  void setValue(int value) { Value = value; }

  void setNext(Node *next) { Next = next; }

  // Getters
  int getValue() { return this->Value; }

  Node* getNext() { return this->Next; }
};

// Classe Lista
class List {
public:
  Node *Beginning;
  Node *End;
  int Size;

  // Construtor
  List(Node *beginning, Node *end, int size) {
    beginning = Beginning;
    end = End;
    size = Size;
  }

  // Setters
  void setBeginning(Node *beginning) { Beginning = beginning; }
  void setEnd(Node *end) { End = end; }
  void setSize(int size) { Size = size; }

  // Getters
  Node* getBeginning() { return this->Beginning; }
  Node* getEnd() { return this->End; }
  int getSize() { return Size; }
};


void insertAtTheBeginning(List *list) {
  Node *newNode = new Node(0, NULL);
  int newValue = rand() % 999;
  if (newNode) {
    newNode->setValue(newValue);
    newNode->setNext(list->Beginning);
    list->setBeginning(newNode);
    list->setSize(list->getSize() + 1); // AUMENTANDO COM SETTER
  } else
    printf("\nErro no malloc (memória não alocada).\n");
}

void insertAfterXValue(List *list, int previousValue) {
  Node *helper = new Node(0, NULL);
  Node *newNode = new Node(0, NULL);
  int newValue = rand() % 999;
  if (newNode) {
    newNode->setValue(newValue);
    // é o primeiro?
    if (list->Beginning == NULL) {
      newNode->setNext(NULL);
      list->setBeginning(newNode);
    } else {
      helper = list->Beginning; // SEM GETTER
      while (helper->Value != previousValue && helper->Next)
        helper = helper->Next; /// SEM SETTER
      newNode->setNext(helper->Next);
      helper->setNext(newNode);
    }
    list->Size++; // SEM SETTER
  } else
    printf("\nErro no malloc (memória não alocada).\n");
}

// remover um elemento da lista
void removeItem(List *list, int choosenValue) {
  Node *beginning = list->Beginning; // ajustando ponteiro para o início
  Node *toRemove = NULL; // ajustando ponteiro para o nó que será removido

  // se o primeiro valor da lista for o valor escolhido pelo usuário, remove
  // ele.
  if (beginning != NULL && list->Beginning->Value == choosenValue) {
    toRemove = list->Beginning;
    list->Beginning = toRemove->Next;
    if (list->Beginning == NULL) // caso essa remoção esvazie a lista
      list->End = NULL;
  } else {
    while (beginning != NULL && beginning->Next != NULL &&
           beginning->Next->Value != choosenValue) {
      beginning = beginning->Next; // anda através da lista procurando o valor
                                   // escolhido para remover
    }
    if (beginning != NULL && beginning->Next != NULL) {
      toRemove = beginning->Next;
      beginning->Next = toRemove->Next;
      if (beginning->Next == NULL) // caso o elemento removido tenha feito a
                                   // lista restar apenas 1 elemento
        list->End =
            beginning; // o primeiro e o último agora são o mesmo elemento
    }
  }
  /*Abre espaço de memória após remover o elmento e decrementa o tamanho da
   * lista*/
  if (toRemove) {
    delete toRemove;
    list->Size--;
  }
}

void printList(List list) {
  Node *node = list.Beginning;
  printf("\nInício da Lista\n");
  while (node) {
    printf("%d \n", node->Value);
    node = node->Next;
  }
  printf("\n\n");
}

int main() {
  int operation, userInputValue;
  List *list = new List(NULL, NULL, 0);

  while (1) {
    printf("\n1 - Inserir no início\n2 - Inserir após um "
           "valor específico\n3- Remover valor da lista\n4 - Imprimir "
           "Lista\n0- Sair\n");
    scanf("%d", &operation);

    switch (operation) {
    case 1:
      insertAtTheBeginning(list);
      break;
    case 2:
      printf("\nVocê deseja adicionar um novo elemento após qual valor "
             "presente na lista?\n");
      scanf("%d", &userInputValue);
      insertAfterXValue(list, userInputValue);
      break;
    case 3:
      printf("\nQual valor você deseja excluir da lista?\n");
      scanf("%d", &userInputValue);
      removeItem(list, userInputValue);
    case 4:
      printList(*list);
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
