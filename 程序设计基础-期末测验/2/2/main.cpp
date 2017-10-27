//
//  main.cpp
//  2
//
//  Created by lyc on 2017/1/12.
//  Copyright © 2017年 lyc. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
long long x,y,n,sum,a[501][501],num=0,px[4]={0,1,0,-1},py[4]={1,0,-1,0},b[1000000];
void rotate(long long level)
{
    if (level == 0)
        return;
    if (level == 1)
    {
        a[x][y] = b[num];
        if (x+y==n-1 || x==y)
            sum += b[num];
        return;
    }
    int i,j;
    for (i=0; i<4; i++)
    {
        for (j=0; j<level-1; j++)
        {
            a[x][y] = b[num];
            if (x+y==n-1 || x==y)
                sum += b[num];
            x += px[i];
            y += py[i];
            num++;
        }
    }
    x++;
    y++;
    rotate(level-2);
}
int main()
{
    cin >> n;
    int i;
    for (i=0; i<n*n; i++)
    {
        cin >> b[i];
    }
    rotate(n);
    cout << sum << endl;
    return 0;
}
