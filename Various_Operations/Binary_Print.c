#include <stdio.h>

/* convert an integer into a string binary */
char *binString(unsigned short n)
{
	static char bin[17];
	int x;

	for(x=0;x<16;x++)
	{
        if (n &1)
        {
            bin[x]="1";
        }
        else
        {
            bin[x]="0";
        }
        n >>=1;
	}
	bin[16] = '\0';

	return(bin);
}

int main()
{
	unsigned short a,b;

	a = 0xFFFF;
	b = 0x00FF;

	printf("Start: %04X - %s\n",a,binString(a));
	printf("     & %04X - %s\n",b,binString(b));

	return 0;
}

