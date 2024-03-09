#include<bits/stdc++.h>
using namespace std;
/*
g++ 13_detect_loop.cpp
a.exe

clang++ 13_detect_loop.cpp
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

bool detectLoop(Node* head){
    if(head == NULL || head->next == NULL) return false;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;

        if(fast == slow) return true;
    }

    return false;

}


int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    Node* head = convertArr2LL(vec);

    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    // creating loop connecting 9 (tail) to 3 (3rd node)
    tail->next = head->next->next; 
    
    cout<<detectLoop(head);
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