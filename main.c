#include <stdio.h>

//Лабораторная работа №1. Ввод и вывод данных
//18. Даны три точки A, B, C на числовой оси. Точка C расположена между точками A и B. Найти произведение длин отрезков AC и BC.
float multi(float a, float b, float c)
{
    float x = (c-a) * (b-c);
    return(x);
}

int main()
{
    float a1, b1, c1;
    printf("Введите координаты трех точек через пробел (например - 2.5 8.3 3.0) \n");
    scanf("%a %a %a", &a1, &b1, &c1);
    float x1 = multi(a1, b1, c1);
    printf("Произведение AC * CB = %f \n", x1);

    return(0);
}