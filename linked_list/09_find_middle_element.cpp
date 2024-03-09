#include<bits/stdc++.h>
using namespace std;
/*
g++ 09_find_middle_element.cpp
a.exe

clang++ 09_find_middle_element.cpp
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

Node* findMiddleElement(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* slow = head;
    Node* fast = head;
    fast = fast->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
        if(fast) fast = fast->next;
        
    }
    return slow;
}

int main(){
    int arr[] = {1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    Node* head = convertArr2LL(vec);

    Node* mid = findMiddleElement(head);
    cout<<mid->data<<endl;
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