#include<bits/stdc++.h>
using namespace std;
/*
g++ 15_delete_middle_node.cpp
a.exe

clang++ 15_delete_middle_node.cpp
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

Node* deleteMidNode(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* prev = NULL;
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next;
        prev = slow;
        slow = slow->next;
        if(fast) fast = fast->next;
        
    }
    prev->next = slow->next;
    free(slow);
    return head;
}

int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    Node* head = convertArr2LL(vec);

    head = deleteMidNode(head);
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