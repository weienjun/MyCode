
#pragma once
#include"Seqlist.h"
#include"List.h"
//适配器---其它容器转换适配出来
//template <class T,class Container>//模板
template <class T,class Container = Seqlist<T>>//模板,缺省值
//template<class T,template<class> class Container = Seqlist>//模板的模板参数
class Stack//栈结构类
{
public:
    void Push(const T& x)//x压栈
	{
		_con.Puch_Back(x);
	}

	void Pop()//出栈
	{
		_con.Seq_Delete(_con.Back);//删除栈顶元素
	}

	T& Top()//取栈顶
	{
		return _con.Back;
	}
	size_t Size()
	{
		return _con.Size;
	}
	bool Empty()//判空
	{
		return _con.Empty();
	}
private:
	Container _con;//类型根据Conter模板确定
	//Container<T> _con
};

//template <class T,class Container>//模板

//void Stack_Test()
//{
//	Stack<int,Seqlist<int>>s1;
//	//stack.Push(1);
//	//stack.Top();
//}
