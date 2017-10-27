//
//  main.cpp
//  4
//
//  Created by lyc on 2017/1/12.
//  Copyright © 2017年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
long long a[1000];
int n;
void paixu(int num)
{
    if (num>=n)
        return;
    int i;
    long long m=num;
    for (i=num; i<n; i++)
    {
        if (a[i] < a[m])
            m = i;
    }
    cout << "swap(a[" << num << "], a[" << m << "]):";
    swap(a[num], a[m]);
    for (i=0; i<n; i++)
        cout << a[i] << ' ';
    cout << endl;
    paixu(num+1);
}
int main()
{
    int i;
    cin >> n;
    for (i=0; i<n; i++)
        cin >> a[i];
    paixu(0);
    return 0;
}
