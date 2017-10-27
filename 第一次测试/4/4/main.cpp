//
//  main.cpp
//  4
//
//  Created by lyc on 2016/10/25.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
long choose(long n0, long m0)  {
    long i0 = 1;
    double a0=1;//  a0表示结果
    if ((m0 * n0 == 0) || (n0 <= m0))  return 1;
    else
    {
        for (i0 = n0;i0 >= n0-m0+1;i0 = i0 - 1)
            a0 = a0 * i0 / (n0+1-i0);
        return long(a0);
    }
}
int main(int argc, const char * argv[]) {
    unsigned int n,i,j,a[11]={1,0,1};
    cin >> n;
    for (i=3; i<=n; i++){
        a[i] = (i-1) * (a[i-1]+a[i-2]);
    }
    cout << a[n] <<endl;
    a[0] = 1;
    a[1] = 0;
    a[2] = 1;
    unsigned int p=2; //  p=排列数
    for (i=3; i<=n; i++){
        p = p*i;
        a[i] = p;
        for (j=1; j<=i; j++){
            a[i] -= choose(i, j) * a[i-j];
        }
    }
    cout << a[n] << endl;
    return 0;
}
