#include<bits/stdc++.h>
using namespace std;
/*
g++ 17_reverse_ll_in_group.cpp
a.exe

clang++ 17_reverse_ll_in_group.cpp
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

Node* findKthNode(Node* head, int k){
    int pos=0;
    Node* curr = head;
    while(curr != NULL){
        pos++;
        if(pos == k) return curr;
        curr = curr->next;
    }
    return NULL;
}

Node* reverseInGroupOfK(Node* head, int k){
    Node* curr = head; Node* nextNode = NULL; Node* prevNode = NULL;
    while(curr != NULL){
        Node* kthNode = findKthNode(curr, k);
        if(kthNode == NULL){
            if(prevNode) prevNode->next = curr;
            break;
        }
        nextNode = kthNode->next;
        kthNode->next = NULL;
        reverse(curr);
        if(curr == head){
            head = kthNode;
        }else{
            prevNode->next = kthNode;
        }
        prevNode = curr;
        curr = nextNode;
    }
   return head;
}




int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    Node* head = convertArr2LL(vec);
    int k = 3;
    head = reverseInGroupOfK(head, k);
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