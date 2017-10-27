//
//  main.cpp
//  5
//
//  Created by lyc on 2016/11/22.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;
int a[1001][1001],n;
long sum=0,m=0;
void step(int x,int y)
{
    if (x>=n)
    {
        if (sum > m)
            m = sum;
    }
    else
    {
        sum += a[x][y];
        step(x+1,y);
        sum -= a[x][y];
        sum += a[x][y];
        step(x+1,y+1);
        sum -= a[x][y];
    }
}
long answer(const int nf)
{
    long l1[1001],sum=0,l2[1001];
    int k,l;
    for (k=0; k<1001; k++)
        l1[k] =  l2[k] = 0;
    l1[1] = a[1][1];
    for (k=2; k<=nf; k++)
    {
        for (l=1; l<=k; l++)
        {
            if (l1[l] > l1[l-1])
                l2[l] = l1[l] + a[k][l];
            else
                l2[l] = l1[l-1] + a[k][l];
        }
        for (l=1; l<=k; l++)
            l1[l] = l2[l];
    }
    for (k=1; k<=nf; k++)
        if (l1[k] > sum)
            sum = l1[k];
    return sum;
}
int main(int argc, const char * argv[]) {
    int i,j;
    cin >> n;
    for (i=1; i<=n; i++)
        for (j=1; j<=i; j++)
            cin >> a[i][j];
    //step(0,0);
    //cout << m;
    cout << answer(n);
    return 0;
}
