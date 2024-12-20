#include <stdio.h>
#include <conio.h>
#include <bios.h>
#include <dos.h>

#define ESCAPE 27
#define UP 72
#define DOWN 80

#define LEFT 75
#define RIGHT 77

#define X1 15
#define X2 65
#define Y1 5
#define Y2 15
int keypressed()
{

	union REGS r;

	r.h.ah = 0x0B;

	int86(0x21, &r, &r);

	return r.h.al;

}

int getKey()

{

	union REGS r;

	r.h.ah = 0x7;

	int86(0x21, &r, &r);

	return r.h.al;

}
int main()
{
	int x, y, ch;
	x = y = 1;
	window(X1, Y1, X2, Y2);
	textbackground(7);
	textcolor(4);
	_setcursortype(_NOCURSOR);
	gotoxy(x, y);
	clrscr();
	printf("*");
	gotoxy(x, y);
	do {
		ch = getKey();
		if (ch == 0 || ch == 224) {
			switch (getKey()) {
			case LEFT:
				clrscr();
				if (x - 1 >= 1) {
					x--;
					gotoxy(x, y);
					printf("*");
					gotoxy(x, y);
				}
				else {
					x = X2 - X1 + 1;
					gotoxy(x, y);
					printf("*");
					gotoxy(x, y);
				}
				break;
			case RIGHT:
				clrscr();
				if (x + 1 <= (X2 - X1) + 1) {
					x++;
					gotoxy(x, y);
					printf("*");
					gotoxy(x, y);
				}
				else {
					x = 1;
					gotoxy(x, y);
					printf("*");
					gotoxy(x, y);
				}
				break;
			}
		}
	} while (ch != ESCAPE);

	return 0;
}
