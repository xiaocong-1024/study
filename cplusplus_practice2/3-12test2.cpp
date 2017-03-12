#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>

bool Find(int target, vector<vector<int> > array)
{
	int rows = array.size();
	int columns = array[0].size();
	if (rows < 1 || columns < 1)
	{
		return false;
	}
	int row = 0;
	int column = columns - 1;
	while (row < rows && column >= 0)
	{
		if (target < array[row][column])
		{
			column--;
		}
		else if (target > array[row][column])
		{
			row++;
		}
		else
		{
			return true;
		}
	}
	return false;
}

void Test1()
{
	int arr[3][5] = {
		{ 2, 3, 4, 5, 6 },
		{ 12, 34, 45, 56, 67 },
		{ 120, 340, 450, 560, 670 }
	};

	vector<vector<int>> a;
	vector<int> b;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			b.push_back(arr[i][j]);
		}
		a.push_back(b);
	}
	cout<<Find(34,a)<<endl;
}

bool FunTest2(int target, int array[][5], int N)
{
	int rows = N;
	int columns = 5;
	int row = 0;
	int column = columns - 1;
	while (row < rows && column >= 0)
	{
		if (target < array[row][column])
		{
			column--;
		}
		else if (target > array[row][column])
		{
			row++;
		}
		else
		{
			return true;
		}
	}
	return false;
}

void Test2()
{
	int arr[3][5] = {
		{ 2, 3, 4, 5, 6 },
		{ 12, 34, 45, 56, 67 },
		{ 120, 340, 450, 560, 670 }
	};
	cout << FunTest2(100, arr, 3) << endl;
}


int main()
{
	Test1();
	return 0;
}