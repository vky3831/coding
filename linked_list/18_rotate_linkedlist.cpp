#include<bits/stdc++.h>
using namespace std;
/*
g++ 18_rotate_linkedlist.cpp
a.exe

clang++ 18_rotate_linkedlist.cpp
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

Node* findKthNode(Node* head, int k){
    int pos=0;
    Node* curr = head;
    while(curr != NULL){
        pos++;
        if(pos == k) return curr;
        curr = curr->next;
    }
    return NULL;
}

Node* rotate(Node* head, int k){
    if(head == NULL) return head;

    int len = 1;
    Node* tail = head;
    while(tail->next != NULL){
        len++;
        tail = tail->next;
    }

    if(len%k == 0) return head;

    int newTailPosition = len - k;
    Node* newTail = findKthNode(head, newTailPosition);

    tail->next = head;
    head = newTail->next;
    newTail->next = NULL;

    return head;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    Node* head = convertArr2LL(vec);
    int k = 3;
    head = rotate(head, k);
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