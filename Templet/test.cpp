/*
#include<iostream>
using namespace std;
template <class T>//T Ϊ�β����������ض�����������
//class ��дΪtypename
//ģ��һ��ʹ�����ô��Σ��ɱ��⿽���������⣨��TΪ�ַ�������ȣ�
void Swap(T& a,T& b)//�����ʵ�����ͽ��в���
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
	//Swap(a,c1);//����ͬһģ�壬ʵ����������ͬ
	double n=3.1;
	IsEqual<double>(a,n);//ʹ����ʾʵ����ָ��Ϊ double���ͣ����������ת����
	system("pause");
	return 0;
}

*/
/*
#pragma once
#include<iostream>
using namespace std;

template <class T>
//˳���
class Seqlist
{
public:
	Seqlist()//���캯����
		:_data(NULL)//��ʼ���б�
		,_size(0)
		,_nsize(0)
	{
	}
	//Seqlist();//��������
	void Seq_has()//����
	{
		if(_size >= _nsize)//����
			_nsize= _nsize>0 ? _nsize*2 : 3;//��һ�ο���3���ռ䣬֮�󿪱ٶ���
		 T* newsize = new T[_nsize];//ʹ��new���ٿռ䣨���������ٿռ䣩(T*���ͱ���)
		 if(_data)
		 {
			 memcpy(newsize,_data,sizeof(T)*_nsize);//���ݸ���
			 delete(_data);//�ͷ�ԭ�пռ�
	     }
		 _data=newsize;//ָ���¿ռ�
	}
	void Push_Back(const T& data)
	{
		Seq_has();
		_data[_size]=data;
		_nsize++;
	}

	~Seqlist()//��������
	{
		if(_data)
			delete(_data);//����malloc���ٿռ�
	}

protected:
		T * _data;
		size_t _size;
		size_t _nsize;
};

//template <class T>
//Seqlist<T>::Seqlist()//���⹹�캯����(��ָ�����Ǹ��࣬��ͬ�������Ͷ�Ӧ��ͬ���࣬���Ի���ģ�����)
//	:_data(NULL)//��ʼ���б�
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

//T ����ģ�����
//N �����͵�ģ�����--����  Nֻ��Ϊint��char���Ͳ���������Ϊ�����ͺ�string����
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
     friend ostream&operator<<(ostream& out ,const Data& d);//��Ԫ

private:
	int year;
	int month;
	int data;
};

ostream&operator<<(ostream& out ,const Data& d)//�������
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
