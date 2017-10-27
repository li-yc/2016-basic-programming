//
//  main.cpp
//  组队编程／快速排序
//
//  Created by lyc on 2016/12/12.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int e[100] = { 7, 9, 5, 4, 4, 5, 7, 9, 4, 4 };
void print(int *array, int num)
{
    for (int i = 0; i < num; ++i)
        cout << array[i] << ' ';
    cout << endl;
}
int suiji(int left, int right)
{
    srand((unsigned int)time(NULL)); /// 设置随机序列的种子
    return (unsigned int)rand() % (right - left + 1) + left;
}
void qsort(int *array, int left, int right)
{
    if(right-left<=1) return;
    int z = left, y = right, k = (left + right)/2, /*suiji(left, right),*/ m = array[k], flag=0;  //  test
    do
    {
        while (z <= y && array[z] <= m)
        {
            if (z <= k) ++z;
            else
            {
                array[k] = array[z];
                ++z;
                ++k;
                flag = 1;
            }
        }
        int zm = array[z];
        while (z <= y && array[y] >= m)
        {
            if (y >= k) --y;
            else
            {
                array[k] = array[y];
                --y;
                --k;
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
        print(e, 10);  //  test
    } while (z < y);
    array[k] = m;
    qsort(array, left, k - 1);
    qsort(array, k + 1, right);
}
int main()
{
    qsort(e, 0, 9);
    print(e, 10);
}
