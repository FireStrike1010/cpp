#include<iostream>
#include<vector>

using namespace std;
//18. Поменять местами первый минимальный и последний элементы.

int main()
{
    vector <int> v {5, 9, 8, 1, 2, 4};
    
    cout << "Начальный вектор\t";
    for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
    }
    
    int min = 999999;
    int min_index;
    for(int i = 0; i < v.size(); i++){
        if(v[i] < min){
            min = v[i];
            min_index = i;
        }
    }
    swap(v[min_index], v[v.size()-1]);
    
    cout << "\nИзмененный вектор\t";
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
    }
    
    return 0;
}
