
#include<stdio.h>
#include<string.h>


struct  sale{
	const 	char  s[8];
	int   number;
}records[4] = { { "levono", 0 }, { "acer", 0 }, { "asus", 0 }, { "dell", 0 } };


void  record(char *brand,int m)
{
	int n;
	for (n = 0; n < 4; n++)
	{
		if (0 == strcmp(records[n].s, brand))
		{
			records[n].number += m;
			break;
		}
	}
}


void TOfile(FILE* fp)
{
	int n;
	for (n = 0; n < 4; n++)
	{
		fwrite(records[n].s, sizeof(records[n].s), 1, fp);
		fwrite("\t", sizeof('\t'), 1, fp);
	}
}
int  main()
{
	

	char  brand[8],*menu;
	int i, n, m;
	scanf_s("%s  %d", brand, &m);
	
	record(brand,m);
	
	FILE  *fp;
	i = fopen_s(&fp, "D:\\record.txt", "w+");
	if (!i)
	{
		TOfile(fp);
		
	}
	fclose(fp);

	return 0;
}


