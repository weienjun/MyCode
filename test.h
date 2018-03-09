#pragma once
#include<iostream>
using namespace std;

namespace AA//命名空间AA
{
	int a = 10;
}
int add(int a ,int b = 3)
{
	return a + b;
}

int add2(int a = 1 ,int b = 30)
{
	return a + b;
}
int add3(int a ,int b = 2,int c = 3)
{
	return a + b + c;
}
int a = 20;//全局变量
void test()
{
	int a = 10;
	int b = 20;

	cout <<"a = " << a << endl;//局部
	cout << "::a=" << ::a << endl;//全局
	cout << "AA::a=" << AA::a << endl;//命名空间

	cout.unsetf(ios::dec);//终止十进制格式设置
	cout.setf(ios::hex);//输出设置成十六进制
	cout << a << endl;
	//注：设置仅用于当前函数,包括所调用的函数
	//也可用类似方法设置精度及其它输出格式
	cout.unsetf(ios::hex);//终止十六进制格式设置
	cout << a << endl;

	cout << add(1,2) << endl;//不缺省，使用实参运算
	cout << add(1) << endl;//半缺省，使用缺省形参
	cout << add2() << endl;//全缺省，使用形参
	cout << add3(1) << endl; //缺省，只能从左向右连续缺省，不可间断缺省 

}