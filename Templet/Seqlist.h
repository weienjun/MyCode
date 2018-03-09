#pragma once
#include<iostream>
#include<string>
//#include"Copy.h"
using namespace std;

template <class T>
//顺序表
//类名 Seqlist
//类型 Seqlist <T>
class Seqlist
{
public:
	Seqlist()//构造函数数
		:_data(NULL)//初始化列表
		,_size(0)
		,_nsize(0)//不可写_nsize=0
	{}
	//深拷贝：重新开辟内存空间，将数据放入到新空间中去
	//浅拷贝：不重新开辟空间，只让指针指向到同一个地址（或直接赋值）
	Seqlist(const Seqlist<T> &list)//拷贝构造(将对象list中数值赋给新对象)
	{    
		_data=new T[list._size];//拷贝构造已知类型 不需加 T*
		for(size_t i=0;i<list._size;i++)
		{
			_data[i]=list._data[i];
		}
		_size=list._size;
		_nsize=list._nsize;

	}
	Seqlist<T>&operator=(Seqlist<T> S)//根据重载方法实现
	{
		swap(_data,S._data);
		swap(_size,S._size);
		swap(_nsize,S._nsize);
	}
	//Seqlist();//类内声明
	void Seq_has()//扩容
	{
		if(_size >= _nsize)//已满
			_nsize= _nsize>0 ? _nsize*2 : 3;//第一次开辟3个空间，之后开辟二倍
		 T * newsize = new T[_nsize];//使用new开辟空间（按个数开辟空间）(T*类型变量)
		 if(_data)//有数据
		 {
			 //string 自定义类型（是一个类似顺序表类型的类）（28/32）：字符<16存储栈buf数组中（堆），字符>=16 存在堆上，ptr指向该空间
			//memcpy(newsize,_data,sizeof(T)*_nsize);//数据复制,错误(为string类型时两个指针指向同一空间，当释放空间时若字符>16就会导致数据丢失)
			 for(size_t i=0; i< _size ; i++)
			 {
				 newsize[i]=_data[i];
			 }
			 /*
			 	__TypeCopy(newsize,list._data,list._size);/  /使用萃取拷贝
			 */
            delete []_data;//释放所有空间([]_data中存放的是所开辟的内存大小)
		 }
		 //delete []_data;//释放原有空间
		 _data=newsize;//指向新空间
	}
	void Push_Back(const T& data)
	{
		Seq_has();
		_data[_size]=data;
		_size++;
	}
	T& Back()//输出尾数据
	{
		assert(_szie >0);
		return _data[_size-1];
	}
	size_t Size()//大小
	{
		return _size;
	}
	void Seq_Delete(const T& data)//删除
	{
		int temp=Seq_Search(data);
		if((int)temp < 0 )//强转判断是否找到
		{
			cout << "NO data!"<<endl;
			return ;
		}
		for(size_t i=temp;i< _size;i++)
		{
			_data[i]=_data[i+1];
		}
		_size--;
    }

	size_t Seq_Search(const T& data)//查找
	{
	for(size_t i=0;i<_size;i++)
	{
		if(_data[i] == data)
			return i;
	}
	return -1;
}
	void Seq_add(const T& data1,const T& data2)//指定位置插入
	{
		int i=0;
		int temp=Seq_Search(data1);
		if((int)temp < 0 )//强转判断是否找到
		{
			cout << "NO data1!"<<endl;
			return ;
		}
		Seq_has();
		for(i=_size;i > temp;i--)
		{
			_data[i]=_data[i-1];
		}
		_data[i]=data2;
		_size++;
    }

	void Seq_print(void)//输出
	{
		for(size_t i=0;i < _size;i++)
			cout << _data[i] << endl;
	}

	bool Empty()//判空
	{
		rteurn _size==0;
	}
	~Seqlist()//析构函数
	{
		if(_data)
			delete []_data;//释放采用new开辟空间
	}

protected:
		T * _data;
		size_t _size;
		size_t _nsize;
};



void Seqlist_test(void)//测试函数
{
	 Seqlist<int>  list_1;//对象
	
	list_1.Push_Back(1);
	list_1.Push_Back(2);
	list_1.Push_Back(3);
	list_1.Seq_print();

	Seqlist<char> list_2;
	list_2.Push_Back('a');
	list_2.Push_Back('b');
	list_2.Push_Back('c');
	list_2.Seq_print();
	
	Seqlist<string> list_3;
	list_3.Push_Back("ab");
	list_3.Push_Back("12");
	list_3.Push_Back("1211111111111111111111111111111111111111");
	list_3.Push_Back("1211111111111111111111111111111111111111");
	list_3.Push_Back("1211111111111111111111111111111111111111");
	list_3.Push_Back("AB");
	list_3.Push_Back("AB");
	list_3.Push_Back("AB");
	list_3.Seq_print();
	//由于strig(自定义类型)中的ptr指向同一块内存空间，所以析构时会对同一内存空间进行多次释放导致错误（字符>16会使用ptr）
	//所以对于string(自定义类型)应自己写拷贝构造函数
	Seqlist<string>list_4(list_3);//拷贝（调用拷贝构造）
	list_4.Seq_print();

	int data=0;
	cout <<"put search data :";
	cin >> data ;
	cout << list_1.Seq_Search(data)<<endl;//查找

	cout <<"put delete data : ";
	cin >> data ;
	list_1.Seq_Delete(data);//删除
	list_1.Seq_print();

	list_1.Seq_add(1,2);//指定位置插入
	list_1.Seq_print();
}



/*

template<class T>
size_t Seqlist<T>::Seq_Search(const T& data)//查找(需指明那个类（返回类型之后）)
{
	for(int i=0;i<_size;i++)
	{
		if(_data[i] == data)
			return i;
	}
	return -1;
}

template<class T>
void Seqlist<T>::Seq_Delete(const T& data)//删除
{
	int temp=Seq_Search(data);
	if((int)temp < 0 )//强转判断是否找到
	{
		cout << "NO data!"<<endl;
		return ;
	}
	for(int i=temp;i< _size;i++)
	{
		_data[i]=_data[i+1];
	}
	_size--;
}

template <class T>
void Seqlist<T>::Seq_add(const T& data1,const T& data2)//指定位置插入
{
	int i=0;
	int temp=Seq_Search(data1);
	if((int)temp < 0 )//强转判断是否找到
	{
		cout << "NO data1!"<<endl;
		return ;
	}
	Seq_has();
	for(i=_size;i > temp;i--)
	{
		_data[i]=_data[i-1];
	}
	_data[i]=data2;
	_size++;
}

*/
//template <class T>
//Seqlist<T>::Seqlist()//类外构造函数数(需指明是那个类，不同参数类型对应不同的类，所以还需模板操作)
//	:_data(NULL)//初始化列表
//	,_size(0)
//	,_nsize(0)
//{
//}
