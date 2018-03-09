#include<iostream>
#include<string>
#include"Seqlist.h"
#include"Stack.h"
#include"List.h"
#include"test.cpp"
#include"Copy.h"
using namespace std;

void List_tlest(void);


//void List_test(void);

void test(void)
{
	Array<int,10> a1;
	Array<char*,20> a2;
	char arr[]="345666111";
	a1.Push_Back(1233);
	a2.Push_Back(arr);
	a1.print();
	a2.print();
}

void test_copy(void)
{
	int a1[]={1,2,3};
	int a2[]={4,5,6};
    __TypeCopy(a1,a2,3);
	cout << a1[0] <<endl;

	char c1='a';
	char c2='b';
	__TypeCopy(&c1,&c2,1);
	cout << c1 << endl;
	
	string s1[]={"123","456","789"};
	string s2[]={"456","369","987"};
	__TypeCopy(s1,s2,3);//3表示个数
	cout << s1[0] <<endl;
	cout << s1[1] <<endl;
	cout << s1[2] <<endl;

}


int main(void)
{
	//Seqlist_test();//测试函数
	List_tlest();

	//Stack<int,Seqlist<int>> s1;
	//Stack<int,Seqlist> s1;

   // Stack_Test();
/*
	char bufr[5];
	//bufr[0]=-80;
	//bufr[1]=-82;
	bufr[2]=-62;
	bufr[3]=-30;
	bufr[4]=0;
	cout <<bufr<<endl;
    test();
   
	test_copy();
*/
	system("pause");
	return 0;
}


/*
void List_test(void)
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

*/