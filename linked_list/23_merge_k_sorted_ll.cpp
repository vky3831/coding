#include<bits/stdc++.h>
using namespace std;
/*
g++ 19_merge_two_sorted_ll.cpp
a.exe

clang++ 23_merge_k_sorted_ll.cpp
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


Node* mergeKSortedLL(vector<Node*> headList){
    priority_queue<pair<int, Node*>, vector<pair<int, Node*> >, greater<pair<int, Node*> > > minHeap;
    for(int i=0; i<headList.size(); i++){
        if(headList[i] != NULL) minHeap.push(make_pair(headList[i]->data, headList[i]));
    }

    Node* dummy = new Node(-1);
    Node* curr = dummy;
    while(!minHeap.empty()){
        Node* temp = minHeap.top().second;
        minHeap.pop();
        curr->next = temp;
        curr = curr->next;
        temp = temp->next;
        if(temp) minHeap.push(make_pair(temp->data, temp));
    }
    return dummy->next;
}

int main(){
    int arr[] = {1, 6, 16, 18, 20};
    int arr2[] = {2, 7, 15, 17, 19, 21};
    int arr3[] = {3, 8, 13, 22};
    int arr4[] = {4, 9, 12, 22};
    int arr5[] = {5, 10, 11, 23, 25};

    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);
    Node* head = convertArr2LL(vec);

    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> vec2(arr2, arr2+n2);
    Node* head2 = convertArr2LL(vec2);

    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    vector<int> vec3(arr3, arr3+n3);
    Node* head3 = convertArr2LL(vec3);

    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    vector<int> vec4(arr4, arr4+n4);
    Node* head4 = convertArr2LL(vec4);

    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    vector<int> vec5(arr5, arr5+n5);
    Node* head5 = convertArr2LL(vec5);

    vector<Node*> headList;
    headList.push_back(head);
    headList.push_back(head2);
    headList.push_back(head3);
    headList.push_back(head4);
    headList.push_back(head5);

    head = mergeKSortedLL(headList);

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