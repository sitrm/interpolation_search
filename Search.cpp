
#include <iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;


//критерий сравнения: (для типа int)
//массив должен быть отсортирован по убыванию
int comp1(const void* arg1, const void* arg2)
{
    int* a1 = (int*)arg1;
    int* a2 = (int*)arg2;
    if (*a1 > *a2) return -1;
    if (*a1 == *a2) return 0;
    return 1;
}
//критерий сравнения: сравниваем абсолютные значения
//(для типа double)
//массив должен быть отсортирован по возрастанию
//абсолютного значения
int comp2(const void* arg1, const void* arg2)
{
    double* a1 = (double*)arg1;
    double* a2 = (double*)arg2;
    if (abs(abs(*a1) - abs(*a2)) < DBL_EPSILON * abs(*a1)) return 0;
    if (abs(*a1) < abs(*a2)) return -1;
    return 1;
}

int main()
{
    const int k = -1;//что ищем
    double kd = -4.5;
    int a[10] = { 32,25,24,18,15,12,8,7,-1,-20 };
    double b[5] = { 1.8,-2.5,3.2,-5.4,-7.8 };
    int* ptr1;
    double* ptr2;
    //Бинарный поиск в массиве a
    ptr1 = (int*)bsearch(&k, a, 10, sizeof(int), comp1);
    if (ptr1 != 0) cout << *ptr1 << endl;
    else cout << "error" << endl;

    //Бинарный поиск в массиве b

    ptr2 = (double*)bsearch(&kd, b, 5, sizeof(double), comp2);
    if (ptr2 != 0) cout << *ptr2 << endl;
    else cout << "error" << endl;
  

    return 0;
}


