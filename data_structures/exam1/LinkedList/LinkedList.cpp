#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(){
        head = NULL;
    }

LinkedList::~LinkedList(){
	Node* crawler;
	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}

// Add a new Node to the list
void LinkedList::insert(Node* prev, int newKey){

    //Check if head is Null i.e list is empty
    if(head == NULL){
        head = new Node;
        head->key = newKey;
        head->next = NULL;
    }

        // if list is not empty, look for prev and append our Node there
    else if(prev == NULL)
    {
        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = head;
        head = newNode;
    }

    else{

        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = prev->next;
        prev->next = newNode;

    }
}



// Building list
void LinkedList::loadList(int* keys , int length) {

    insert(NULL, keys[0]);

    Node* prev = head;

    for(int i = 1; i < length; i++)
    {
        insert(prev, keys[i]);
        prev = prev->next;
    }

}

// Print the keys in your list
void LinkedList::printList(){
    Node* temp = head;

    while(temp->next != NULL){
        cout<< temp->key <<" -> ";
        temp = temp->next;
    }

    cout<<temp->key<<" -> NULL"<<endl;
}

///////////////////////////////////////////////////////////////
// TODO : Complete the following function
void LinkedList::removeNthFromEnd(int n) {
  // If list is empty
  if (head == NULL) {
    return;
  }
  int count = 1;
  Node* temp = head;
  // Finding number of nodes in list
  while (true) {
    if (temp->next != NULL) {
      temp = temp->next;
      count++;
    }
    else {
      break;
    }
  }
  // If n is greater than number of nodes in list, it will not work
  if (n > count) {
    return;
  }
  delete temp;
  Node* current = head;
  Node* prev = NULL;
  // current node will be node to be deleted
  for (int i = 0; i < count-n; i++) {
    prev = current;
    current = current->next;
  }
  cout << current->key << endl;
  // deleting head
  if (current == head) {
    head = current->next;
  }
  // deleting tail
  else if (current->next == NULL) {
    prev->next = NULL;
  }
  else {
    prev->next = current->next;
  }
}
