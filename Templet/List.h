#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template <class T>

//带头-----循环链表  （第一个节点有数据）
//不带头---双向链表  （第一个节点无数据）
struct ListNode //在C++中struct相当于定义一个类
{
	T _data ;
	ListNode<T>* _Next;//与C不同，无struct
	ListNode<T>* _prev;

	ListNode(const T& x)//拷贝构造 （创建节点）
		:_data(x)
		,_Next(NULL)
		,_prev(NULL)
	{}
};

template<class T>
class List
{
	typedef ListNode<T> Node;//重定义类型名（之后Node代表ListNode）
public:
	List()//构造函数，初始化
		:_head(new Node(T()))//创建头节点 T()缺省类型参数（即无类型参数）
	{
		_head->_prev=_head;
		_head->_Next=_head;
	}

	List(const List<T>& list)//拷贝构造
		:_head(new Node(T()))//创建新头节点
	{
		_head->_Next=_head;
		_head->_prev=_head;
		//至此新链表头节点构造完成
		Node * ptemp=list._head->_Next;//从原链表的非头节点开始复制
		while(ptemp != list._head)
		{
			this->Push_Back(ptemp->_data);//将数据赋值给新链表节点(this即表示对应的新对象的节点)
			ptemp=ptemp->_Next;
		}
	}
	List<T>& operator=(List<T>list)//重载
	{
		swap(_head,list._data);
		return *this;
	}

	~List()//析构
	{
		List_clear();
		delete _head;//删除头节点
		_head=NULL;
	}
	void List_clear()//清空链表（不清空头节点）
	{
		Node * ptemp=_head->_Next;
		Node * del=NULL;
		while(ptemp != _head)
		{
			del=ptemp;
			ptemp=ptemp->_Next;
			delete del;
		}
		_head->_Next=_head;//重行让头节点指向自己
		_head->_prev=_head;
	}

	void Push_Back(const T& data)//尾插
	{
		assert(_head);
		Node * ptail=_head->_prev;//指向尾节点
		Node * nlist=new Node(data);//创建新节点(自动调用拷贝构造)，数据data
		
		ptail->_Next=nlist;
		nlist->_prev=ptail;

		nlist->_Next=_head;
		_head->_prev=nlist;
	}

	void Push_Pop(Node * pos)//删除数据(pos位置)
	{
		if(!pos && pos !=_head)//不可删头
		{
			cout << "no find"<<endl;
			return ;
		}
		pos->_prev->_Next=pos->_Next;
		pos->_Next->_prev=pos->_prev;

		delete (pos);
	}

	Node* List_Faid(const T& data)//查找
	{
		assert(_head);
		Node * ptemp=_head->_Next;
		while(ptemp != _head)
		{
			if(ptemp->_data == data)
				return ptemp;
			ptemp=ptemp->_Next;
		}
		return NULL;
	}

	void List_push(Node * pos,const T& data)//pos位置插入数据
	{
        if(!pos && pos != _head)
		{
			cout << "no pos!"<<endl;
			return ;
		}
		Node * pnew= new Node(data);//新节点
		pos->_prev->_Next=pnew;
		pnew->_prev=pos->_prev;

		pnew->_Next=pos;
		pos->_prev=pnew;
	}

	void List_print()//输出
	{
		assert(_head);
		Node * ptemp=_head->_Next;
		while(ptemp != _head)
		{
			cout << ptemp->_data <<"->";
			ptemp=ptemp->_Next;
		}
		cout << "NULL"<<endl;
	}

private:
	Node * _head;
};

void List_tlest(void)
{
	List<int> list;

	list.Push_Back(1);
	list.Push_Back(2);
	list.Push_Back(3);
	list.List_print();

	cout << list.List_Faid(2) << endl;;
	list.Push_Pop(list.List_Faid(1));
	list.Push_Pop(list.List_Faid(3));
	list.List_print();

	list.List_push(list.List_Faid(2),3);
	list.List_print();

	List<int>list2(list);
	list2.List_print();
	list.List_print();

	list2.List_clear();
	list2.Push_Back(5);
	list2.List_print();
}
