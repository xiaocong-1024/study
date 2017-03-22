#include"List.h"

//拷贝构造
List::List(const List& l)
:_head(NULL)
, _tail(NULL)
{
	Node* cur = l._head;
	while (cur)
	{
		PushBack(cur->_data);
		cur = cur->_next;
	}
}

void List::Swap(List l)
{
	std::swap(_head, l._head);
	std::swap(_tail, l._tail);
}

//赋值运算符（写法现代）
//List& List::operator=(List l)
//{
//	Swap(l);
//	return *this;
//}


//赋值运算符（传统写法）
List& List::operator=(const List& l)
{
	if (this != &l)
	{
		this->~List();
		Node* cur = l._head;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	return *this;
}


//尾插
void List::PushBack(DataType x)
{
	//1.链表为空
    //2.有节点
	Node* cur = _head;
	if (cur == NULL)
	{
		_head = _tail = new Node(x);
	}
	else
	{
		Node* tmp = new Node(x);
		_tail->_next = tmp;
		tmp->_prev = _tail;
		_tail = tmp;
	}
}

//打印链表
void List::Print()
{
	Node* cur = _head;
	while (cur)
	{
		cout << cur->_data << "  ";
		cur = cur->_next;
	}
	cout << endl;
}
//尾删
void List::PopBack()
{
	//1.链表为空
	//2.有一个节点
	//3.有多个节点
	if (NULL == _head)
	{
		return;
	}
	if (NULL == _head->_next)
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node* cur = _tail->_prev;
		delete _tail;
		_tail = cur;
		_tail->_next = NULL;
	}
}

//头插
void List::PushFront(DataType x)
{
	//1.链表为空
	//2.有节点
	Node* cur = _head;
	if (NULL == cur)
	{
		_head = _tail = new Node(x);
	}
	else
	{
		Node* tmp = new Node(x);
		tmp->_next = _head;
		_head->_prev = tmp;
		_head = tmp;
	}
}

//头删
void List::PopFront()
{
	//1.链表为空
	//2.有一个节点
	//3.有多个节点
	if (NULL == _head)
	{
		return;
	}
	if (NULL == _head->_next)
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node* cur = _head->_next;
		delete _head;
		_head = cur;
		_head->_prev = NULL;
	}
}

List::Node* List::Find(DataType x)
{
	Node* cur = _head;
	while (cur && (cur->_data != x))
	{
		cur = cur->_next;
	}
	return cur;
}


//在pos位置的前面插入
void List::Insert(Node* pos, DataType x)
{
	//1.在头结点前插入
	//2.不在头结点插入
	assert(pos != NULL);
	if (pos == _head)
	{
		PushFront(x);
	}
	else
	{
		Node* tmp = new Node(x);
		Node* tmpPrev = pos->_prev;
		tmp->_next = pos;
		pos->_prev = tmp;
		tmp->_prev = tmpPrev;
		tmpPrev->_next = tmp;
	}
}

//删除某个位置的节点
void List::Erase(Node* pos)
{
	//1.链表为空
	//2.删除头结点
	//3删除尾节点
	//3.删除中间任意节点
	assert(pos != NULL);
	if (NULL == _head)
	{
		return;
	}
	if (pos == _head)
	{
		PopFront();
	}
	else if (pos == _tail)
	{
		PopBack();
	}
	else
	{
		Node* cur = _head;
		while (cur && cur->_next != pos)
		{
			cur = cur->_next;
		}
		if (cur)
		{
			Node *next = pos->_next;
			cur->_next = next;
			next->_prev = cur;
			delete pos;
		}
	}
}


//释放空间
void List::Destory()
{
	Node* cur = _head;
	while (cur)
	{
		Node* del = cur;
		cur = cur->_next;
		delete del;
	}
	_head = _tail = NULL;
}

List::~List()
{
	Destory();
}

void Test1()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.Print();

}

void Test2()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.Print();
	l.PopBack();
	l.Print();
	l.PopBack();
	l.PopBack();
	l.Print();
}

void Test3()
{
	List l;
	/*l.PushBack(1);
	l.PushBack(2);
	l.Print();*/
	l.PushFront(9);
	l.PushFront(8);
	l.PushFront(7);
	l.Print();
}

void Test4()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.Print();
	l.PopFront();
	l.Print();
	l.PopFront();
	l.Print();
	l.PopFront();
	l.Print();
}


void Test5()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.Insert(l.Find(1), 9);
	l.Print();
	l.Insert(l.Find(2), 8);
	l.Print();
}

void Test6()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.Print();
	//l.Erase(l.Find(1));
	//l.Print();
	l.Erase(l.Find(2));
	l.Print();
}

void Test7()
{
	List l;
	l.PushBack(2);
	List l2(l);
	l2.Print();
}

void Test8()
{
	List l1;
	l1.PushBack(2);
	l1.Print();
	List l;
	l.PushFront(9);
	l.PushFront(8);
	l.PushFront(7);
	l.Print();
	l1 = l;
	l1.Print();
}

int main()
{
	Test8();
	return 0;
}