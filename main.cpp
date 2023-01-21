#include<iostream>
#include<string>

using namespace std;


//Во всех заданиях, помимо указанных в задании операций, обязательно должны быть реализованы следующие методы:
//– метод инициализации init;
//– ввод с клавиатуры read;
//– вывод на экран display;
//– преобразование в строку toString.

//Все задания должны быть реализованы двумя способами:
//- тип данных представляется структурой с необходимыми полями, а операции реализуются как внешние функции, которые получают объекты данного типа в качестве аргументов;
//– как класс с закрытыми полями, где операции реализуются как методы класса.

//18. Создать класс LongLong для работы с целыми числами из 64 бит. Число должно быть представлено двумя полями: long – старшая часть,
//unsigned long – младшая часть. Должны быть реализованы арифметические операции, присутствующие в С++ (без присваивания), и сравнения.

struct LongLongs{
    long low;
    unsigned long high;
}



class LongLongc{
    private:
        long low;
        unsigned long high;
    public:
        LongLongc(string input){
            int neg = 1;
            if (input[0] == '-'){
                neg = neg - 2;
                input = input.substr(1);
            }
            if (input.length() < 9){
                low = stol(input) * neg;
                high = 0;
            }
            else{
                low = stol(input.substr(input.length() - 9, input.length())) * neg;
                high = stol(input.substr(0, input.length() - 9));
            }
        }
        LongLongc(){
            low = 0;
            high = 0;
        }
        void read(){
            string input{};
            cout << "Введите число\n";
            getline(cin >> ws, input);
            int neg = 1;
            if (input[0] == '-'){
                neg = neg - 2;
                input = input.substr(1);
            }
            if (input.length() < 9){
                low = stol(input) * neg;
                high = 0;
            }
            else{
                low = stol(input.substr(input.length() - 9, input.length())) * neg;
                high = stol(input.substr(0, input.length() - 9));
            }
        }
        string get_string(){
            int neg = 1;
            if (low < 0){neg = neg - 2;}
            string number = to_string(low*neg);
            if (high != 0){
                for (int i = number.length(); i<9; i++){
                    number = "0" + number;
                }
                number = to_string(high) + number;
            }
            if (neg == -1){
                number = "-" + number;
            }
            return number;
        }
        void display(){
            cout << "high: " << high << "\t" << "low: " << low << "\n";
        }
        long long number(){
            return stoll(get_string());
        }
        LongLongc operator+(LongLong other){
            long long result = this -> number() + other.number();
            return LongLong(to_string(result));
        }
        LongLongc operator-(LongLong other){
            long long result = this -> number() - other.number();
            return LongLong(to_string(result));
        }
        LongLongc operator*(LongLong other){
            long long result = this -> number() * other.number();
            return LongLong(to_string(result));
        }
        LongLongc operator/(LongLong other){
            long long result = this -> number() / other.number();
            return LongLong(to_string(result));
        }
        LongLongc operator%(LongLong other){
            long long result = this -> number() % other.number();
            return LongLong(to_string(result));
        }
};

int main()
{
    LongLong x = LongLong("-23512293475092345");
    x.display();
    LongLong y = LongLong("345");
    LongLong z = x * y;
    cout << z.number();
    return 0;
}
