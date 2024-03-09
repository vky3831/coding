#include<bits/stdc++.h>
using namespace std;
/*
g++ 01_linkedlist_intro.cpp
a.exe

clang++ 01_linkedlist_intro.cpp
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

int lengthOfLL(Node* head){
    int size = 0;
    Node* curr = head;
    while(curr != NULL){
        size++;
        curr = curr->next;
    }
    return size;
}

int search(Node* head, int val){
    Node* curr = head;
    while(curr != NULL){
        if(curr->data == val) return true;
        curr = curr->next;
    }
    return false;
}

Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp); // delete temp;
    return head;
}

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node* tail = temp->next;
    temp->next = NULL;
    free(tail);
    return head;
}

Node* removeKth(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        return removeHead(head);
    }
    Node *curr = head, *prev = NULL;
    int cnt = 0;
    while(curr != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(curr); 
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

Node* removeElement(Node* head, int el){
    if(head == NULL) return head;
    if(head->data == el){
        return removeHead(head);
    }
    Node *curr = head, *prev = NULL;

    while(curr != NULL){
        if(curr->data == el){
            prev->next = prev->next->next;
            free(curr); 
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

Node* insertHead(Node* head, int val){
    Node* newHead = new Node(val, head);
    return newHead;
}

Node* insertTail(Node* head, int val){
    if(head == NULL){
        return insertHead(head, val);
    }
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new Node(val);
    return head;
}

Node* insertKth(Node* head, int k, int val){
    if(head == NULL){
        if(k == 1) return insertHead(head, val);
        return head;
    }
    if(k == 1) return insertHead(head, val);
    int cnt = 0;
    Node* curr = head;
    while(curr != NULL){
        cnt++;
        if(cnt == (k-1)){
            Node* newNode = new Node(val, curr->next);
            curr->next = newNode;
            break;
        }
        curr = curr->next;
    }
    return head;
}

Node* insertBefore(Node* head, int el, int val){
    if(head == NULL){
        return head;
    }
    if(head->data == el) return insertHead(head, val);

    Node* curr = head;
    while(curr->next != NULL){

        if(curr->next->data == el){
            Node* newNode = new Node(val, curr->next);
            curr->next = newNode;
            break;
        }
        curr = curr->next;
    }
    return head;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    cout<<"convertArr2LL(vec)"<<endl;
    Node* head = convertArr2LL(vec);
    printLL(head);

    cout<<"lengthOfLL(head)"<<endl;
    cout<<lengthOfLL(head)<<endl;

    cout<<"search(head, 5)"<<endl;
    cout<<search(head, 5)<<endl;

    cout<<"search(head, 0)"<<endl;
    cout<<search(head, 0)<<endl;

    head = removeHead(head);
    cout<<"removeHead(head)"<<endl;
    printLL(head);

    head = removeTail(head);
    cout<<"removeTail(head)"<<endl;
    printLL(head);

    head = removeKth(head, 3);
    cout<<"removeKth(head, 3)"<<endl;
    printLL(head);

    head = removeElement(head, 2);
    cout<<"removeElement(head, 2)"<<endl;
    printLL(head);

    head = insertHead(head, 1);
    cout<<"insertHead(head, 1)"<<endl;
    printLL(head);

    head = insertTail(head, 11);
    cout<<"insertTail(head, 11)"<<endl;
    printLL(head);

    head = insertKth(head, 3, 4);
    cout<<"insertKth(head, 3, 4)"<<endl;
    printLL(head);

    head = insertBefore(head, 11, 10);
    cout<<"insertBefore(head, 11, 10)"<<endl;
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