//
//  main.cpp
//  1330-矩阵乘方
//
//  Created by lyc on 2016/12/1.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
long long n[2][2],a[2][2],output=0,t=0;
void mod(long long mf, long long a[2][2])
{
    t += 1;
    if (t > 1)
    {
        a[0][0] = a[0][0] % mf;
        a[1][0] = a[1][0] % mf;
        a[0][1] = a[0][1] % mf;
        a[1][1] = a[1][1] % mf;
        t -= 2;
    }
}
void mul(long long a[2][2], long long a2[2][2], long long mf)
{
    long long c[2][2],j,k;
    for (j=0; j<2; j++)
        for (k=0; k<2; k++)
            c[j][k] = a[j][0]*a2[0][k] + a[j][1]*a2[1][k];
    for (j=0; j<2; j++)
        for (k=0; k<2; k++)
            a[j][k] = c[j][k];
    mod (mf, a);
}
void out(long long a[2][2])
{
    cout << a[0][0] << ' ' << a[0][1] << '\n' << a[1][0] << ' ' << a[1][1];
}
void cheng(long long bf, long long mf)
{
    long long j;
    if (bf==0)
    {
        if (mf==1)
            cout << "0 0\n0 0";
        else
            cout << "1 0\n0 1";
        output = 1;
    }
    else
    {
        if (bf%2 == 0)
        {
            cheng (bf/2, mf);
            mul (n, n, mf);
            mod (mf, n);
        }
        else
        {
            if (bf>2)
            {
                cheng (bf-1, mf);
                mod (mf, n);
                mul (n, a, mf);
                mod (mf, n);
            }
            else
                mod (mf, n);
        }
    }
}
int main() {
    long long i,b,m;
    cin >> b >> m;
    for (i=0; i<2; i++)
    {
        cin >> n[i][0] >> n[i][1];
        a[i][0] = n[i][0];
        a[i][1] = n[i][1];
    }
    mod (m, a);
    mod (m, n);
    cheng (b, m);
    if (!output)
        out(n);
    return 0;
}
