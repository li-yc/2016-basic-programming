//
//  黄可钊／组队编程.cpp
//  组队编程／快速排序
//
//  Created by lyc on 2016/12/12.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int suiji(int left, int right)
{
    srand((unsigned int)time(NULL)); /// 设置随机序列的种子
    return (unsigned int)rand() % (right - left + 1) + left;
}
void qsort(int *array, int left, int right)
{
    if (array[left] > array[right] && right - left == 1)
        swap(array[left], array[right]);
    if (right - left <= 1) return;
    int z = left, y = right, k = suiji(left, right)/*(left + right)/2*/;
    int m = array[k];
    int flag = 0;
    do
    {
        while ((z <= y) && (array[z] <= m))
        {
            if (z <= k) ++z;
            else
            {
                array[k] = array[z];
                ++k;
                ++z;
                flag = 1;
            }
        }
        int zm = array[z];
        while ((z <= y)&&(array[y] >= m))
        {
            if (y >= k) --y;
            else
            {
                array[k] = array[y];
                --k;
                --y;
                flag = 2;
            }
        }
        if (z <= y)
        {
            if (flag == 2)
            {
                array[z] = array[y];
                array[k] = zm;
                if (z < y)
                {
                    --k;
                    --y;
                }
            }
            else if (flag == 0)
            {
                array[z] = array[y];
                array[y] = zm;
            }
            else if (flag == 1)
            {
                array[k] = array[y];
                array[y] = zm;
                if (z < y)
                {
                    ++k;
                    ++z;
                }
            }
        }
    } while (z < y);
    array[k] = m;
    qsort(array, left, k - 1);
    qsort(array, k + 1, right);
}
void print(int *array, int num)
{
    for (int i = 0; i < num; ++i)
        cout << array[i] << ' ';
}
int main()
{
    int d[5] = { 1,2,7,4,5 };
    qsort(d, 0, 4);
    print(d, 5);
    cout << endl;
    int f[6] = { 2, 9, 3, 1, 2, 7 }; /// 7 added
    qsort(f, 0, 5);
    print(f, 6);
    cout << endl;
    int e[100];
    for (int i = 0; i <= 99; ++i)
    {
        e[i] = (unsigned int)rand();
    }/// 4 added
    qsort(e, 0, 99);
    print(e, 100);
    int i[10]={7,9,5,4,4,5,7,9,4,4};
    qsort(i,0,9);
    print(i,10);
}
