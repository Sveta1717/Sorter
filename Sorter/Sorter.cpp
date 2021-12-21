// Sorter.cpp : Создать класс Sorter, который будет содержать в себе статические методы, реализующие разные алгоритмы сортировки одномерных массивов 
//(Bubble, Insert, Select, Quick). Массивы могут быть любого типа, любых размеров(по количеству элементов).

#include "Libraries.h"

template <class T>

class Sorter
{    
public:    

    static void Bubble(T arr[], int size)
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
            cout << arr[i] << " ";
        }              
    }
    static void Insert(T arr[], int size)
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
            cout << arr[i] << " ";
        }       
    }
    static void Select(T arr[], int size)
    {
        int j = 0;
        T tmp = 0;
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
            cout << arr[i] << " ";
        }        
    }
    static void Quick(T arr[], int size)
    {
        T m = 0;
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
                cout << arr[i] << " ";
            }
        }        
    }  
};
int main()
{
    srand(time(0));
    const int size = 10;
    int arr[size];
    cout << "Array \n";
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << "\n";    
    cout << "Bubble\n";
    Sorter<int>::Bubble(arr, 10);
    cout << "\n"; 
    cout << "Insert\n"; 
    Sorter<int>::Insert(arr, 10);
    cout << "\n";
    cout << "Select\n";
    Sorter<int>::Select(arr, 10);
    cout << "\n";
    cout << "Quick\n";
    Sorter<int>::Quick(arr, 10);
    cout << "\n\n";
}