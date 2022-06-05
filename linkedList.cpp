#include <iostream> 

using namespace std;

class Node{
    int info;
    Node *next;
}

void push(Node** head, int new_info){
    Node* new_node = new Node();

    new_node->info = new_info;

    new_node->next = (*head);

    (*head) = new_node;
}

int main(void){

}