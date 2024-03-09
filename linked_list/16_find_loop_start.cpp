#include<bits/stdc++.h>
using namespace std;

/*
g++ 16_find_loop_start.cpp
a.exe

clang++ 16_find_loop_start.cpp
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

Node* findLoopStart(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;
        if(fast == slow) break;
    }

    if(fast == NULL) return NULL;

    slow = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
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

    tail->next = head->next->next;
        // tail->next = head;


    Node* loopStart = findLoopStart(head);

    if(loopStart == NULL) cout<<"null";
    else cout<<loopStart->data;
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

