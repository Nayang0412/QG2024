#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Buzzer.h"


void main()
{
char i;
	while(1)
	{
		for(i=0;i<10;i++)
		{
		Buzzer_Time(100);
			Delay(500);
		}
	
	}


}
