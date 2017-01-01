#include"ListNode.h"

void Test1()
{
	PNode pHead = NULL;
	InitListNode(&pHead);
	PushBack(&pHead,1);
	PushBack(&pHead,2);
	PushBack(&pHead,3);
	PushBack(&pHead,4);
	PushBack(&pHead,5);
	printList(pHead);
	/*PopBack(&pHead);
	printList(pHead);
	PopBack(&pHead);
	PopBack(&pHead);
	PopBack(&pHead);
	printList(pHead);
	PopBack(&pHead);
	printList(pHead);*/

	//Erase(&pHead,Find(pHead,5));
	Remove(&pHead,3);
	printList(pHead);
}


void Test2()
{
	PNode pHead = NULL;
	InitListNode(&pHead);
	PushFront(&pHead,2);
	PushFront(&pHead,2);
	PushFront(&pHead,3);
	PushFront(&pHead,1);
	PushFront(&pHead,2);
	PushFront(&pHead,1);
	PushFront(&pHead,2);
	printList(pHead);
    RemoveAll(&pHead,2);
	printList(pHead);
	/*PopFront(&pHead);
	printList(pHead);
	PopFront(&pHead);
	printList(pHead);
	PopFront(&pHead);
	printList(pHead);
	PopFront(&pHead);
	printList(pHead);
	PopFront(&pHead);
	printList(pHead);*/
	//printList(pHead);
	////printFromTailToFront(pHead);
	//PNode pos = Find(pHead,4);
	//InsertNode(pos,6);
	//printList(pHead);
	//Erase(&pHead,pos);
	//printList(pHead);
	
}



void Test3()
{
	PNode pHead = NULL;
	InitListNode(&pHead);
	PushFront(&pHead,2);
	PushFront(&pHead,3);
	PushFront(&pHead,4);
	PushFront(&pHead,1);
	printf("size : %d\n",Size(pHead));
}



void Test4()
{
	PNode pHead = NULL;
	InitListNode(&pHead);
	PushFront(&pHead,2);
	PushFront(&pHead,3);
	PushFront(&pHead,4);
	PushFront(&pHead,1);
	printList(pHead);
	PNode pos = Find(pHead,3);
	DeleteNotTailNode(pos);
	printList(pHead);
}

void Test5()
{
	PNode pHead = NULL;
	InitListNode(&pHead);
	PushFront(&pHead,2);
	PushFront(&pHead,3);
	PushFront(&pHead,4);
	PNode pos = Find(pHead,4);
	printList(pHead);
	InsertNotHeadNode(pos,7);
	printList(pHead);
}

void Test6()
{
	PNode pHead = NULL;
	InitListNode(&pHead);
	PushBack(&pHead,1);
	PushBack(&pHead,2);
	PushBack(&pHead,3);
	PushBack(&pHead,4);
	PushBack(&pHead,5);
	PushBack(&pHead,6);
	printList(pHead);
	PNode pos = Find(pHead,6);
	pos->next = pHead;
	pos = JosephCircle(pHead,2);
	printf("%d \n",pos->data);

}

void Test7()
{
	PNode pHead = NULL;
	InitListNode(&pHead);
	PushBack(&pHead,6);
	PushBack(&pHead,2);
	PushBack(&pHead,8);
	PushBack(&pHead,3);
	PushBack(&pHead,0);
	//PushBack(&pHead,7);
	printList(pHead);
	PNode mid = FindMidNode(pHead);
	if (mid)
	printf("%d \n",mid->data);
	/*PNode node = ReverseList(pHead);
	printList(node);*/
}



void Test8()
{
	PNode pHead = NULL;
	InitListNode(&pHead);
	PushBack(&pHead,6);
	PushBack(&pHead,2);
	PushBack(&pHead,8);
	PushBack(&pHead,3);
	PushBack(&pHead,0);
	PushBack(&pHead,7);
	printList(pHead);
	//PNode node = FindLastKNode(pHead,3);
	DeleteLastKNode(pHead,2);
	printList(pHead);

}



void Test9()
{
	PNode pHead1 = NULL;
	InitListNode(&pHead1);
	PushBack(&pHead1,1);
	PushBack(&pHead1,5);
	PushBack(&pHead1,7);
	printList(pHead1);
	PNode pHead2 = NULL;
	InitListNode(&pHead2);
	PushBack(&pHead2,0);
	PushBack(&pHead2,3);
	//PushBack(&pHead2,4);
	
	printList(pHead2);
	PNode node = MergeList(pHead1,pHead2);
	printList(node);
}



int main()
{
	//Test2();
	//Test3();
	//Test5();
	//Test6();
	//Test7();
	//Test8();
	Test9();
	system("pause");
	return 0;
}