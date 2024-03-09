#include<bits/stdc++.h>
using namespace std;
/*
g++ 10_check_palindrome.cpp
a.exe

clang++ 10_check_palindrome.cpp
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

Node* reverse(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverse(head->next);
    Node* front = head->next;

    front->next = head;
    head->next = NULL;

    return newHead;
}

bool checkPalindrome(Node* head){
    if(head == NULL && head->next == NULL) return true;
    Node* mid = findMiddleElement(head);
    Node* rhead = reverse(mid->next);
    Node* curr1 = head;
    Node* curr2 = rhead;

    while(curr2 != NULL){
        if(curr1->data != curr2->data){
            reverse(rhead);
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    reverse(rhead);
    return true;
}


int main(){
    int arr[] = {1,2,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    Node* head = convertArr2LL(vec);

    cout<<checkPalindrome(head);
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