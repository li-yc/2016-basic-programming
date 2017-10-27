//
//  main.cpp
//  1283-N皇后问题
//
//  Created by lyc on 2016/12/1.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int cpq[10][10];  //  cpq = cannot place quene. br = break.
int ans=0,n;  //  queen = -1 means no queen.
//  version 1
/*int queen[10];
 bool check(int x, int y)
 {
 int i;
 for (i=0; i<x; i++)
 if (y == queen[i] || x+y == queen[i]+i || x-y == i-queen[i])
 return 0;
 return 1;
 }
 void place(int m)
 {
 int k;
 if (m >= n)
 {
 ans += 1;
 return;
 }
 for (k=0; k<n; k++)
 {
 if (check(m, k) && !cpq[m][k])
 {
 queen[m] = k;
 place(m+1);
 }
 }
 }
 int main()
 {
 int i,j;
 cin >> n;
 for (i=0; i<n; i++)
 {
 for (j=0; j<n; j++)
 cin >> cpq[i][j];
 queen[i] = -1;
 }
 place(0);
 cout << ans;
 return 0;
 }*/
//  version 2
void add(int x, int y, int a)  //  add a.
{
    int i;
    for (i=x+1; i<n; i++)
    {
        cpq[i][y] += a;
        if (x+y-i>=0)
            cpq[i][x+y-i] += a;
        if (i-x+y<n)
            cpq[i][i-x+y] += a;
    }
}
void tp(int m)  //  try position.
{
    int k;
    if (m >= n)
    {
        ans += 1;
        return;
    }
    for (k=0; k<n; k++)
    {
        if (!cpq[m][k])
        {
            add(m, k, 1);
            tp(m+1);
            add(m, k, -1);
        }
    }
}
int main()
{
    int i,j;
    cin >> n;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            cin >> cpq[i][j];
    tp(0);
    cout << ans;
    return 0;
}
