#include<stdint.h>
#include<stdlib.h>

int main()
{
	uint16_t addr = 10000; 
	
	uint8_t a = ((addr>>16) & (0xff));	
	
	// 10000>> 16 = x
	// x=0
	// x & (0xff) = y
	// 0 & 11111111, y=0
	
	uint8_t b = (((addr>>8) & (0xff)));
	
	// 10000>> 8 = z
	// z=39
	// z & (0xff) = w
	// 39 & 11111111, w=39
	
	printf("%ld %ld",a,b);
}
