#include<bits/stdc++.h>
using namespace std;
/*
g++ 07_remove_Nth_fromEnd.cpp
a.exe

clang++ 07_remove_Nth_fromEnd.cpp
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

Node* removeNthFromEnd(Node* head, int n){
    Node* fast = head;
    Node* slow = head;
    int t = n;
    while(t--){
        fast = fast->next;
    }
    if(fast == NULL){
        Node* newHead = head->next;
        free(head);
        return newHead;
    }
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    Node* toDel = slow->next;
    slow->next = slow->next->next;
    free(toDel);
    return head;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    Node* head = convertArr2LL(vec);

    head = removeNthFromEnd(head, 6);
    printLL(head);
    head = removeNthFromEnd(head, 2);
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