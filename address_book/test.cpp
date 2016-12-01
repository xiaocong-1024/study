#include"AddressBook.h"

int main()
{
	seqlist pro;
	pro.count = 0;
	while (1)
	{
		menu();
		printf("ÇëÑ¡Ôñ£º>");
		int select = 0;
		scanf("%d",&select);
		switch(select)
		{
			case Add:
				add_peo(&pro);
				break;
			case Delect:
				delete_peo_message(&pro);
				break;
			case Find:
				find(&pro);
				break;
			case Modify:
				modify(&pro);
				break;
			case Print:
				print_people_message(&pro);
				break;
			case Clear:
				clearall(&pro);
				break;
			case Sort:
				sort(&pro);
				break;
			case Quit:
				exit(0);
			default :
				break;	  
	}

	}
	system("pause");
	return 0;
}