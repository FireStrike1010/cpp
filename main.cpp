#include<iostream>

using namespace std;

template <typename Type>
struct Element{
    Type data;
    Element<Type> *next;
};

template <typename Type>
class List{
    private:
        Element<Type> *begin;
        int lenght;
    public:
        List(){
            begin = NULL;
            lenght = 0;
        }
        ~List(){
            delete_List(begin);
        }
        void delete_List(Element<Type> *elem){
            if (elem != NULL){
                delete_List(elem -> next);
                delete elem;
            }
        }
        int len(){
            return lenght;
        }
        void print(){
            if (begin == NULL){
                cout << "[]\n";
            }
            else{
                Element<Type> *iter = begin;
                cout << "[" << begin -> data;
                while (true){
                    if (iter -> next == NULL){
                        cout << "]\n";
                        return;
                    }
                    iter = iter -> next;
                    cout << ", " << iter -> data;
                }
            }
        }
        int get_index(Type value){
            if (begin == NULL){
                return -1;
            }
            Element<Type> *iter = begin;
            for (int i = 0; i < lenght; i++){
                if (iter -> data == value){
                    return i;
                }
                iter = iter -> next;
            }
            return -1;
        }
        Element<Type>* get_elem(int index){
            if ((index + 1) > lenght){
                cout << "Ошибка: Индекс " << index << " за пределами (0, " << lenght-1 << ") списка\n";
                return NULL;
            }
            Element<Type> *iter = begin;
            for (int i = 0; i < index; i++){
                iter = iter -> next;
            }
            return iter;
        }
        Type get_data(int index){
            Element<Type> *elem = get_elem(index);
            if (elem != NULL){
                return elem -> data;
            }
            return NULL;
        }
        void insert(Type value, int index){
            if (index == 0){
                Element<Type> *elem = new Element<Type>;
                elem -> data = value;
                elem -> next = begin;
                begin = elem;
            }
            else if(index >= lenght){
                cout << "Ошибка: Индекс " << index << " за пределами (0, " << lenght-1 << ") списка\n";
                cout << "Воспользуйтесь append(значение), чтобы добавить значение в конец списка\n";
            }
            else{
                Element<Type> *elem = new Element<Type>;
                elem -> data = value;
                elem -> next = get_elem(index);
                Element<Type> *buf = get_elem(index-1);
                buf -> next = elem;
                lenght ++;
            }
        }
        void append(Type value){
            if (begin == NULL){
                begin = new Element<Type>;
                begin -> data = value;
                begin -> next = NULL;
                lenght ++;
            }
            else{
                Element<Type> *iter = begin;
                while (true){
                    if (iter -> next == NULL){
                        iter -> next = new Element<Type>;
                        iter -> next -> data = value;
                        iter -> next -> next = NULL;
                        lenght ++;
                        return;
                    }
                    iter = iter -> next;
                }
            }
        }
        void delete_value(int index){
            if (index == 0){
                Element<Type> *del = begin;
                begin = begin -> next;
                lenght --;
                delete del;
            }
            else{
                Element<Type> *elem = get_elem(index-1);
                Element<Type> *del = elem -> next;
                elem -> next = elem -> next -> next;
                lenght --;
                delete del;
            }
        }
};

int main()
{
    List<float> *list = new List<float>();
    list -> append(4.6);
    list -> append(2.2);
    list -> print();
    cout << "Вставляем 3.9 в индекс 1" << endl;
    list -> insert(3.9, 1);
    list -> print();
    cout << "Удаляем значение под индексом 2" << endl;
    list -> delete_value(2);
    list -> print();
    cout << "Длина списка - " << list -> len() << endl;
    cout << "Элемент списка под индексом 1 - " << list -> get_data(1) << endl;
    cout << "Индекс элемента со значением 4.6 - " << list -> get_index(4.6) << endl;
    delete list;
    return 0;
}
