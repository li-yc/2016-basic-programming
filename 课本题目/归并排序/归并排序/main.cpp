//
//  main.cpp
//  归并排序
//
//  Created by lyc on 2016/12/13.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int a[30],b[30];
void output(int begin, int end, int *an)
{
    int i;
    for (i=begin; i<=end; i++)
        cout << an[i] << ' ';
    cout << endl;
}
void sort3or2(int begin, int end)
{
    if (end-begin==2)
    {
        int min = begin;
        if (a[begin+1] < a[min])
            min ++;
        if (a[begin+2] < a[min])
            min = begin+2;
        swap(a[min], a[begin]);
    }
    if (a[end] < a[end-1])
        swap(a[end], a[end-1]);
}
void CombineSort(int begin, int end)
{
    if (end-begin<=3)
        sort3or2(begin, end);
    else
    {
        int p1 = 0, p2=(begin+end)/2, i=0, num=end-begin+1, *b=new int [num], mid=p2;
        CombineSort(begin, p2);
        CombineSort(++p2, end);
        for (i=0; p1<=mid && p2<=end; i++)
        {
            if (a[p1]<a[p2])
                b[i] = a[p1++];
            else
                b[i] = a[p2++];
        }
        if (p1==mid)
            for (; i<=end; i++)
                b[i]=a[p2++];
        else
            for (; i<=end; i++)
                b[i]=a[p1++];
        for (i=0; i<=end; i++)
            a[i] = b[i+begin];
        delete []b;
    }
}
int main()
{
    int i,n;
    cout << "Please input the number of numbers.\n";
    cin >> n;
    cout << "Please input numbers.\n";
    for (i=0; i<n; i++)
        cin >> a[i];
    CombineSort(0, n-1);
    output(0, n-1, a);
    return 0;
}
