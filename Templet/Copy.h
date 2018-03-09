#pragma once
#include<iostream>
#include<string>

struct __FalseType{};
struct __TrueType{};

template<class T>
struct __TypeTraits //拷贝int ,char ...
{
	//POD：平凡类型---基本类型
	//在C++中与C兼容的类型，可按照C的处理方式
	//typedef __FalseType IsPODType;//内嵌重定义
	typedef __TrueType IsPODType;

};

template<>//特化
struct __TypeTraits<string>//拷贝string
{
	typedef __FalseType IsPODType;//内嵌重定义
};

//特化自定义Data类
/*
class Date;//前置声明
template<>
struct __TypeTraits<Data> //拷贝int ,char ...
{
	typedef __TrueType IsPODType;

};
*/
template<class T>
T*__TypeCopy(T* dst,const T* src,const size_t count)//确定调用那个复制
{
	return __TypeCopy(dst,src,count,__TypeTraits<T>::IsPODType());//重载
}

template<class T>
T* __TypeCopy(T* dst,const T* src,const size_t count,__TrueType)//拷贝int或char...
{
	return (T*)memcpy(dst,src,count*sizeof(T));//效率高
}

template<class T>
T* __TypeCopy(T* dst,const T* src,const size_t count,__FalseType)//拷贝string
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
