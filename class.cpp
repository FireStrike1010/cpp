#include<iostream>

using namespace std;


//Лабораторная работа № 1. Структура-пара
//18. Поле first – целое число, целая часть числа; поле second – положительное целое число, дробная часть числа.
//Реализовать метод multiply() – умножение на произвольное целое число типа int.
//Метод должен правильно работать при любых допустимых значениях first и second.

class Pair{
    public:
        Pair(double a){
            if (a < 0){
                neg = 1;
                a *= -1;
            }
            else{neg = 0;}
            first = a;
            second = a - first;
        }
        void multiply(int a){
            if (a < 0){
                a *= -1;
                if (neg){neg = 0;}
                else{neg = 1;}
            }
            if (a == 0){
                neg = 0;
                first = 0;
                second = 0.0;
                return;
            }
            first *= a;
            second *= a;
            int buf = second;
            first += buf;
            second -= buf;
        }
        double getPair(){
            double res = second;
            res += first;
            if (neg){res *= -1;}
            return res;
        }
    private:
        int first;
        double second;
        bool neg;
};

int main()
{
    double a;
    int b;
    cout << "Введите число";
    cin >> a;
    Pair number(a);
    cout << "Введено = " << number.getPair() << endl;
    cout << "Введите множитель";
    cin >> b;
    number.multiply(b);
    cout << "Ответ = " << number.getPair();
    return 0;
}
