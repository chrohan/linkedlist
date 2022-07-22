#include<iostream>
using namespace std;

struct Node {
    int val;
    Node * next;
};

void printLinkedList(Node * head){
    while(head != NULL) {
       cout<<head->val<<" ";
       head = head->next;
    }
    printf("\n");
}

Node * create5(){
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *fifth = new Node();
    first->val = 2;
    second->val = 3;
    third->val = 5;
    fourth->val = 7;
    fifth->val = 11;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    return first;
}

 void insertAtEnd(Node *head, int valToBeInsertedAtEnd){
     Node *temp = head;
     while(temp->next != NULL){                       //  2->3->5->7->11->null
         temp = temp->next;
     }

     Node *toBeInsertedAtEnd = new Node();
     toBeInsertedAtEnd->val = valToBeInsertedAtEnd;
     toBeInsertedAtEnd->next = NULL;

     temp->next = toBeInsertedAtEnd;

 }

 Node * insertAtBeg(Node *head, int val){
     Node *toBeInsertedAtBeg = new Node();
     toBeInsertedAtBeg->val = val;
     toBeInsertedAtBeg->next = head;
     head = toBeInsertedAtBeg;
     return head;
 }

int countNoOfELements(Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

void insertAt4th(Node *head, int val){
    int n = 4;
    // to insert at nth position, we need to know the address of n-1th node and to get the address of (n-1)th node traverse first n-2 nodes:
    for(int i = 1;i<=n-2;i++){
         head  = head->next;
    }
    Node *next = head->next;

    Node *toBeInserted = new Node();
    toBeInserted->val = val;
    toBeInserted->next = next;
    head->next = toBeInserted;

}

int recursiveLength(Node *head){
    if(head == NULL)
      return 0;
    else
      return 1 + recursiveLength(head->next);  
}

Node * reverse(Node *head){
    Node *prev = NULL;
    Node *current = head;
    Node *next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
         // getting ready for next iteration
        prev = current;     
        current = next;
    }
    head = prev;
    return head;
}

int main(){
    // create a linked list of 5 nodes containing first 5 prime numbers
    Node *head = create5();
    //  print the values of above linked literals
    printLinkedList(head);
    /*
    Inserting a node
    1. At end
    2. At beginning
    3.After a given node
    4. At given postion
    To insert a node we need prev node address
    */
    int valToBeInsertedAtEnd, valToBeInsertedAtBeg;
    cin>>valToBeInsertedAtEnd;
    insertAtEnd(head, valToBeInsertedAtEnd);
    printLinkedList(head);
    cin>>valToBeInsertedAtBeg;
    head = insertAtBeg(head, valToBeInsertedAtBeg);
    printLinkedList(head);

    //Insert 72 at 4th position
     insertAt4th(head,72);

     printLinkedList(head);

    // Find the number of elements in a linked list
    int sizeOfLinkedList = countNoOfELements(head);
    cout<<"\nThe size of linked list is "<<sizeOfLinkedList<<"\n";

    //Find length of linked list recursive method
    int length = recursiveLength(head);

     //reverse a linked list
     head = reverse(head);

     printLinkedList(head);



}