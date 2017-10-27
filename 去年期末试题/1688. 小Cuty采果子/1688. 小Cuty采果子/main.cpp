//
//  main.cpp
//  1688. 小Cuty采果子
//
//  Created by lyc on 2017/1/11.
//  Copyright © 2017年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n,p,q,i,a[21],m[21];  //  test
    cin >> n >> p >> q;
    for (i=1; i<=n; i++)
    {
        cin >> a[i];
        if (a[i]==-1)
            m[i] = -1;
        else
            m[i] = 0;
    }
    m[i] = a[1];
    for (i=1; i<=n; i++)
    {
        if (m[i]==-1 || ((i-p<=0 || m[i-p]==-1) &&(i-q<0 || m[i-q]==-1)))
        {
            m[i] = -1;
            continue;
        }
        if (i+p<=n && m[i+p]>=0 && m[i+p]<m[i]+a[i])
            m[i+p] = m[i] + a[i];
        if (i+q<=n && m[i+q]>=0 && m[i+q]<m[i]+a[i])
            m[i+q] = m[i] + a[i];
    }
    cout << (m[n]>-1 ? m[n]+a[n] : -1) << endl;
    return 0;
}
