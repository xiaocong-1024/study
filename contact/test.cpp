#include"contact.h"

	int main()
 {
	pseqlist  pro;
	Init_seqlist(&pro);
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
				clearall(pro);
				break;
			case Sort:
				sort(&pro);
				break;
			default :
				break;	  
	}
 }
	free(pro->per_mesg);
	free(pro);
	system("pause");
	return 0;
 }