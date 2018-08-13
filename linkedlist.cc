#include<iostream>
using namespace std;

template <class T>
class Node
{
	public:
	T data;
	Node *next;
	Node(T t):data(t){}

};

template <class T>
class List
{
	private:
		Node<T>* start;
	public:
		List()
		{
			start=NULL;
		}
		void addNode(T t);
		void print();
		void printrev();
		void printrev(Node<T>*);
		void printrevN(int);
		
};
template <class T>
void List<T>::addNode(T data)
{
	if(start == NULL)
	{
		start = new Node<T>(data);
		start->next=NULL;
	}
	else
	{
		Node<T>* node = new Node<T>(data);
		node->next=start;
		start=node;
	}
}
template <class T>
void List<T>::print()
{
	if(start==NULL)
		return;
	Node<T>* node=start;
	do{
		cout<<node->data<<std::endl;
		node = node->next;

	}while(node);
}
template <class T>
void List<T>::printrev()
{
	printrev(start);
}

template <class T>
void List<T>::printrev(Node<T>* node)
{
	if(node->next != NULL)
	printrev(node->next);
	cout<<node->data<<std::endl;
}
template <class T>
void List<T>::printrevN(int n)
{
	Node<T>* p1=start;
	Node<T>* p2=start;
	for(int i=0;i<n;i++)
		p1 = p1->next;
	while(p1->next != NULL)
	{
		p1 = p1->next;
		p2=p2->next;
	}
	cout<<n<<"th node:"<<p2->data<<endl;
}

int main()
{
	List<int> list;
	for(int i=1;i<=10;i++)
	{
		list.addNode(i);
	}
	//list.print();
	//list.printrev();
	list.printrevN(0);
}
	
