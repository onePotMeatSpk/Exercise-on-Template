#pragma once
#include<iostream>
#include<string>
using namespace std;

//定义模板
template<class T>
//定义类
class myArray
{
public:
	//构造函数
	myArray(int room)
	{
		this->m_Room = room;
		this->m_Size = 0;
		this->m_array = new T[this->m_Room];
	}

	//析构函数
	~myArray()
	{
		if (this->m_array != NULL)
		{
			//释放数组空间
			delete[] this->m_array;
			//避免野指针
			this->m_array = NULL;
			//将各参数置零
			this->m_Size = 0;
			this->m_Room = 0;
		}
	}

	//深拷贝
	myArray(const myArray& arr)
	{
		//普通成员变量实行浅拷贝
		this->m_Room = arr.m_Room;
		this->m_Size = arr.m_Size;
		//指向堆内存的指针实行深拷贝
		this->m_array = new T[arr.m_Room];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->m_array[i] = arr.m_array[i];
		}
	}

	//=运算符重载
	myArray& operator=(const myArray& arr)
	{
		//如果该数组中存有数据，则清空重置
		if (this->m_array != NULL)
		{
			//释放数组空间
			delete[] this->m_array;
			//将各参数置零
			this->m_Size = 0;
			this->m_Room = 0;
		}

		//普通成员变量实行浅拷贝
		this->m_Room = arr.m_Room;
		this->m_Size = arr.m_Size;
		//指向堆内存的指针实行深拷贝
		this->m_array = new T[arr.m_Room];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->m_array[i] = arr.m_array[i];
		}

		//链式编程
		return *this;
	}

	//[]运算符重载
	T& operator[] (int index)
	{
		return this->m_array[index];
	}

	//**********get类中private成员变量的函数**********//
	//getSize函数
	int getSize()
	{
		return this->m_Size;
	}

	//getRoom函数
	int getRoom()
	{
		return this->m_Room;
	}

	//尾插法函数
	myArray& backInsert(const T& val)
	{
		//判断数组是否已满
		if (this->m_Size >= this->m_Room)
		{
			//链式编程
			return *this;
		}

		//数组未满，则尾部插入数据
		this->m_array[this->m_Size] = val;
		this->m_Size++;

		//链式编程
		return *this;
	}

	//尾删法函数
	myArray& backDelete()
	{
		//判断数组是否为空
		if (this->m_Size == 0)
		{
			//链式编程
			return *this;
		}

		//数组不为空，则删除尾部数据(逻辑删除）
		this->m_Size--;

		//链式编程
		return *this;
	}
private:
	int m_Size;//数组大小
	int m_Room;//数组容量
	T* m_array;//数组指针
};
