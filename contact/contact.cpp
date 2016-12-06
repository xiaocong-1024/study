#include"contact.h"

void menu()
{
	printf("###########################\n");
	printf("#1.add############2.delete#\n");
	printf("#3.find###########4.modiyf#\n");
	printf("#5.print###########6.clear#\n");
	printf("#7.sort###########0.quit##\n");
	printf("###########################\n");

}

void Init_seqlist(pseqlist* message)
{	
	(*message) = (pseqlist)malloc(sizeof(seqlist));
	if (NULL == (*message))
	{
		printf("out of memory\n");
		exit(1);
	}
	(*message)->per_mesg = (People_t *)malloc(sizeof(People_t) * MAX_PEOPLES);
	(*message)->length = MAX_PEOPLES;
	(*message)->count = 0;
	if (NULL == (*message)->per_mesg)
	{
		printf("out of memory\n");
		exit(1);
	}
	printf("初始化成功\n");
}

void add_peo(pseqlist* message)
{
	if ((*message)->count >= (*message)->length)
	{
		People_t * newbase = (People_t *)realloc((*message)->per_mesg,\
			(MAX_PEOPLES + INCREMENT) * sizeof(People_t) * INCREMENT);
		if (NULL ==newbase )
		{
			printf("out of memory\n");
			exit(1);
		}
		(*message)->per_mesg = newbase;
		(*message)->length += INCREMENT;
	}
	else
	{
		printf("姓名：>");
		scanf("%s",(*message)->per_mesg[(*message)->count].name);
		printf("年龄:>");
		scanf("%d",&(*message)->per_mesg[(*message)->count].age);
		printf("性别：>");
		scanf("%s",(*message)->per_mesg[(*message)->count].sex);
		printf("电话：>");
		scanf("%s",(*message)->per_mesg[(*message)->count].telephone);
		printf("地址：>");
		scanf("%s",(*message)->per_mesg[(*message)->count].address);
	
		(*message)->count++;
	}
}



void print_people_message(pseqlist* message)
{
	if ((*message)->count != 0)
	{
		for (int i = 0; i < (*message)->count; i++)
		{
			printf("name : %s  ",(*message)->per_mesg[i].name );
			printf("age : %d  ",(*message)->per_mesg[i].age );
			printf("sex : %s  ",(*message)->per_mesg[i].sex);
			printf("telephone : %s  ",(*message)->per_mesg [i].telephone);
			printf("address : %s  ",(*message)->per_mesg [i].address);
			printf("\n");
		}
	}
	else
	{
		printf("通讯录为空\n");
	}
}

//查找下标
static int find_peo_sub(pseqlist*  message,char *name)
{
	int i = 0;
	for (i = 0; i < (*message)->count; i++)
	{
		if (strcmp(name,(*message)->per_mesg[i].name ) == 0)
		{
			return i;
		}
	}
	return -1;
}


void delete_peo_message(pseqlist*  message)
{
	if ( (*message)->count <= 0)
	{
		printf("通讯录为空\n");
		return ;
	}
	printf("请输入要删除的联系人姓名:>");
	char name[10];
	scanf("%s",name);
	int ret = find_peo_sub(message,name);
	if (ret != -1)
	{
		for (int j = ret; j < (*message)->count; j++)
		{
			(*message)->per_mesg[j] = (*message)->per_mesg[j+1];
		}
		printf("删除成功\n");
		(*message)->count--;
		return ;
	}
	else
	{
		printf("通讯录中没有要删除的联系人\n");
	}
}	

void find(pseqlist* message)
{
	if ( (*message)->count <= 0)
	{
		printf("通讯录为空\n");
		return ;
	}
	printf("请输入你要查找联系人的姓名:>");
	char name[10];
	scanf("%s",name);
	int ret = find_peo_sub(message,name);
	if (ret != -1)
	{
		printf("name : %s age: %d sex : %s telephone : %s address %s\n",\
				(*message)->per_mesg[ret].name,(*message)->per_mesg[ret].age,(*message)->per_mesg[ret].sex,\
				(*message)->per_mesg[ret].telephone,(*message)->per_mesg[ret].address);
	}	
	else
	{
		printf("没有找到该联系人\n");
	}
}

void modify(pseqlist*  message)
{
	if ( (*message)->count <= 0)
	{
		printf("通讯录为空\n");
		return ;
	}
	printf("请输入要修改联系人的姓名:>");
	char name[10];
	scanf("%s",name);
	int ret = find_peo_sub(message,name);
	if (ret != -1)
	{
		printf("请输入要修改后的名字：>");
		scanf("%s",(*message)->per_mesg[ret].name);

		printf("请输入修改后的年龄：>");
		scanf("%d",&(*message)->per_mesg[ret].age);
		
		printf("请输入修改后的性别：>");
		scanf("%s",(*message)->per_mesg[ret].sex);
		
		printf("请输入修改后的电话：>");
		scanf("%s",(*message)->per_mesg[ret].telephone);
		
		printf("请输入要修改后的地址:>");
		scanf("%s",(*message)->per_mesg[ret].address);
		printf("修改成功：\n");

	}
	else
	{
		printf("要修改的联系人不存在\n");
	}
}

void clearall(seqlist * message)
{
	message->count = 0;
}


void sort(pseqlist*  message)
{
	//冒泡排序
	if ( (*message)->count <= 0)
	{
		printf("通讯录为空\n");
		return ;
	}
	for (int i = 0; i < (*message)->count-1; i++)
	{
		int flag = 1;
		for (int j = 0; j < (*message)->count-1-i; j++)
		{
			if (strcmp((*message)->per_mesg[j].name,(*message)->per_mesg[j+1].name) > 0)
			{
				flag  = 0;
				People_t tmp = (*message)->per_mesg[j];
				(*message)->per_mesg[j] = (*message)->per_mesg[j+1];
				(*message)->per_mesg[j+1] =tmp;
			}
		}
		if (flag)
		{
			break;
		}
	}
}