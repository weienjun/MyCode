#pragma once
#include<iostream>
using namespace std;

namespace AA//�����ռ�AA
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
int a = 20;//ȫ�ֱ���
void test()
{
	int a = 10;
	int b = 20;

	cout <<"a = " << a << endl;//�ֲ�
	cout << "::a=" << ::a << endl;//ȫ��
	cout << "AA::a=" << AA::a << endl;//�����ռ�

	cout.unsetf(ios::dec);//��ֹʮ���Ƹ�ʽ����
	cout.setf(ios::hex);//������ó�ʮ������
	cout << a << endl;
	//ע�����ý����ڵ�ǰ����,���������õĺ���
	//Ҳ�������Ʒ������þ��ȼ����������ʽ
	cout.unsetf(ios::hex);//��ֹʮ�����Ƹ�ʽ����
	cout << a << endl;

	cout << add(1,2) << endl;//��ȱʡ��ʹ��ʵ������
	cout << add(1) << endl;//��ȱʡ��ʹ��ȱʡ�β�
	cout << add2() << endl;//ȫȱʡ��ʹ���β�
	cout << add3(1) << endl; //ȱʡ��ֻ�ܴ�����������ȱʡ�����ɼ��ȱʡ 

}