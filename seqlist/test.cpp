#include"seqlist.h"


int main()
{
	seqlist seq;
	Init_Seqlist(&seq);
	PushBack(&seq, 10);
	PushBack(&seq, 20);
	PushBack(&seq, 36);
	PushBack(&seq, 87);
	
    Insert(&seq,2,4);
    PrintSeqlist(&seq);
	Insert(&seq,1,9);
    PrintSeqlist(&seq);
	 Erase(&seq,3);
	PrintSeqlist(&seq);
	// Erase(&seq,5);
	//PrintSeqlist(&seq);

	Remove(&seq,10);
	PrintSeqlist(&seq);

	
	
	
	

	system("pause");
	return 0;
}