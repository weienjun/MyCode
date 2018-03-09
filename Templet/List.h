#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template <class T>

//��ͷ-----ѭ������  ����һ���ڵ������ݣ�
//����ͷ---˫������  ����һ���ڵ������ݣ�
struct ListNode //��C++��struct�൱�ڶ���һ����
{
	T _data ;
	ListNode<T>* _Next;//��C��ͬ����struct
	ListNode<T>* _prev;

	ListNode(const T& x)//�������� �������ڵ㣩
		:_data(x)
		,_Next(NULL)
		,_prev(NULL)
	{}
};

template<class T>
class List
{
	typedef ListNode<T> Node;//�ض�����������֮��Node����ListNode��
public:
	List()//���캯������ʼ��
		:_head(new Node(T()))//����ͷ�ڵ� T()ȱʡ���Ͳ������������Ͳ�����
	{
		_head->_prev=_head;
		_head->_Next=_head;
	}

	List(const List<T>& list)//��������
		:_head(new Node(T()))//������ͷ�ڵ�
	{
		_head->_Next=_head;
		_head->_prev=_head;
		//����������ͷ�ڵ㹹�����
		Node * ptemp=list._head->_Next;//��ԭ����ķ�ͷ�ڵ㿪ʼ����
		while(ptemp != list._head)
		{
			this->Push_Back(ptemp->_data);//�����ݸ�ֵ��������ڵ�(this����ʾ��Ӧ���¶���Ľڵ�)
			ptemp=ptemp->_Next;
		}
	}
	List<T>& operator=(List<T>list)//����
	{
		swap(_head,list._data);
		return *this;
	}

	~List()//����
	{
		List_clear();
		delete _head;//ɾ��ͷ�ڵ�
		_head=NULL;
	}
	void List_clear()//������������ͷ�ڵ㣩
	{
		Node * ptemp=_head->_Next;
		Node * del=NULL;
		while(ptemp != _head)
		{
			del=ptemp;
			ptemp=ptemp->_Next;
			delete del;
		}
		_head->_Next=_head;//������ͷ�ڵ�ָ���Լ�
		_head->_prev=_head;
	}

	void Push_Back(const T& data)//β��
	{
		assert(_head);
		Node * ptail=_head->_prev;//ָ��β�ڵ�
		Node * nlist=new Node(data);//�����½ڵ�(�Զ����ÿ�������)������data
		
		ptail->_Next=nlist;
		nlist->_prev=ptail;

		nlist->_Next=_head;
		_head->_prev=nlist;
	}

	void Push_Pop(Node * pos)//ɾ������(posλ��)
	{
		if(!pos && pos !=_head)//����ɾͷ
		{
			cout << "no find"<<endl;
			return ;
		}
		pos->_prev->_Next=pos->_Next;
		pos->_Next->_prev=pos->_prev;

		delete (pos);
	}

	Node* List_Faid(const T& data)//����
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

	void List_push(Node * pos,const T& data)//posλ�ò�������
	{
        if(!pos && pos != _head)
		{
			cout << "no pos!"<<endl;
			return ;
		}
		Node * pnew= new Node(data);//�½ڵ�
		pos->_prev->_Next=pnew;
		pnew->_prev=pos->_prev;

		pnew->_Next=pos;
		pos->_prev=pnew;
	}

	void List_print()//���
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
