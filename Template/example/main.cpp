#include"myArray.hpp"
#include<iostream>
using namespace std;
void print(MyArray<int> arr)
{
    for(int i=0;i<arr.getSize();i++)
        cout << arr[i] << " ";
    cout << endl;
}
void test_1()
{
    MyArray<int> arr(10);
    for(int i=0;i<10;i++)
        arr.push_back(i);
    print(arr);
    MyArray<int> arr_2(arr);
    arr_2.pop_back();
    arr_2.pop_back();
    print(arr_2);
}

int main()
{
    test_1();
    return 0;
}