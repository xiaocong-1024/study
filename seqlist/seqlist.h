#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_SIZE 100
#define INCREMENT 20

typedef int DataType;

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<memory.h>

typedef struct seq
{
	DataType *data;
	int count;
	int listsize;
}seqlist,*pseqlist;


void Init_Seqlist(pseqlist seq);

void PushBack(pseqlist seq,DataType x);

void PopBack(pseqlist seq);

void Pushfront(pseqlist seq,DataType x);

void Popfront(pseqlist seq);

void Insert(pseqlist seq,size_t pos,DataType x);

void PrintSeqlist(pseqlist seq);

int  Find(pseqlist seq,DataType x);

void Erase(pseqlist seq,size_t pos);

void Remove(pseqlist seq,DataType x);
