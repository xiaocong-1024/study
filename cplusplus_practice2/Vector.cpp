#define _CRT_SECURE_NO_WARNINGS 1
#include"Vector.h"

 Vector::Vector(size_t capacity)//避免发生隐式类型转换
	 :_pData(NULL)
	 ,_capacity(capacity)
	 , _size(0)
 {}

 Vector::Vector(size_t n, const DataType& data)
	 : _pData(new DataType[MAXSIZE])
	 , _capacity(MAXSIZE)
	 , _size(n)
 {
	 for (size_t index = 0; index < n; index++)
	 {
		 _pData[index] = data;
	 }
 }

 Vector::Vector(const Vector& v)
	 : _capacity(v._capacity)
	 , _size(v._size)
 {
	 _pData = new DataType[_capacity];
	 memcpy(_pData, v._pData, sizeof(DataType)*_size);
 }

 Vector& Vector::operator=(const Vector& v)
 {
	 if (this != &v)
	 {
		 _capacity = v._capacity;
		 _size = v._size;
		 DataType* pTemp = new DataType[v._capacity];
		 memcpy(pTemp, v._pData, sizeof(DataType)*_size);
		 delete[] _pData;
		 _pData = pTemp;
	 }
	 return *this;
 }

ostream& operator<<(ostream& _cout, const Vector& v)
 {
	for (size_t index = 0; index < v._size; index++)
	{
		_cout << v._pData[index] << "   ";
	}
	_cout << "_capacity = " << v._capacity << "     _size = " << v._size;
	return _cout;
 }

//尾插
void Vector::PushBack(const DataType& data)
{
	_CheckCapacity();
	_pData[_size] = data;
	_size++;
}
//尾删
void Vector::PopBack()
{
	if (_size != 0)
	{
		_size--;
	}
}
//在任意位置插入
void Vector::Insert(size_t pos, const DataType& data)
{
	assert(pos < _size);
	_CheckCapacity();
	for (int index = _size; index >= pos; index--)
	{
		_pData[index] = _pData[index - 1];
	}
	_pData[pos] = data;
	_size++;
}

//删除任意位置的元素
void Vector::Erase(size_t pos)
{
	assert(pos < _size);
	if (_size != 0)
	{
		for (size_t index = pos; index < _size - 1; index++)
		{
			_pData[index] = _pData[index + 1];
		}
		_size--;
	}
}

//查找值为data的元素
int Vector::Find(const DataType& data)const
{
	size_t count = _size;
	DataType* pTemp = _pData;
	while (count--)
	{
		if (pTemp[count] == data)
		{
			return count;
		}
	}
	return -1;
}
//清空顺序表
void Vector::Clear()
{
	_size = 0;
}
//获取顺序表中元素的个数
size_t Vector::Size()const
{
	return _size;
}

//扩展容量
void Vector::ReSize(size_t size, const DataType& data)
{
	if (size <= _size)
	{
		_size = size;
	}
	else if (size >= _capacity)
	{
		int count = _size;
		_size = size;
		_CheckCapacity();
		for (size_t index = count; index < size; index++)
		{

			_pData[index] = data;
		}
	}
	else
	{
		for (size_t index = _size; index < size; index++)
		{
			_pData[index] = data;
		}
		_size = size;
	}
}
//获取顺序表的容量
size_t Vector::Capacity()const
{
	return _capacity;
}
//判空
bool Vector::Empty()const
{
	if (0 == _size)
	{
		return true;
	}
	return false;
}
//获取首元素
DataType& Vector::Front()
{
	if (!Empty())
	{
		return _pData[0];
	}
}

const DataType& Vector::Front()const
{
	if (!Empty())
	{
		return _pData[0];
	}
}
//获取尾部的元素
DataType& Vector::Back()
{
	if (!Empty())
	{
		return _pData[_size - 1];
	}
}
const DataType& Vector::Back()const
{
	if (!Empty())
	{
		return _pData[_size - 1];
	}
}
//赋值
void Vector::Assign(size_t n, const DataType& data)
{
	DataType* Temp = new DataType[n];
	for (size_t index = 0; index < n; index++)
	{
		Temp[index] = data;
	}
	delete[] _pData;
	_size = n;
	_CheckCapacity();
	_pData = Temp;
}


DataType& Vector::operator[](size_t index)
{
	
		return _pData[index];
}
const DataType& Vector::operator[](size_t index)const
{
		return _pData[index];

}

//下标访问某个元素
DataType& Vector::At(size_t index)
{
	assert(index < _size);
	return _pData[index];
}

const DataType& Vector::At(size_t index)const
{
	assert(index < _size);
	return _pData[index];
}


void Test1()
{
	Vector v1(3, 10);
	//Vector v2(4, 6);
	//v2 = v1;
	//v1.PopBack();
	v1.PushBack(4);
	v1.Insert(2, 9);
	v1.Insert(3, 6);
	//cout << v1 << endl;
	//cout << v1.Find(7) << endl;;
	//cout << v1.Size() << endl;
	//v1.ReSize(12);
	//cout << v1.Capacity() << endl;
	//cout << v1 << endl;
	//cout << v1.Empty() << endl;
	//cout << v1.Front() << endl;
	//cout << v1.Back() << endl;
	//v1.Assign(2, 5);
	cout << v1[3] << endl;
	cout << v1.At(3) << endl;
}

int main()
{
	Test1();
	return 0;
}