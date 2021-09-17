
#include <iostream>

using namespace std;

struct Node{
    Node* next;
    int val;
    
};

void printMiddle(Node* h){
    
    Node* n1=h;
    Node* n2=h;
    
    while(n2!=NULL && n2->next!=NULL){
        n2=n2->next->next;
        n1=n1->next;
    }
     cout<<n1->val<<"\n";
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
    printMiddle(n1);
    return 0;
}
