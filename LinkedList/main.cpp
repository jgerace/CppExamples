#include <cstdlib>
#include <iostream>

using namespace std;

struct Node
{
       int data;
       Node *next;
};

Node *insertFront(Node *head, int data) // to modify head in place, use Node **head
{
     Node *n = new Node;
     n->data = data;
     n->next = head;

     head = n;

     return head;
}

Node *deleteFront(Node *head)
{
    if(head == NULL) {
        return head;
    }

    Node *temp = head->next;
    delete head;
    head = temp;
    return head;
}

bool find(Node *head, int data) // is a piece of data in the list?
{
     while(head != NULL) {
        if(head->data == data) {
           return true;
        }
        else {
           head = head->next;
        }
     }

     return false;
}

void printList(Node *head)
{
     while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
     };
     cout << endl;
}

void deleteList(Node **head)
{
     Node *deleteMe = *head;

     while(deleteMe != NULL) {
        Node *next = deleteMe->next;
        delete deleteMe;
        deleteMe = next;
     }

     *head = NULL; // prevent dangling pointer
}

int main(int argc, char *argv[])
{
    Node *head = NULL; // initialize just to be safe

    head = insertFront(head, 1);
    head = insertFront(head, 2);

    printList(head);

    if(find(head, 2)) {
       cerr << "2 is in list" << endl;
    }

    if(!find(head, 3)) {
       cerr << "3 is not in list" << endl;
    }

    cout << "Deleting first element" << endl;
    head = deleteFront(head);

    printList(head);

    cerr << "deleting" << endl;
    deleteList(&head);

    return 0;
}
