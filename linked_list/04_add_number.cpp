#include<bits/stdc++.h>
using namespace std;
/*
g++ 04_add_number.cpp
a.exe

clang++ 04_add_number.cpp
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

Node*  add_number(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    Node* curr1 = head1;
    Node* curr2 = head2;
    int carry = 0;
    while(curr1 != NULL || curr2 != NULL){
        int sum = carry;
        if(curr1) sum += curr1->data;
        if(curr2) sum += curr2->data;

        curr->next = new Node(sum % 10);
        carry = sum / 10;
        curr = curr->next;

        if(curr1) curr1 = curr1->next;
        if(curr2) curr2 = curr2->next;
    }
    if(carry){
        curr->next = new Node(carry);
    }

    return dummy->next;

}


int main(){
    int arr[] = {3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    int arr2[] = {4,5,9,9};
    n = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> vec2(arr2, arr2+n);

    Node* head1 = convertArr2LL(vec);
    Node* head2 = convertArr2LL(vec2);

    Node* head = add_number(head1, head2);
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