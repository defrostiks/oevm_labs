#include <conio.h>
#include <iostream.h>
#include "stdio.h"
#include "stdlib.h"
#include "dos.h"
#include "time.h"  

union type
{
	unsigned long long ll;
	long double d;
};

void printLongDouble(long double x)
{
	type m;
	m.d = x;
	for (int i = 16 * sizeof(m.ll) - 1; i > -1; i--)
	{
		cprintf("%d", m.ll >> i & 1);
	}
	cprintf("\n\r");
}




void scroll(int direction, int lines, char l_row, char l_col, char r_row, char r_col, char attr)
{
	union REGS r;
	if (direction) 
	{
		r.h.al = lines;
		r.h.ah = direction;
	}
	else
	{
		r.h.al = lines;
		r.h.ah = 7; 
	}
	r.h.ch = l_row;
	r.h.cl = l_col;
	r.h.dh = r_row;
	r.h.dl = r_col;
	r.h.bh = attr;
	int86(0x10, &r, &r);
}




void GetPrintColor(unsigned char colors)
{
	unsigned char bg = colors >> 4;
	unsigned char text = colors & 15;

	switch (bg)
	{
	case 0:
		cprintf("1 ");
		break;
	case 1:
		cprintf("2 ");
		break;
	case 2:
		cprintf("3 ");
		break;
	case 3:
		cprintf("4 ");
		break;
	case 4:
		cprintf("5 ");
		break;
	case 5:
		cprintf("6 ");
		break;
	case 6:
		cprintf("7 ");
		break;
	case 7:
		cprintf("8 ");
		break;
	case 8:
		cprintf("9 ");
		break;
	case 9:
		cprintf("10 ");
		break;
	case 10:
		cprintf("11 ");
		break;
	case 11:
		cprintf("12 ");
		break;
	case 12:
		cprintf("13 ");
		break;
	case 13:
		cprintf("14 ");
		break;
	case 14:
		cprintf("15 ");
		break;
	case 15:
		cprintf("16 ");
		break;
	}
	switch (text)
	{
	case 0:
		cprintf("Black\r");
		break;
	case 1:
		cprintf("Blue\r");
		break;
	case 2:
		cprintf("Green\r");
		break;
	case 3:
		cprintf("Cian\r");
		break;
	case 4:
		cprintf("Red\r");
		break;
	case 5:
		cprintf("Purple\r");
		break;
	case 6:
		cprintf("Brown\r");
		break;
	case 7:
		cprintf("Light Grey\r");
		break;
	case 8:
		cprintf("Dark Grey\r");
		break;
	case 9:
		cprintf("Light blue\r");
		break;
	case 10:
		cprintf("Light Green\r");
		break;
	case 11:
		cprintf("Light Cyan\r");
		break;
	case 12:
		cprintf("Light Red\r");
		break;
	case 13:
		cprintf("Light Purple\r");
		break;
	case 14:
		cprintf("Yellow\r");
		break;
	case 15:
		cprintf("White\r");
		break;
	}
}

int main()
{
	char t;
	long double inputLongDouble;
	scroll(7, 0, 0, 0, 25, 80, 7);
	window(15, 5, 65, 15); 
	textattr(112);  
	scroll(7, 0, 0, 14, 4, 64, 14); 
	cprintf("\n\n\n\n\n\n\n\n\r");
	do {
		unsigned char i = 0;
		do
		{
			textattr(i);
			inputLongDouble = ((0.956358714) * (rand() % 12501));
			printLongDouble(inputLongDouble);
			GetPrintColor(i);
			i++;
			delay(400);  
			scroll(7, 0, 0, 14, 4, 64, 14); 
		} while (i < 127); 
		cprintf("who hext& (y - again / n - exit): ");
		do {
			cscanf("%c", &t);
		} while (t != 'y' && t != 'n');
	} while (t == 'y');
	cprintf("\n\r --------VALERY GRIGORIEV 3354--------\n\r");
	getch();
	return 0;
}
