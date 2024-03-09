#include<bits/stdc++.h>
using namespace std;
/*
g++ 05_segregate_odd_even.cpp
a.exe

clang++ 05_segregate_odd_even.cpp
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

Node* segregate_odd_even(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* eHead = head->next;
    Node* odd = head;
    Node* even = head->next;
    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = eHead;

    return head;

}

Node* segregate_odd_even_2(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* eDummy = new Node(-1);
    Node* oDummy = new Node(-1);

    Node* odd = oDummy;
    Node* even = eDummy;
    Node* curr = head;
    int it = 0;
    while(curr != NULL){
        it++;
        if(it%2 == 0){
            even->next = curr;
            even = even->next;
        }else{
            odd->next = curr;
            odd = odd->next;
        }
        curr = curr->next;
    }
    odd->next = eDummy->next;
    even->next = NULL;

    return head;

}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    Node* head = convertArr2LL(vec);

    head = segregate_odd_even_2(head);
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