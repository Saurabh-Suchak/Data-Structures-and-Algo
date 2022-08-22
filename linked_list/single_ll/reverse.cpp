// contains both iterative and recursive method

#include <iostream>
using namespace std;

class LinkedList {
    public:
        class Node {
            public:
            int val;
            Node * next;
            Node(int data) {
                val = data;
                next = NULL;
            }
        };

    Node * head = NULL;

    void display() //prints linked list
    {

        Node * curr = head;
        while (curr) {
            cout << curr -> val << " ";
            curr = curr -> next;
        }
        cout << endl;
    }

    void AddEnd(int data) { //adds node in the end of linked list
        Node * node = new Node(data);
        if (!head) {
            head = node;
            head -> next = NULL;
        }
        Node * temp = head;
        while (temp -> next) {
            temp = temp -> next;
        }
        temp -> next = node;
        node -> next = NULL;
    }

    void reverse_recursive()
    {
        if (head == NULL || head->next == NULL)
            return;
  
        /* reverse the rest list and put 
          the first element at the end */
        Node* rest = reverse_recursive();
        head->next->next = head;
  
        /* tricky step -- see the diagram */
        head->next = NULL;
  
        /* fix the head pointer */
        head=rest;
    }

    void reverse_iterative()
    {
        // Initialize current, previous and next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
  
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }   
};


int main() {
    LinkedList l1; //ll is an object of type LinkedList

    cout << "Elements will be inserted in the end" << endl;

    for (int i = 1; i < 10; i++) {
        l1.AddEnd(i);
    }

    l1.display();

    cout<<"reversed list is -"<< endl;
    l1.reverse_iterative();
    l1.display();

    cout<<"reversing again using recursive method -"<<endl;
    l1.reverse_recursive();
    l1.display();


    return 0;
}