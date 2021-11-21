#include <iostream> 
//#include <bitset>/stdc++.h>
using namespace std;


class Node { 
    public: 
        int data; 
        Node* next; 
        Node(int val = 0, Node* n = NULL){
            data = val;
            next = n;
        }
};

class LinkedList {
    public:
        Node* head;

        LinkedList(Node* head){
            this->head = head;
        }
        void printList(){
            Node* temp = this->head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }

        void addValues(Node* n){
            Node* temp = this->head;
            while(temp != NULL && n != NULL){
                temp->data += n->data;
                temp = temp->next;
                n = n->next;
            }
            this->printList();
        }

        void addValues(LinkedList* n){
            Node* temp = this->head;
            while(temp != NULL && n->head != NULL){
                temp->data += n->head->data;
                temp = temp->next;
                n->head = n->head->next;
            }
            this->printList();
        }

        void bubbleSort(){
            cout << "Unsorted List\n";
            this->printList();
            Node* temp1 = this->head;
            while(temp1 != NULL){
                Node* temp2 = this->head;
                while(temp2 != NULL){
                    if(temp1->data < temp2->data){
                        int swap = temp1->data; 
                        temp1->data = temp2->data;
                        temp2->data = swap;
                    }
                    temp2 = temp2->next;
                }
                temp1 = temp1->next;
            }
            cout << "Sorted List\n";
            this->printList();
        }

};

int main() {
    Node* head = new Node(1, new Node(2, new Node()));
    LinkedList* list = new LinkedList(head);
    cout << "First List\n", list->printList();
    Node* testNode = new Node(8, new Node(3, new Node(5, NULL)));
    LinkedList* testList = new LinkedList(testNode);
    cout <<  "Second List\n", testList->printList();

    cout << "Adding two lists\n", list->addValues(testList);
    cout << "Adding nodes to list\n", list->addValues(testNode);
    list->bubbleSort();
    //second->addValues(third);
}