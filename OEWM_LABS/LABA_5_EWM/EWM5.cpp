#include <dos.h>
#include <stdio.h>
#include <conio.h>

void interrupt(far* oldvect)(...);
volatile long ticks;
void interrupt far clava(...)
{
    ticks++; // Увеличиваем счетчик прерываний таймера
    if ((ticks % 20) == 0)
    {
        asm mov DL, 42
            asm mov AH, 2
            asm int 21h
    } // Если значение счетчика кратно 20, печатаем *
    _chain_intr(oldvect); // Вызываем старый обработчик прерывания
}

void main(void)
{
    clrscr();
    ticks = 0L;// Сбрасываем счетчик
    oldvect = _dos_getvect(0x1c);// Запоминаем адрес старого обработчика прерывания
    _dos_setvect(0x1c, clava);// Устанавливаем новый обработчик прерывания
    printf("\nTimer is installed\n");
    getch();
    _dos_setvect(0x1c, oldvect); // Восстанавливаем старый обработчик прерывания
}

