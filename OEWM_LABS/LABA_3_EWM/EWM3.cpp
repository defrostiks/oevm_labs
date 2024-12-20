#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

const float PI = 3.14159265358979323846;
const float START = 0; // Начало графика
const float END = 18 * PI; // 18π
const int NUMBER_OF_STEPS = 200;
const int AXIS_OFFSET = 300; // Смещение осей влево

// Функция для отображения
float myFunction(float x) {
    return pow(sin(x / 2), 3) + sqrt(x);
}

// Функция для установки осей
void putAxis() {
    int maxX = getmaxx();
    int maxY = getmaxy();
    int midX = maxX / 2 - AXIS_OFFSET; // Сдвинуть ось X влево
    int midY = maxY / 2;

    // Рисуем оси
    line(0, midY, maxX, midY); // Горизонтальная ось
    line(midX, 0, midX, maxY); // Вертикальная ось

    // Оси X
    for (int i = 0; i <= 18; ++i) {
        float xValue = i * (END / 18);
        int xCoord = midX + (xValue - 0) * (maxX / (END - 0)); // Масштабирование
        line(xCoord, midY - 5, xCoord, midY + 5); // Метка
        char label[10];
        sprintf(label, "%.1f", xValue);
        outtextxy(xCoord - 15, midY + 10, label);
    }

    // Оси Y
    for (int j = -10; j <= 10; ++j) {
        int yCoord = midY - j * (maxY / 20);
        line(midX - 5, yCoord, midX + 5, yCoord); // Метка
        char label[10];
        sprintf(label, "%d", j);
        outtextxy(midX + 10, yCoord - 10, label);
    }
}

// Функция для отрисовки графика
void drawGraph() {
    int maxX = getmaxx();
    int maxY = getmaxy();
    int midX = maxX / 2 - AXIS_OFFSET; // Сдвинуть ось X влево
    int midY = maxY / 2;

    float step = (END - START) / NUMBER_OF_STEPS;
    for (int i = 0; i < NUMBER_OF_STEPS - 1; ++i) {
        float x1 = START + i * step;
        float y1 = myFunction(x1);
        float x2 = START + (i + 1) * step;
        float y2 = myFunction(x2);

        // Преобразование координат
        int xCoord1 = midX + (x1 - 0) * (maxX / (END - 0)); // Масштабирование по оси X
        int yCoord1 = midY - (y1 * (maxY / 40)); // Масштабирование по оси Y
        int xCoord2 = midX + (x2 - 0) * (maxX / (END - 0)); // Масштабирование по оси X
        int yCoord2 = midY - (y2 * (maxY / 40)); // Масштабирование по оси Y

        // Проверка на выход за пределы окна
        if (yCoord1 >= 0 && yCoord1 <= maxY && yCoord2 >= 0 && yCoord2 <= maxY) {
            line(xCoord1, yCoord1, xCoord2, yCoord2);
        }
    }
}

int main() {
    int grDriver = DETECT, grMode;
    initgraph(&grDriver, &grMode, "C:\\TurboC3\\BGI");

    putAxis();
    drawGraph();

    getch();
    closegraph();
    return 0;
}
