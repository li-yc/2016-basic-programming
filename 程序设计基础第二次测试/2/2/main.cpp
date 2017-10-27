//
//  main.cpp
//  2
//
//  Created by lyc on 2016/11/22.
//  Copyright © 2016年 lyc. All rights reserved.
//
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int comp(int a0, int b0)
{
    if (a0>b0)
        return 0;
    return 1;
}
int main(int argc, const char * argv[]) {
    int i,n, *a;
    a = new int [n];
    float mid;
    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n, comp);
    if (n%2)
        mid = a[(n+1)/2-1];
    else
        mid = float(a[n/2] + a[n/2-1]) / 2;
    printf("%.2f", mid);
    return 0;
}
