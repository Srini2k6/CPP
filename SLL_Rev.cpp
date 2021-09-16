#include <iostream>

using namespace std;

struct Node{
    
    int val;
    Node* next;
    
};

void rev(Node* &head){
    
    Node* prv=NULL;
    Node* next=NULL;
    Node* curnt=head;
    
    while(curnt!=NULL){
        next=curnt->next;
        curnt->next=prv;
        prv=curnt;
        curnt=next;
    }
    head=prv;
}

void print(Node* h){
    Node* n=h;
    while(n!=NULL){
        cout<<n->val<<"\n";
        n=n->next;
    }
}

int main()
{
    Node* n1= new Node();
    Node* n2= new Node();
    Node* n3= new Node();
    Node* n4= new Node();
    Node* n5= new Node();
    n1->val=1; n1->next=n2;
    n2->val=2; n2->next=n3;
    n3->val=3; n3->next=n4;
    n4->val=4; n4->next=n5;
    n5->val=5; n5->next=NULL;
    cout<<"Before Rev:"<<endl;
    print(n1);
    rev(n1);
    cout<<"After Rev:"<<endl;
    print(n1);
    
}
