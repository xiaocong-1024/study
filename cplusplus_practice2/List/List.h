#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
typedef int DataType;

struct Node
{
	Node(const DataType& data)
	:_data(data)
	, pNext(NULL)
	, pPrev(NULL)
	{}
	DataType _data;
	Node* pNext;
	Node* pPrev;
};

class List
{
public :
	List()
		:_pHead(NULL)
		, _pTail(NULL)
		, _size(0)
	{}
	List(const List& l);
	List(int n, const DataType& data = DataType());
	List& operator=(List l);
	~List()
	{
		Clear();
	}
	void PushBack(const DataType& data);
	void PopBack();
	void PushFront(const DataType& data);
	void PopFront();
	void Insert(Node* pos, const DataType& data);
	void Erase(Node* pos);
	
	void Assign(int n, const DataType data = DataType());
	void Clear();

	Node& Front();
	const Node& Front()const;
	Node& Back();
	const Node& Back()const;
	Node& operator[](size_t index);
	const Node& operator[](size_t index)const;
	size_t Size()const;
	bool Empty()const;
	Node* Find(const DataType& data);
	Node* GetNode(const DataType& data);
	void print();
private :
	Node* _pHead;
	Node* _pTail;
	size_t _size;
};