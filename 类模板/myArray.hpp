#pragma once
#include<iostream>
#include<string>
using namespace std;

//����ģ��
template<class T>
//������
class myArray
{
public:
	//���캯��
	myArray(int room)
	{
		this->m_Room = room;
		this->m_Size = 0;
		this->m_array = new T[this->m_Room];
	}

	//��������
	~myArray()
	{
		if (this->m_array != NULL)
		{
			//�ͷ�����ռ�
			delete[] this->m_array;
			//����Ұָ��
			this->m_array = NULL;
			//������������
			this->m_Size = 0;
			this->m_Room = 0;
		}
	}

	//���
	myArray(const myArray& arr)
	{
		//��ͨ��Ա����ʵ��ǳ����
		this->m_Room = arr.m_Room;
		this->m_Size = arr.m_Size;
		//ָ����ڴ��ָ��ʵ�����
		this->m_array = new T[arr.m_Room];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->m_array[i] = arr.m_array[i];
		}
	}

	//=���������
	myArray& operator=(const myArray& arr)
	{
		//����������д������ݣ����������
		if (this->m_array != NULL)
		{
			//�ͷ�����ռ�
			delete[] this->m_array;
			//������������
			this->m_Size = 0;
			this->m_Room = 0;
		}

		//��ͨ��Ա����ʵ��ǳ����
		this->m_Room = arr.m_Room;
		this->m_Size = arr.m_Size;
		//ָ����ڴ��ָ��ʵ�����
		this->m_array = new T[arr.m_Room];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->m_array[i] = arr.m_array[i];
		}

		//��ʽ���
		return *this;
	}

	//[]���������
	T& operator[] (int index)
	{
		return this->m_array[index];
	}

	//**********get����private��Ա�����ĺ���**********//
	//getSize����
	int getSize()
	{
		return this->m_Size;
	}

	//getRoom����
	int getRoom()
	{
		return this->m_Room;
	}

	//β�巨����
	myArray& backInsert(const T& val)
	{
		//�ж������Ƿ�����
		if (this->m_Size >= this->m_Room)
		{
			//��ʽ���
			return *this;
		}

		//����δ������β����������
		this->m_array[this->m_Size] = val;
		this->m_Size++;

		//��ʽ���
		return *this;
	}

	//βɾ������
	myArray& backDelete()
	{
		//�ж������Ƿ�Ϊ��
		if (this->m_Size == 0)
		{
			//��ʽ���
			return *this;
		}

		//���鲻Ϊ�գ���ɾ��β������(�߼�ɾ����
		this->m_Size--;

		//��ʽ���
		return *this;
	}
private:
	int m_Size;//�����С
	int m_Room;//��������
	T* m_array;//����ָ��
};
