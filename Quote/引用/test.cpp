#include<iostream>
using namespace std;

void test()
{
 	int a1;
	int &a2=a1;//���ñ���a
	a1=10;//�����ñ�����ֵ��ԭ����ֵҲ��ı�
	cout << a1 << endl;
	a1=48;
	cout << a1 << endl;//ԭ���������ñ�����ֵһֱ����ͬ������ͬ��
	cout << &a1 << endl;//��ַ��ͬ
	cout << &a2 << endl;

	int& b = a2 ;//�������ã�b����a2��a2����a1������ֵͬ������ַ��ͬ��
	cout << "b=" << b <<" &b=" << &b << endl;
	b=49;
	cout << "a1=" << a1 <<" &a=" << &a1 << endl;
	a1=50;
	cout << "b=" << b << endl;

	const int c1=6;
	//int& c2 = c1;//����const����ԭ����������Ҳ�����const���Σ����򲻺Ϸ���ԭ�������ɱ䣬��Ӧ���ɱ䣩
	const int c2=c1;
	
	int d1 = 7;
	const int& d2 = d1;
	d1=8;//d2Ϊconst���β��ɱ䣬����d1������ͬ��
	//d2=7;//����const���εı�������������ɱ�
	cout << "d1="<<d1 << endl;//8
	cout << "d2="<<d2 << endl;//8

	a2 = d1;//����ȡd1��ֵ������ַ���䣬a2������a1�ı����������ñ���һ���̳����Ǹ������ı�������Ͳ����ٸı�����������ı�����
	cout <<"a2=" << a2 << endl;
	cout << "a1=" << a1 << endl;
	cout << "d1=" << d1 << endl;
	cout << "&a1=" << &a1 << endl;
	cout << "&a2=" << &a2 << endl;
	cout << "&ad1=" << &d1 << endl;


	//char& ch = a;//����������ԭ�������Ͳ�ͬ��������ʽ����ת������ʹ��const����
	const char& ch = a1;//ch���õ�Ϊ����ת��ʱ��������ʱ���������г��ԣ����������const����
	cout << ch << endl;  
	cout << &a1 << endl;
	cout << &ch << endl;
}
int& Add(const int& num1,const int& num2)//���ô��Σ��β�ֻ��ʵ�εı�������������ʱ�����������÷���ֵ
{
	int num=num1+num2;
	return num;//�����˳�ʱ��num�����٣���ֵͨ���Ĵ������أ������ص���һ����ʱ����
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
	int& n=Add(1,2);//n���õ�Ϊ ����ֵnum�ı�����num���˳�����ʱ������
	Add(2,2);
	cout << n << endl;//��ӡ���õ�ֵ 4
	//cout << Add(0,1) << endl;//���ú���
	cout << n << endl;//num���˳�����ʱ�����٣�Խ�����,���ֵ 
	test1();//�������
	system("pause");
	return 0;
}