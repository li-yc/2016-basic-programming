//
//  main.cpp
//  1994. 炒股
//
//  Created by lyc on 2017/1/11.
//  Copyright © 2017年 lyc. All rights reserved.
//

#include <iostream>
#include <fstream>
int max1(int a, int b)
{
    return (a>b ? a : b);
}
using namespace std;
int main()
{
    ifstream fin("stock.in");
    ofstream fout("stock.out");
    int i,n,stock,earn[10000][2];
    cin >> n >> stock;
    earn[0][1] = -stock;
    for (i=1; i<n; i++)
    {
        cin >> stock;
        earn[i][0] = max1(earn[i-1][0], earn[i-1][1]+stock);
        earn[i][1] = max1(earn[i-1][1], earn[i-1][0]-stock);
    }
    cout << earn[n-1][0] << endl;
    return 0;
}
