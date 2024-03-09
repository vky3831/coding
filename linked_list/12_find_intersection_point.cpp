#include<bits/stdc++.h>
using namespace std;
/*
g++ 12_find_intersection_point.cpp
a.exe

clang++ 12_find_intersection_point.cpp
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



Node* findIntersectionPoint(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL) return NULL;

    Node* curr1 = head1;
    Node* curr2 = head2;

    while(curr1 != curr2){
        curr1 = curr1->next;
        curr2 = curr2->next;

        if(curr1 == curr2) return curr1;

        if(curr1 == NULL) curr1 = head2;
        if(curr2 == NULL) curr2 = head1;
    }

    return NULL;
}



int main(){
    int arr[] = {3, 1, 4, 6, 2};
    int arr2[] = {1, 2, 4, 5};

    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);
    Node* head = convertArr2LL(vec);

    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> vec2(arr2, arr2+n2);
    Node* head2 = convertArr2LL(vec2);

    Node* tail2 = head2;
    while(tail2->next != NULL){
        tail2 = tail2->next;
    }

    tail2->next = head->next->next;

    Node* point = findIntersectionPoint(head, head2);
    if(point == NULL) cout<<"NULL"<<endl;
    else cout<<point->data<<endl;

    /*
          3->1
              \
               4->6->2->NULL
              /      
    1->2->4->5
    */

    int arr3[] = {3, 1, 4, 6, 2};
    int arr4[] = {1, 2, 4, 5};

    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    vector<int> vec3(arr3, arr3+n3);
    Node* head3 = convertArr2LL(vec3);

    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    vector<int> vec4(arr4, arr4+n4);
    Node* head4 = convertArr2LL(vec4);

    point = findIntersectionPoint(head3, head4);
    if(point == NULL) cout<<"NULL"<<endl;
    else cout<<point->data<<endl;
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