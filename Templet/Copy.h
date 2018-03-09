#pragma once
#include<iostream>
#include<string>

struct __FalseType{};
struct __TrueType{};

template<class T>
struct __TypeTraits //����int ,char ...
{
	//POD��ƽ������---��������
	//��C++����C���ݵ����ͣ��ɰ���C�Ĵ���ʽ
	//typedef __FalseType IsPODType;//��Ƕ�ض���
	typedef __TrueType IsPODType;

};

template<>//�ػ�
struct __TypeTraits<string>//����string
{
	typedef __FalseType IsPODType;//��Ƕ�ض���
};

//�ػ��Զ���Data��
/*
class Date;//ǰ������
template<>
struct __TypeTraits<Data> //����int ,char ...
{
	typedef __TrueType IsPODType;

};
*/
template<class T>
T*__TypeCopy(T* dst,const T* src,const size_t count)//ȷ�������Ǹ�����
{
	return __TypeCopy(dst,src,count,__TypeTraits<T>::IsPODType());//����
}

template<class T>
T* __TypeCopy(T* dst,const T* src,const size_t count,__TrueType)//����int��char...
{
	return (T*)memcpy(dst,src,count*sizeof(T));//Ч�ʸ�
}

template<class T>
T* __TypeCopy(T* dst,const T* src,const size_t count,__FalseType)//����string
{
	for(size_t i=0;i<count;++i)
	{
		dst[i]=src[i];
	}
	return dst;
}



//void test_copy(void)
//{
//	int a1[]={1,2,3,};
//	int a2[]={4,5,6};
//    __TypeCopy(a1,a2,3);
//	cout << a1 <<endl;
//
//	string s1[]={"123"};
//	string s2[]={"456"};
//	__TypeCopy(s1,s2,4);
//	cout << s1 <<endl;
//}
