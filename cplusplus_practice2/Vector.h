#pragma once
#include<iostream>
using namespace std;
#define MAXSIZE 30
#include<assert.h>

typedef int DataType;
class Vector
{
public:
	explicit Vector(size_t capacity = MAXSIZE);//避免发生隐式类型转换

	// 有n个值为data的元素
	Vector(size_t n, const DataType& data);//construction function
	Vector(const Vector& v);//construction function
	Vector& operator=(const Vector& v);//overloaded function
	~Vector()//destruction function
	{
		if (NULL != _pData)
		{
			delete[] _pData;
			_pData = NULL;
			_size = 0;
			_capacity = 0;
		}
	}
	void PushBack(const DataType& data);
	void PopBack();
	void Insert(size_t pos, const DataType& data);
	void Erase(size_t pos);
	int Find(const DataType& data)const;
	void Clear();
	size_t Size()const;
	void ReSize(size_t size, const DataType& data = DataType());
	size_t Capacity()const;
	bool Empty()const;
	DataType& Front();
	const DataType& Front()const;
	DataType& Back();
	const DataType& Back()const;
	void Assign(size_t n, const DataType& data = DataType());
	DataType& operator[](size_t index);
	const DataType& operator[](size_t index)const;
	DataType& At(size_t index);
	const DataType& At(size_t index)const;
private:
	void _CheckCapacity()
	{
		if (_size >= _capacity)
		{
			DataType* pTemp = new DataType[_capacity * 2];
			_capacity = 2 * _capacity;
			memcpy(pTemp, _pData, _size * sizeof(DataType));
			delete[] _pData;
			_pData = pTemp;
		}
	}
	friend ostream& operator<<(ostream& _cout, const Vector& v);
private:
	DataType* _pData;
	size_t _capacity;
	size_t _size;
};
