//
//  main.cpp
//  3
//
//  Created by lyc on 2016/11/22.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;
bool prin[100001];
long prime[10000];
int main()
{
    long n,i,j,pn=0;
    cin >> n;
    memset(prin, 1, 100001);
    prin[0] = prin[1] = false;
    for (i=2; i*i<=100000; i++)
    {
        if (prin[i])
        {
            for (j=i*2; j<= 100000; j += i)
                prin[j] = false;
            prime[pn] = i;
            pn += 1;
        }
    }
    for (i=0; prime[i] != 0; i++)
    {
        if (prin[prime[i]+n])
        {
            cout << prime[i]+n << ' ' << prime[i];
            break;
        }
    }
    return 0;
}
