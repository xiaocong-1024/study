#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cassert>

typedef int DataType;
struct SlistNode
{
	DataType _data;
	SlistNode* _next;
	SlistNode(DataType x)
	{
		_data = x;
		_next = NULL;
	}
};

class SList
{
	typedef SlistNode Node;
public:
	SList();
	SList(const SList& l);
	SList& operator=(SList l);
	void Swap(SList& l);
	~SList();
	void Destory();
	void PushBack(DataType x);
	void PopBack();
	void PushFront(DataType x);
	void PopFront();
	void Insert(Node* pos, DataType x);
	void Erase(Node* pos);
	Node* Find(DataType x);
	void Print();
protected :
	Node* _head;
	Node* _tail;
};






