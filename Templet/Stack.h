
#pragma once
#include"Seqlist.h"
#include"List.h"
//������---��������ת���������
//template <class T,class Container>//ģ��
template <class T,class Container = Seqlist<T>>//ģ��,ȱʡֵ
//template<class T,template<class> class Container = Seqlist>//ģ���ģ�����
class Stack//ջ�ṹ��
{
public:
    void Push(const T& x)//xѹջ
	{
		_con.Puch_Back(x);
	}

	void Pop()//��ջ
	{
		_con.Seq_Delete(_con.Back);//ɾ��ջ��Ԫ��
	}

	T& Top()//ȡջ��
	{
		return _con.Back;
	}
	size_t Size()
	{
		return _con.Size;
	}
	bool Empty()//�п�
	{
		return _con.Empty();
	}
private:
	Container _con;//���͸���Conterģ��ȷ��
	//Container<T> _con
};

//template <class T,class Container>//ģ��

//void Stack_Test()
//{
//	Stack<int,Seqlist<int>>s1;
//	//stack.Push(1);
//	//stack.Top();
//}
