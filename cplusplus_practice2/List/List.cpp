#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

List::List(int n, const DataType& data)
{
	while (n--)
	{
		PushBack(data);
	}
}

List::List(const List& l)
:_pHead(NULL)
, _pTail(NULL)
, _size(l._size)
{
	Node* cur = l._pHead;
	while (cur)
	{
		PushBack(cur->_data);
		cur = cur->pNext;
	}
}

List& List::operator=(List l)
{
	swap(_pHead, l._pHead);
	swap(_pTail, l._pTail);
	_size = l._size;
	return *this;
}


//尾插（在最后一个节点的后面插入一个新的节点）
void List::PushBack(const DataType& data)
{
	if (NULL == _pHead)
	{
		assert(_pTail == NULL);
		_pHead = GetNode(data);
		_pTail = _pHead;
		_size = 1;
	}
	else
	{
		Node* pTemp = GetNode(data);
		_pTail->pNext = pTemp;
		pTemp->pPrev = _pTail;
		_pTail = pTemp;
		_size++;
	}
}
//尾删（删除链表中最后一个节点）
void List::PopBack()
{
	if (NULL == _pHead)
	{
		assert(NULL == _pTail);
		return;
	}
	else if (NULL == _pHead->pNext)
	{
		delete _pHead;
		_pHead = _pTail = NULL;
		_size = 0;
	}
	else
	{
		Node* prev = _pTail->pPrev;
		delete _pTail;
		prev->pNext = NULL;
		_pTail = prev;
		_size--;
	}
}
//头插（在链表的第一个节点前面插入一个新的节点）
void List::PushFront(const DataType& data)
{
	if (NULL == _pHead)
	{
		assert(_pTail == NULL);
		_pHead = GetNode(data);
		_pTail = _pHead;
		_size = 1;
	}
	else
	{
		Node* pTemp = GetNode(data);
		pTemp->pNext = _pHead;
		_pHead->pPrev = pTemp;
		_pHead = pTemp;
		_size++;
	}
}


//头删（删除第一个节点）
void List::PopFront()
{
	if (NULL == _pHead)
	{
		assert(NULL == _pTail);
		return;
	}
	else if (NULL == _pHead->pNext)
	{
		delete _pHead;
		_pHead = _pTail = NULL;
		_size--;
	}
	else
	{
		Node* cur = _pHead;
		cur = cur->pNext;
		delete _pHead;
		_pHead = cur;
		_size--;
	}
}


//在链表中的任意位置插入一个元素
void List::Insert(Node* pos, const DataType& data)
{
	if (pos == _pTail)
	{
		Node* pTemp = GetNode(data);
		_pTail->pNext = pTemp;
		pTemp->pPrev = _pTail;
		_pTail = pTemp;
		_size++;
	}
	else
	{
		Node* pTemp = GetNode(data);
		Node* cur = pos;
		Node* next = cur->pNext;
		cur->pNext = pTemp;
		pTemp->pNext = next;
		next->pPrev = pTemp;
		pTemp->pPrev = cur;
		_size++;
	}
}

//删除链表中任意位置的元素
void List::Erase(Node* pos)
{
	if (NULL == _pHead)
	{
		assert(_pTail == NULL);
		return;
	}
	else if (pos == _pHead)
	{
		PopFront();
	}
	else
	{
		Node* cur = pos;
		Node* prev = cur->pPrev;
		Node* next = cur->pNext;
		prev->pNext = next;
		delete cur;
		next->pPrev = prev;
		--_size;
	}

}

//返回链表中值为data的位置
Node* List::Find(const DataType& data)
{
	if (NULL == _pHead)
	{
		assert(NULL == _pTail);
		return NULL;
	}
	else
	{
		Node* cur = _pHead;
		while (cur && (cur->_data != data))
		{
			cur = cur->pNext;
		}
		if (cur)
		{
			return cur;
		}
		return NULL;
	}
}

