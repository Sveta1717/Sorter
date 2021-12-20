// Sorter.cpp : Создать класс Sorter, который будет содержать в себе статические методы, реализующие разные алгоритмы сортировки одномерных массивов 
//(Bubble, Insert, Select, Quick). Массивы могут быть любого типа, любых размеров(по количеству элементов).

#include <iostream>
#include <ctime>
using namespace std;

class Sorter
{
    int size; 
    int* arr;    

public:
        
    Sorter(int* _arr, int _size)
    {        
        Show(_arr, _size);
    }
    void Show(int* _arr, int _size)
    {
        if (_size <= 0)
        {
            arr = nullptr;
            size = 0;
            return;
        }
        size = _size;
        arr = new int[_size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = _arr[i];
        }
    }
    void SetArr(int* _arr)
    {        
        for (int i = 0; i < size; i++)
        {
            arr[i] = _arr[i];
        } 
    }    
    void SetSize(int size)
    {
        this->size = size;
    }
    ~Sorter()
    {
        if (arr != nullptr) delete[] arr;       
    }
    const int* const GetArr() const
    {
        return arr;
    }
    const int const GetSize() const
    {
        return size;
    }
    void Bubble(int size)
    {
        int tmp = 0;
        for (int i = 0; i < size; i++) {
            for (int j = (size - 1); j >= (i + 1); j--) {
                if (arr[j] < arr[j - 1]) {
                    tmp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = tmp;
                }
            }
        }
    }
    void Insert(int size)
    {
        int value = 0;
        int i = 0;
        for (int j = 1; j < size; j++) {
            value = arr[j];
            i = j - 1;
            while (i >= 0 && arr[i] > value) {
                arr[i + 1] = arr[i];
                i = i - 1;
                arr[i + 1] = value;
            }
        }
    }
    void Select(int size)
    {
        int j = 0;
        int tmp = 0;
        for (int i = 0; i < size; i++) {
            j = i;
            for (int k = i; k < size; k++) {
                if (arr[j] > arr[k]) {
                    j = k;
                }
            }
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    void Quick(int size)
    {       
        int m = 0;
        int index = size / 2;
        int i, j = 0, k = 0;
        if (size > 1) {
            int* start = new int[size];
            int* end = new int[size];
            m = arr[index];
            for (i = 0; i < size; i++) {
                if (i != index) {
                    if (arr[i] < m) {
                        start[j] = arr[i];
                        j++;
                    }
                    else {
                        end[k] = arr[i];
                        k++;
                    }
                }
            }          
        }        
    }
    void Print()
    {        
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};


int main()
{
    srand(time(0));
    const int size = 10;
    int arr[size];
    cout << "Array \n";
    for (int i = 0; i < size; i++) {

        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << "\n";

    Sorter* s = new Sorter(arr,10);
    cout << "Bubble \n";
    s->Bubble(size);
    s->Print();
    cout << "Insert \n";
    s->Insert(size);
    s->Print();
    cout << "Select \n";
    s->Select(size);
    s->Print();
    cout << "Quick \n";
    s->Quick(size);
    s->Print();
    cout << "\n\n";
}
