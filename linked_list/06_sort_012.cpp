#include<bits/stdc++.h>
using namespace std;
/*
g++ 06_sort_012.cpp
a.exe

clang++ 06_sort_012.cpp
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

Node* sort012(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* zDummy = new Node(-1);
    Node* oDummy = new Node(-1);
    Node* tDummy = new Node(-1);

    Node* zero = zDummy;
    Node* one = oDummy;
    Node* two = tDummy;

    Node* curr = head;

    while(curr != NULL){
        if(curr->data == 0){
            zero->next = curr;
            zero = zero->next;
        }else if(curr->data == 1){
            one->next = curr;
            one = one->next;
        }else{
            two->next = curr;
            two = two->next;
        }

        curr = curr->next;
    }

    zero->next = oDummy->next;
    one->next = tDummy->next;
    two->next = NULL;

    return zDummy->next;

}

int main(){
    int arr[] = {1,0,1,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    Node* head = convertArr2LL(vec);

    head = sort012(head);
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