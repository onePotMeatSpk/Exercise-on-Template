#include<iostream>
#include<string>
#include"myArray.hpp"
using namespace std;

void showIntInfo(myArray<int>& arr)
{
	cout << "����������" << arr.getRoom() << endl;
	cout << "�����С��" << arr.getSize() << endl;
	cout << "����Ԫ�أ�";
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout <<" "<< arr[i];
	}
	cout << endl;
}

int main()
{
	myArray<int> arr0(10);
	arr0.backInsert(1).backInsert(2);
	showIntInfo(arr0);
	system("pause");
	return 0;
}