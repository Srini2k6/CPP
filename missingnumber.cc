#include<iostream>
using namespace std;

int find(int n,int arr[])
{
	int total=n*(n+1)/2;
	cout<<"Total="<<total<<endl;
	for(int i=0;i<n-1;i++)
	{
		total-=arr[i];
		cout<<"Total:"<<total<<endl;
	}
	return total;
}

int main()
{
	int arr[]={1,2,3,4,5,7,8,9,10};
	cout<<"Missing:"<<find(10,arr)<<endl;

}
