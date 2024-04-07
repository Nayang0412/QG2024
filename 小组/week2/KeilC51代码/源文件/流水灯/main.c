#include <REGX52.H>

void Delay(unsigned char xms)		//@12.000MHz
{
	unsigned char i, j;
  while(xms)
	{		i = 2;
			j = 239;
			do
			{
				while (--j);
			} while (--i);
	    xms--;
	}
	
}


void main()
{
	
	char i=0;
	for(i=0;i<8;i++)
	{
		Delay(200);
		P2=~(0x01<<i);
	
	}
}

