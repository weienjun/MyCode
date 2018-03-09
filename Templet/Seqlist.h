#pragma once
#include<iostream>
#include<string>
//#include"Copy.h"
using namespace std;

template <class T>
//˳���
//���� Seqlist
//���� Seqlist <T>
class Seqlist
{
public:
	Seqlist()//���캯����
		:_data(NULL)//��ʼ���б�
		,_size(0)
		,_nsize(0)//����д_nsize=0
	{}
	//��������¿����ڴ�ռ䣬�����ݷ��뵽�¿ռ���ȥ
	//ǳ�����������¿��ٿռ䣬ֻ��ָ��ָ��ͬһ����ַ����ֱ�Ӹ�ֵ��
	Seqlist(const Seqlist<T> &list)//��������(������list����ֵ�����¶���)
	{    
		_data=new T[list._size];//����������֪���� ����� T*
		for(size_t i=0;i<list._size;i++)
		{
			_data[i]=list._data[i];
		}
		_size=list._size;
		_nsize=list._nsize;

	}
	Seqlist<T>&operator=(Seqlist<T> S)//�������ط���ʵ��
	{
		swap(_data,S._data);
		swap(_size,S._size);
		swap(_nsize,S._nsize);
	}
	//Seqlist();//��������
	void Seq_has()//����
	{
		if(_size >= _nsize)//����
			_nsize= _nsize>0 ? _nsize*2 : 3;//��һ�ο���3���ռ䣬֮�󿪱ٶ���
		 T * newsize = new T[_nsize];//ʹ��new���ٿռ䣨���������ٿռ䣩(T*���ͱ���)
		 if(_data)//������
		 {
			 //string �Զ������ͣ���һ������˳������͵��ࣩ��28/32�����ַ�<16�洢ջbuf�����У��ѣ����ַ�>=16 ���ڶ��ϣ�ptrָ��ÿռ�
			//memcpy(newsize,_data,sizeof(T)*_nsize);//���ݸ���,����(Ϊstring����ʱ����ָ��ָ��ͬһ�ռ䣬���ͷſռ�ʱ���ַ�>16�ͻᵼ�����ݶ�ʧ)
			 for(size_t i=0; i< _size ; i++)
			 {
				 newsize[i]=_data[i];
			 }
			 /*
			 	__TypeCopy(newsize,list._data,list._size);/  /ʹ����ȡ����
			 */
            delete []_data;//�ͷ����пռ�([]_data�д�ŵ��������ٵ��ڴ��С)
		 }
		 //delete []_data;//�ͷ�ԭ�пռ�
		 _data=newsize;//ָ���¿ռ�
	}
	void Push_Back(const T& data)
	{
		Seq_has();
		_data[_size]=data;
		_size++;
	}
	T& Back()//���β����
	{
		assert(_szie >0);
		return _data[_size-1];
	}
	size_t Size()//��С
	{
		return _size;
	}
	void Seq_Delete(const T& data)//ɾ��
	{
		int temp=Seq_Search(data);
		if((int)temp < 0 )//ǿת�ж��Ƿ��ҵ�
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

	size_t Seq_Search(const T& data)//����
	{
	for(size_t i=0;i<_size;i++)
	{
		if(_data[i] == data)
			return i;
	}
	return -1;
}
	void Seq_add(const T& data1,const T& data2)//ָ��λ�ò���
	{
		int i=0;
		int temp=Seq_Search(data1);
		if((int)temp < 0 )//ǿת�ж��Ƿ��ҵ�
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

	void Seq_print(void)//���
	{
		for(size_t i=0;i < _size;i++)
			cout << _data[i] << endl;
	}

	bool Empty()//�п�
	{
		rteurn _size==0;
	}
	~Seqlist()//��������
	{
		if(_data)
			delete []_data;//�ͷŲ���new���ٿռ�
	}

protected:
		T * _data;
		size_t _size;
		size_t _nsize;
};



void Seqlist_test(void)//���Ժ���
{
	 Seqlist<int>  list_1;//����
	
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
	//����strig(�Զ�������)�е�ptrָ��ͬһ���ڴ�ռ䣬��������ʱ���ͬһ�ڴ�ռ���ж���ͷŵ��´����ַ�>16��ʹ��ptr��
	//���Զ���string(�Զ�������)Ӧ�Լ�д�������캯��
	Seqlist<string>list_4(list_3);//���������ÿ������죩
	list_4.Seq_print();

	int data=0;
	cout <<"put search data :";
	cin >> data ;
	cout << list_1.Seq_Search(data)<<endl;//����

	cout <<"put delete data : ";
	cin >> data ;
	list_1.Seq_Delete(data);//ɾ��
	list_1.Seq_print();

	list_1.Seq_add(1,2);//ָ��λ�ò���
	list_1.Seq_print();
}



/*

template<class T>
size_t Seqlist<T>::Seq_Search(const T& data)//����(��ָ���Ǹ��ࣨ��������֮��)
{
	for(int i=0;i<_size;i++)
	{
		if(_data[i] == data)
			return i;
	}
	return -1;
}

template<class T>
void Seqlist<T>::Seq_Delete(const T& data)//ɾ��
{
	int temp=Seq_Search(data);
	if((int)temp < 0 )//ǿת�ж��Ƿ��ҵ�
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
void Seqlist<T>::Seq_add(const T& data1,const T& data2)//ָ��λ�ò���
{
	int i=0;
	int temp=Seq_Search(data1);
	if((int)temp < 0 )//ǿת�ж��Ƿ��ҵ�
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
//Seqlist<T>::Seqlist()//���⹹�캯����(��ָ�����Ǹ��࣬��ͬ�������Ͷ�Ӧ��ͬ���࣬���Ի���ģ�����)
//	:_data(NULL)//��ʼ���б�
//	,_size(0)
//	,_nsize(0)
//{
//}