//赋值
void List::Assign(int n, const DataType data)
{
	
		Node* cur = _pHead;
		int size = n;
		if (size >= _size)
		{
			while (cur && size--)
			{
				cur->_data = data;
				cur = cur->pNext;
			}
			if (size != 0 && cur == NULL)
			{
				int count = n - _size;
				while (count--)
				{
					PushBack(data);
				}
				_size += count;
			}
		}
		else
		{
			Node* cur = _pHead;
			Node* del = _pHead;
			while (size--)
			{
				cur->_data = data;
				del = cur;
				cur = cur->pNext;
			}
			_size = n;
			_pTail = del;
			_pTail->pNext = NULL;
		}	
}

//清空链表
void List::Clear()
{
	if (NULL != _pHead)
	{
		Node* cur = _pHead;
		while (cur)
		{
			Node* del = cur;
			cur = cur->pNext;
			delete del;
		}
		_pHead = _pTail = NULL;
	}
}

//返回头节点
Node& List::Front()
{
	if (NULL != _pHead)
	{
		return *_pHead;
	}
}

//
const Node& List::Front()const
{
	if (NULL != _pHead)
	{
		return *_pHead;
	}
}
//返回尾节点
Node& List::Back()
{
	if (NULL != _pHead)
	{
		return *_pTail;
	}
}

const Node& List::Back()const
{
	if (NULL != _pHead)
	{
		return *_pTail;
	}
}


Node& List::operator[](size_t index)
{
	if (NULL != _pHead)
	{
		assert(index < _size);
		Node* cur = _pHead;
		while (index-- && cur)
		{
			cur = cur->pNext;
		}
		if (cur)
		{
			return *cur;
		}
	}
}

const Node& List::operator[](size_t index)const
{
	if (NULL != _pHead)
	{
		assert(index < _size);
		Node* cur = _pHead;
		while (index-- && cur)
		{
			cur = cur->pNext;
		}
		if (cur)
		{
			return *cur;
		}
	}
}

//获取链表中节点的个数
size_t List::Size()const
{
	return _size;
}

//判空
bool List::Empty()const
{
	if (NULL == _pHead)
	{
		return true;
	}
	return false;
}

//获取一个节点
Node* List::GetNode(const DataType& data)
{
	Node* pTemp = new Node(data);
	pTemp->pNext = NULL;
	pTemp->pPrev = NULL;
	return pTemp;
}

void List::print()
{
	if (NULL != _pHead)
	{
		Node* cur = _pHead;
		while (cur)
		{
			cout << (cur->_data) << "  ";
			cur = cur->pNext;
		}
		cout << endl;
	}
}

void Test1()
{
	List l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	l1.PushBack(5);
	l1.print();
	List l2;
	l2.PushBack(7);
	l2.PushBack(8);
	l2.PushBack(9);
	l2.PushBack(10);
	l2.print();
	l2 = l1;
	l2.print();
}



void Test2()
{
	List l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.print();
	l1.PopBack();
	l1.PopBack();
	l1.PopBack();
	l1.PopBack();

	l1.print();

}

void Test3()
{
	List l1;
	l1.PushFront(5);
	l1.PushFront(6);
	l1.PushFront(7);
	l1.print();
	l1.PopFront();
	l1.print();
	l1.PopFront();
	l1.PopFront();
	l1.print();
}


void Test4()
{
	List l2;
	l2.PushBack(7);
	l2.PushBack(8);
	l2.PushBack(9);
	l2.PushBack(10);
	l2.print();
	Node* pos = l2.Find(8);
	//l2.Insert(pos,5);
	l2.Erase(pos);
	l2.print();
	l2.Clear();
	l2.PushBack(0);
	l2.print();
}

void Test5()
{
	List l2;
	l2.PushBack(7);
	l2.PushBack(8);
	l2.PushBack(9);
	Node temp = l2[0];
	cout << temp._data << endl;
}

void Test6()
{
	List l2;
	l2.PushBack(7);
	l2.PushBack(8);
	l2.PushBack(9);
	l2.Assign(2, 10);
	l2.print();
	l2.Assign(5, 3);
	l2.print();
}


void Test7()
{
	List l1(3, 4);
	l1.print();
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test6();
	Test7();
	return 0;
}