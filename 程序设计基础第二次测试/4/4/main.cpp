//
//  main.cpp
//  4
//
//  Created by lyc on 2016/11/22.
//  Copyright © 2016年 lyc. All rights reserved.
//
#include <iostream>
#include <math.h>
using namespace std;
int a[3],b[3],n;
int dis(int p, int q)
{
    if (p>q)
    {
        int g=p;
        p=q;
        q=g;
    }  // let q > p
    int d1=q-p,d2=n-q+p;
    if (d1<d2)
        return d1;
    else
        return d2;
    return -1;
}
bool near(int a1, int a2, int a3)
{
    int af[3] = {a1, a2, a3},m,c[3],d[3];
    for (m=0; m<3; m+=1)
    {
        c[m] = dis(af[m], a[m]);
        d[m] = dis(af[m], b[m]);
    }
    if ((d[0]<3 && d[1]<3 && d[2]<3) || (c[0]<3 && c[1]<3 && c[2]<3))
    //if ((d[0]<2 && d[1]<2 && d[2]<2) || (c[0]<2 && c[1]<2 && c[2]<2))  //test
        return 1;
    return 0;
}
int main(int argc, const char * argv[]) {
    int i,j,k,sum=0;
    cin >> n;
    for (i=0; i<3; i++)
        cin >> a[i];
    for (i=0; i<3; i++)
        cin >> b[i];
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            for (k=1; k<=n; k++)
            {
                if (near(i, j, k))
                {
                    //cout << i << ',' << j << ',' << k << ' ';
                    sum += 1;
                }
            }
    cout << sum;
    return 0;
}
