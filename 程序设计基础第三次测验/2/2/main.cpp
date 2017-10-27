//
//  main.cpp
//  2
//
//  Created by lyc on 2016/12/20.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
long long yueshu[1000000],num=0;
void qiuyueshu(long long s)
{
    int i;
    s = 2*s;
    for (i=3; i<=s/3; i++)
    {
        if (s % i == 0)
            yueshu[num++] = i;
    }
}
int main()
{
    long long s,sum=0,a,n,amax;  //  ndehe = n(n-1)/2
    cin >> s;
    amax = s/3;
    qiuyueshu(s);
    for (a=1; a<=amax; a++)
    {
        long long nmax = s/(a+1);
        for (n=0; n<num && yueshu[n]<=nmax; n++)
            if ((s-yueshu[n]*a) % (yueshu[n]*(yueshu[n]-1)/2) == 0)
                sum++;
    }
    cout << sum << endl;
    return 0;
}
