#include<iostream>
#include<cmath>
using namespace std;

//Лабораторная работа №1. Исключения
//18.  Функция вычисляет расстояние между двумя точками P1(x1,y1) и P2(x2,y2) по формуле
//D=((x1-x2)2+(y1-y2)2)1/2
//Исключение генерируется, когда P1 и P2 - одна и та же точка.

int main(){
    double x1, x2, y1, y2;
    cout << "Введите координаты точки P1 (через пробел)";
    cin >> x1 >> y1;
    cout << "Введите координаты точки P2 (через пробел)";
    cin >> x2 >> y2;
    try{
        if (x1 == x2 && y1 == y2){
            throw 0;
        }
        double D = pow((pow((x1-x2), 2) + pow((y1-y2), 2)), 0.5);
        cout << "Расстояние равно " << D; 
    }
    catch(int i){
        cout << "Точки одинаковы";
    }
    return 0;
}