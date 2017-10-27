//
//  main.cpp
//  插入乘号
//
//  Created by lyc on 2016/12/5.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
float num[100]={0};
short dig[100];
int dp[100];  //  digit position.
float stof(int l, int r)
{
    float b=0;
    int i;
    for (i=l; i<=r; i++)
        b += float(dig[i]) * pow(0.1, i-l);
    return b;
}
int main()
{
    int k;
    cin >> k;
    int i,nod[10]={0},t=k,j,point=-1;  //  nod = nouber of digits.
    dig[0] = getchar();
    dig[0] = getchar()-'0';
    for (i=0; 0<=dig[i] && dig[i]<=9; i++)
        dig[i+1] = getchar() - '0';
    const long len = i;
    dig[i] = 0;
    bool cheng[len];
    memset(cheng, 0, len);
    for (j=0; j<len; j++)
        nod[dig[j]]++;
    for (j=9; t>=nod[j]; j--)  //  Find biggest numbers and put '*' behind them.
        t -= nod[j];
    for (i=0; i<len; i++)
    {
        if (dig[i] > j)
            cheng[i] = 1;
        else
            if (dig[i] == j)
                dp[++point] = j;
    }
    for (i=0; i<t; i++)  //  Put the last t '*'.
        
    return 0;
}
