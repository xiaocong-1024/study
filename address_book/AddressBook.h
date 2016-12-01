#pragma once
#define MAX_PEOPLES 100
#define MAX_NAME 20
#define MAX_ADDRESS 50

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct tag
{
	char name[MAX_NAME];
	unsigned char age;
	char sex[10];
	char telephone[12];
	char address[MAX_ADDRESS];
}People_t,*PPeople_t;


typedef struct peo
{
	People_t per_mesg[MAX_PEOPLES];
	int count;//实际的人数
}seqlist,*Pseqlist;

enum select{Quit,Add,Delect,Find,Modify,Print,Clear,Sort,};

void add_peo(Pseqlist message);
void print_people_message(Pseqlist message);
void delete_peo_message(Pseqlist message);
void find(Pseqlist message);
static int find_peo(Pseqlist message,char *name);

void modify(Pseqlist message);
void clearall(Pseqlist message);
void sort(Pseqlist message);
void menu();
