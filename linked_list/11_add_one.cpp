#include<bits/stdc++.h>
using namespace std;
/*
g++ 11_add_one.cpp
a.exe

clang++ 11_add_one.cpp
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

    Node* newHead = reverse(head->next);
    Node* front = head->next;

    front->next = head;
    head->next = NULL;

    return newHead;

}

Node* addOne(Node* head){
    Node* rhead = reverse(head);
    Node* curr = rhead;
    int carry = 1;
    while(curr != NULL){
        int sum = carry;
        sum += curr->data;

        curr->data = sum % 10;
        carry = sum / 10;

        curr = curr->next;
    }
    head = reverse(rhead);
    if(carry){
        Node* newHead = new Node(carry, head);
        head = newHead;
    }

    return head;
}

int main(){
    int arr[] = {9, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    Node* head = convertArr2LL(vec);

    head = addOne(head);
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