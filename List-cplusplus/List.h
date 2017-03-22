#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cassert>

typedef  int DataType;

struct ListNode
{
	ListNode(DataType x)
	:_data(x)
	,_next(NULL)
	,_prev(NULL)
	{}
	DataType _data;
	ListNode* _next;
	ListNode* _prev;
};

class List
{
	typedef ListNode Node;
public:
	List()
		:_head(NULL)
		, _tail(NULL)
	{}
	~List();
	List(const List& l);
	List& operator=(const List& l);
		void Destory();
	void PushBack(DataType x);
	void PopBack();
	void PushFront(DataType x);
	void PopFront();
	void Insert(Node* pos, DataType x);
	void Erase(Node* pos);
	void Print();
	Node* Find(DataType x);
	void Swap(List l);
private:
	Node* _head;
	Node* _tail;
};


