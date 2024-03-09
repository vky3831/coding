#include<bits/stdc++.h>
using namespace std;
/*
g++ 08_reverse_linked_list.cpp
a.exe

clang++ 08_reverse_linked_list.cpp
./a.out
*/
class Node {
    public:
    int data;
    Node* next;

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void printLL(Node* head);
Node* convertArr2LL(vector<int> arr);

Node* reverse(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* curr = head;
    Node* prev = NULL;
    
    while(curr != NULL){
        Node* ahead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;
    }

    return prev;
}

Node* reverse_recursion(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* newHead = reverse_recursion(head->next);
    Node* front = head->next;

    front->next = head;
    head->next = NULL;

    return newHead;

}


int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    Node* head = convertArr2LL(vec);

    head = reverse(head);
    printLL(head);

    head = reverse_recursion(head);
    printLL(head);
}

void printLL(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<", ";
        curr = curr->next;
    }
    cout<<endl;
}

Node* convertArr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}