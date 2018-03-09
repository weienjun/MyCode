/*
#include<iostream>
using namespace std;
template <class T>//T 为形参名（类似重定义类型名）
//class 可写为typename
//模板一般使用引用传参，可避免拷贝构造问题（如T为字符串问题等）
void Swap(T& a,T& b)//会根据实参类型进行操作
{
	T c;
	c=a;
	a=b;
	b=c;
}

template <typename Tp>

int IsEqual(const Tp& num1,const Tp& num2)
{
	cout << ((num1>num2) ? num1:num2)<<endl;
	return num1>num2;
}

int main()
{
	int a=1;
	int b=2;
	Swap(a,b);
	cout << a<<"\n"<<b<<endl;
	char c1='a';
	char c2='b';
	Swap(c1,c2);
	cout << c1<<'\n'<<c2<<endl;
	//Swap(a,c1);//错误，同一模板，实参类型需相同
	double n=3.1;
	IsEqual<double>(a,n);//使用显示实例化指定为 double类型（会进行类型转化）
	system("pause");
	return 0;
}

*/
/*
#pragma once
#include<iostream>
using namespace std;

template <class T>
//顺序表
class Seqlist
{
public:
	Seqlist()//构造函数数
		:_data(NULL)//初始化列表
		,_size(0)
		,_nsize(0)
	{
	}
	//Seqlist();//类内声明
	void Seq_has()//扩容
	{
		if(_size >= _nsize)//已满
			_nsize= _nsize>0 ? _nsize*2 : 3;//第一次开辟3个空间，之后开辟二倍
		 T* newsize = new T[_nsize];//使用new开辟空间（按个数开辟空间）(T*类型变量)
		 if(_data)
		 {
			 memcpy(newsize,_data,sizeof(T)*_nsize);//数据复制
			 delete(_data);//释放原有空间
	     }
		 _data=newsize;//指向新空间
	}
	void Push_Back(const T& data)
	{
		Seq_has();
		_data[_size]=data;
		_nsize++;
	}

	~Seqlist()//析构函数
	{
		if(_data)
			delete(_data);//采用malloc开辟空间
	}

protected:
		T * _data;
		size_t _size;
		size_t _nsize;
};

//template <class T>
//Seqlist<T>::Seqlist()//类外构造函数数(需指明是那个类，不同参数类型对应不同的类，所以还需模板操作)
//	:_data(NULL)//初始化列表
//	,_size(0)
//	,_nsize(0)
//{
//}


//#include<iostream>
//#include"Seqlist.h"
//using namespace std;



int main()
{
    Seqlist<int>  list_1;
	Seqlist<char> list_2;
	list_1.Push_Back(1);

	system("pause");
	return 0;
}

*/

#include<iostream>
#include<string>

using namespace std;

//T 类型模板参数
//N 非类型的模板参数--常量  N只能为int，char类型参数，不可为浮点型和string类型
template<class T,size_t N>

class Array
{
public :
	Array()
		:_size(0)
	{}
	void Push_Back(const T& x)
	{
		if(_size >= N)
		{
			cout << "full"<<endl;
			return ;
		}
		_data[_size++]=x;
	}
	void print()
	{
		for(size_t i=0;i<_size;i++)
			cout <<_data[i];
		cout<<endl;
	}
private:
	T _data[N];
	size_t _size;
};

/*
class Data
{
     friend ostream&operator<<(ostream& out ,const Data& d);//友元

private:
	int year;
	int month;
	int data;
};

ostream&operator<<(ostream& out ,const Data& d)//重载输出
{
	out <<d.data<<" ";
	return out ;
} 

*/

////void test(void)
////{
////	Array<int,10> a1;
////	Array<char*,20> a2;
////	char arr[]={"345666632"};
////	a1.Push_Back(1233);
////	a2.Push_Back(arr);
////	a1.print();
////	a2.print();
////}
////
