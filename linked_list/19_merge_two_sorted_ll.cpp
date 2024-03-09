#include<bits/stdc++.h>
using namespace std;
/*
g++ 19_merge_two_sorted_ll.cpp
a.exe

clang++ 19_merge_two_sorted_ll.cpp
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

int main(){
    int arr[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8};

    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);
    Node* head = convertArr2LL(vec);

    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> vec2(arr2, arr2+n2);
    Node* head2 = convertArr2LL(vec2);

    head = mergeTwoSortedLL(head, head2);

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