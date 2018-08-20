#include<iostream>
using namespace std;

class RefCount
{
	private:
	int count;
	public:
	RefCount()
	{
		count=1;
	}
	void addCount()
	{
		count++;
	}
	int decCount()
	{
		return --count;
	}

};
template <class T>
class SmartPointer
{
	private:
		T *data;
		RefCount * rc;
	public:
		SmartPointer(T* t):data(t),rc(new RefCount()){}
		SmartPointer(const SmartPointer& sp)
		{
			this->data = sp.data;
			this->rc= sp.rc;
			rc=>addConut();
		}
		SmartPointer operator=(const SmartPointer& sp)
		{
			if(decCount()==0)
			{
				delete data;
				delete rc;
			}
			data=sp.data;
			rc=sp.rc;
		}
	

}
