#pragma warning (disable :4996)
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node *next;
}Node,*PNode;


void printList(PNode phead);
void InitListNode(PNode *pHead);
void PushBack(PNode *pHead,DataType _data);
void PopBack(PNode *pHead);
PNode Find(PNode pHead, DataType data);

void PushFront(PNode *pHead,DataType _data);
void PopFront(PNode *pHead);
void printFromTailToFront(PNode pHead);

void InsertNode(PNode pos,DataType _data);
void Erase(PNode* pHead, PNode pos);

void Remove(PNode* pHead, DataType data);
void RemoveAll(PNode* pHead, DataType data);
size_t Size(PNode pHead);
PNode Front(PNode pHead);
PNode Back(PNode pHead);
int Empty(PNode pHead);

void DeleteNotTailNode(PNode pos);
void InsertNotHeadNode(PNode pos, DataType data);
//用单链表实现约瑟夫环
PNode JosephCircle(PNode pHead, size_t M);
//逆置单链表--三个指针
PNode ReverseList(PNode pHead);
// 对单链表进行冒泡排序--升序
void BubbleSort(PNode pHead);
// 查找单链表的中间结点，要求只能够遍历一次链表
PNode FindMidNode(PNode pHead);

// 查找单链表的倒数第K个结点，只能够遍历一次链表
PNode FindLastKNode(PNode pHead, size_t K);

// 删除单链表的倒数第K个结点
PNode DeleteLastKNode(PNode pHead, size_t K);

// 合并两个已序单链表，合并之后依然有序
PNode MergeList(PNode pHead1, PNode pHead2);

