//  completed
//  main.cpp
//  快速排序
//  使用了随机选择参照数字的办法
//  Created by lyc on 2016/11/15.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
/*int b[1000000];  //  test
void quickarr(int p1f, int p2f, int a[])  // p1, p2 are pinoters
{
    
    int p1 = p1f,p2 = p2f,k;  //  test
    if (p1>p2)
        return;
    k = a[p1];
    while (p1<p2)
    {
        while (a[p2]>=k && p1<p2)
            p2--;
        a[p1] = a[p2];
        while (a[p1]<=k && p1<p2)
            p1++;
        a[p2] = a[p1];
    }
    a[p1] = k;
    if (p1+1 < p2f)
        quickarr(p1+1, p2f, a);
    if (p1f+1 < p1)
        quickarr(p1f, p1-1, a);
}
int main()
{
    int n,i;
    cout << "please imput data number\n";
    cin >> n;
    cout << "please imput numbers\n";
    for (i=0; i<n; i++)
        scanf("%d",&b[i]);
    quickarr(0, n-1, b);
    for (i=0; i<n; i++)
        cout << b[i] << ' ';
    return 0;
}*/
#include<iostream>
using namespace std;
int a[100005];
void quicksort(int left,int right)
{
    int i,j,base;
    i=left; j=right;
    base=a[(i+j)/2];
    while (i<=j){
        while (a[i]<base) i++;
        while (a[j]>base) j--;
        if (i<=j){
            int t=a[i]; a[i]=a[j];a[j]=t;
            i++;
            j--;
        }
    }
    if (left<j) quicksort(left,j);
    if (i<right) quicksort(i,right);
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    quicksort(0,n-1);
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
