#include<iostream>
using namespace std;

void test()
{
 	int a1;
	int &a2=a1;//引用变量a
	a1=10;//对引用变量赋值，原变量值也会改变
	cout << a1 << endl;
	a1=48;
	cout << a1 << endl;//原变量与引用变量的值一直保持同步（相同）
	cout << &a1 << endl;//地址相同
	cout << &a2 << endl;

	int& b = a2 ;//多重引用，b引用a2，a2引用a1（所有值同步，地址相同）
	cout << "b=" << b <<" &b=" << &b << endl;
	b=49;
	cout << "a1=" << a1 <<" &a=" << &a1 << endl;
	a1=50;
	cout << "b=" << b << endl;

	const int c1=6;
	//int& c2 = c1;//错误，const修饰原变量，引用也必须加const修饰，否则不合法（原变量不可变，则都应不可变）
	const int c2=c1;
	
	int d1 = 7;
	const int& d2 = d1;
	d1=8;//d2为const修饰不可变，但与d1不保持同步
	//d2=7;//错误，const修饰的变量，则变量不可变
	cout << "d1="<<d1 << endl;//8
	cout << "d2="<<d2 << endl;//8

	a2 = d1;//仅获取d1的值，但地址不变，a2依旧是a1的别名，即引用变量一旦继承了那个变量的别名，则就不可再改变成其它变量的别名。
	cout <<"a2=" << a2 << endl;
	cout << "a1=" << a1 << endl;
	cout << "d1=" << d1 << endl;
	cout << "&a1=" << &a1 << endl;
	cout << "&a2=" << &a2 << endl;
	cout << "&ad1=" << &d1 << endl;


	//char& ch = a;//错误，引用与原变量类型不同，存在隐式类型转换，需使用const修饰
	const char& ch = a1;//ch引用的为类型转换时产生的临时变量（具有常性），所以需加const修饰
	cout << ch << endl;  
	cout << &a1 << endl;
	cout << &ch << endl;
}
int& Add(const int& num1,const int& num2)//引用传参（形参只是实参的别名，不产生临时拷贝），引用返回值
{
	int num=num1+num2;
	return num;//函数退出时，num被销毁（数值通过寄存器返回），返回的是一个临时对象
}

void Swap(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void test1()
{
	int* p=0;
	int& a = *p;
	int b = 2 ;
	Swap(a,b);
}

int main()
{
	//int n=0;
	//test();
	int& n=Add(1,2);//n引用的为 返回值num的别名，num在退出函数时被销毁
	Add(2,2);
	cout << n << endl;//打印引用的值 4
	//cout << Add(0,1) << endl;//调用函数
	cout << n << endl;//num在退出函数时被销毁，越界访问,随机值 
	test1();//程序崩溃
	system("pause");
	return 0;
}