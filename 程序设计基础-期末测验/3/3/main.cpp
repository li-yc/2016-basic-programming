//
//  main.cpp
//  3
//
//  Created by lyc on 2017/1/12.
//  Copyright © 2017年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n,a[100],wei=0,last=-1,i;
    cin >> n;
    while (n>0)
    {
        a[wei] = n % 2;
        n = (n-a[wei]) / 2;
        if (a[wei] != 0 && last == -1)
            last = wei;
        wei++;
    }
    for (i=wei-1; i>=0; i--)
    {
        if (a[i] != 0)
        {
            cout << "2(" << i << ")";
            if (i != last)
                cout << '+';
        }
    }
    cout << endl;
    return 0;
}
