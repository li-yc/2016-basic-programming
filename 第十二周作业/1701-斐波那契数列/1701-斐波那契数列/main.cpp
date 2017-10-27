//
//  main.cpp
//  1701-斐波那契数列
//
//  Created by lyc on 2016/12/1.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
long long a[31];
long long fn(int n)
{
    if (a[n] != 0)
        return a[n];
    else
    {
        a[n] = fn(n-1) + fn(n-2);
        return a[n];
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    int num;
    a[0] = a[1] = 1;
    while (cin >> num)
        cout << fn(num);
    return 0;
}
