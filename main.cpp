#include<iostream>
#include<string>

using namespace std;

class LongLong{
    private:
        long low;
        unsigned long high;
    public:
        LongLong(string input){
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
        LongLong(unsigned long first, long second){
            high = first;
            low = second;
        }
        LongLong(){
            low = 0;
            high = 0;
        }
        LongLong(const LongLong &other){
            high = other.high;
            low = other.low;
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
        long long number(){
            return stoll(get_string());
        }
        LongLong operator+(LongLong other){
            long long result = this -> number() + other.number();
            return LongLong(to_string(result));
        }
        LongLong operator-(LongLong other){
            long long result = this -> number() - other.number();
            return LongLong(to_string(result));
        }
        LongLong operator*(LongLong other){
            long long result = this -> number() * other.number();
            return LongLong(to_string(result));
        }
        LongLong operator/(LongLong other){
            long long result = this -> number() / other.number();
            return LongLong(to_string(result));
        }
        LongLong operator%(LongLong other){
            long long result = this -> number() % other.number();
            return LongLong(to_string(result));
        }
};

int main()
{
    LongLong x = LongLong("-23512293475092345");
    LongLong y = LongLong("1234567890");
    LongLong z = x * y;
    cout << z.number();
    return 0;
}
