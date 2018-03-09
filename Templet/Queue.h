#pragma once
#include"Seqlist.h"
#include"List.h"

template<class T,class Container>
class Queue
{
public :
	void Puch(const T& x)
	{
		_con.Puch_Back(x);
	}

	void PopFront()
	{
		
	}
	void Front()//ͷ
	{
	}
private :
	Container _con;
};