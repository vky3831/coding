#include<bits/stdc++.h>
using namespace std;
/*
g++ 24_sort_linkedlist.cpp
a.exe

clang++ 24_sort_linkedlist.cpp
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


Node* mergeTwoSortedLL(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL) return head1 == NULL ? head2 : head1;

    Node* dummy = new Node(-1);
    Node* curr = dummy;

    Node* curr1 = head1;
    Node* curr2 = head2;

    while(curr1 != NULL && curr2 != NULL){
        if(curr1->data < curr2-> data){
            curr->next = curr1;
            curr = curr->next;
            curr1 = curr1->next;
        }else{
            curr->next = curr2;
            curr = curr->next;
            curr2 = curr2->next;
        }
    }

    if(curr1 != NULL){
        curr->next = curr1;
    }

    if(curr2 != NULL){
        curr->next = curr2;
    }

    return dummy->next;

}

Node* findMid(Node* head){
    // if(head == NULL || head->next == NULL) return head;

    Node* slow = head;
    Node* fast = head;
    fast = fast->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;


}

Node* mergeSortLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    // cout<<"left->data: "<<left->data<<endl;
    // cout<<"mid->data: "<<mid->data<<endl;
    // cout<<"right->data: "<<right->data<<endl;

    left = mergeSortLL(left);
    right = mergeSortLL(right);

    return mergeTwoSortedLL(left, right);


}

int main(){
    int arr[] = {1, 9, 6, 8, 2};

    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);
    Node* head = convertArr2LL(vec);

    head = mergeSortLL(head);

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