#include<iostream>
#include<string>
#include"myArray.hpp"
using namespace std;

void showIntInfo(myArray<int>& arr)
{
	cout << "数组容量：" << arr.getRoom() << endl;
	cout << "数组大小：" << arr.getSize() << endl;
	cout << "数组元素：";
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