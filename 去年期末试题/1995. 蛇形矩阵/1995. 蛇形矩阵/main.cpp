//
//  main.cpp
//  1995. 蛇形矩阵
//
//  Created by lyc on 2017/1/11.
//  Copyright © 2017年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n,x,y,a[21][21],p=1;
    cin >> n;
    for (x=2; x<=2*n; x++)
    {
        for (y=1; y<=n; y++)
            if (x-y>0 && x-y<=n)
                a[x-y][y] = p++;
        x++;
        for (y=n; y>=1; y--)
            if (x-y>0 && x-y<=n)
                a[x-y][y] = p++;
    }
    for (x=1; x<=n; x++)
    {
        for (y=1; y<=n; y++)
            cout << a[x][y] << ' ';
        cout << endl;
    }
    return 0;
}
