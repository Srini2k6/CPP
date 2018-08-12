#include<iostream>
#include<string>

template<class T>
class Test
{
        public:
        int n;
        T* m_ptr;
        Test();
        Test(const Test<T>&);
        const Test<T>& operator=(const Test&);
        ~Test();
};

template<class T>
Test<T>::Test()
{
        std::cout<<"Constroctor"<<std::endl;
        n=0;
        m_ptr=NULL;
}

template< class T>
Test<T>::Test(const Test<T>& test )
{
        std::cout<<"Copy Constroctor"<<std::endl;
        this->n = test.n;
        this->m_ptr= new T[n];
        for(int i=0;i<n;i++)
        {
                *(this->m_ptr+i) = *(test.m_ptr+i);
        }
}

template<class T>
const Test<T>& Test<T>::operator=(const Test<T>& test)
{
        std::cout<<"Operator ="<<std::endl;
        this->n = test.n;
        this->m_ptr=test.m_ptr;
        return *this;
}

template<class T>
Test<T>::~Test()
{
        std::cout<<"Destroctor"<<std::endl;
        delete [] this->m_ptr;

}

class A
{
        public:
        int a;
        A(){a=10;}
};

int main()
{
        Test<A> t1;
        t1.n=10;
        t1.m_ptr=new A[10];
        Test<A> t2(t1);
        std::cout<<t2.n<<std::endl;
        Test<A> t3;
        t3=t1;
        std::cout<<t3.n<<std::endl;
}
