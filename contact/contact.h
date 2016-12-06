#pragma once
#define MAX_PEOPLES 100
#define MAX_NAME 20
#define MAX_ADDRESS 50
#define INCREMENT  50

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<malloc.h>

typedef struct 
{
	char name[MAX_NAME];
	unsigned char age;
	char sex[10];
	char telephone[12];
	char address[MAX_ADDRESS];
}People_t;


typedef struct peo
{
	 People_t *per_mesg;
	int count;//实际的人数
	int length;
}seqlist,*pseqlist;

enum select{Quit,Add,Delect,Find,Modify,Print,Clear,Sort,};

void menu();
void add_peo(pseqlist* message);
void print_people_message(pseqlist* message);
static int find_peo_sub(pseqlist*  message,char *name);
void delete_peo_message(pseqlist*  message);
void find(pseqlist* message);
void modify(pseqlist*  message);
void clearall(seqlist * message);
void sort(pseqlist*  message);
void Init_seqlist(pseqlist* message);

