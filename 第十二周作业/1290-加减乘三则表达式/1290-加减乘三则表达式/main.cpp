//
//  main.cpp
//  1290-加减乘三则表达式
//
//  Created by lyc on 2016/11/30.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
/*long long a[51],b,ip,i;  // abandoned code.
char sign[51],c[101];
void js(int pf)  // 计算式子
{
    int i;
    for (i=0; i<pf; i++)
    {
        if (sign[i] == '+')
            a[0] += a[i+1];
        if (sign[i] == '-')
            a[0] -= a[i+1];
    }
    cout << a[0];
}
void multiply()
{
    
    a[ip] = b;
    b = 0;
    for (i=i; '0'<=c[i] && c[i]<='9' && i<strlen(c); (i)+=1)
        b = b*10 + c[i] - '0';
    if (i == strlen(c) || c[i] == '*')
        return;
    else
    {
        multiply();
    }
    sign[ip] *= b;
    ip += 1;
    b = 0;
}
int main()
{
    int i,ip=0,bcs;  // bcs = 被乘数
    for (i=0; i<50; i++)
        a[i] = 0;
    sign[0] = '+';
    cin>>c;
    for (i=0; i<strlen(c); i++)
    {
        if (c[i] == '+' || c[i] == '-')
        {
            sign[ip+1] = c[i];
            a[ip] = b;
            b = 0;
            ip += 1;
        }
        if ('0'<=c[i] && c[i]<='9')
            b = b*10 + c[i] - '0';
        if (c[i] == '*')
        {
            multiply();
        }
    }
    a[ip] = b;
    js(ip);
    return 0;
}*/
char c[101],sign[51];
int i=0,n=0;
long len;  // len = string length
long long a[51];
long long aton(char *ch, int s, int e)  // s = start, e = end.
{
    long long b=0,j;
    for (j=s; j<=e; j++)
        if (ch[j]>='0' && ch[j]<='9')
            b = b*10 + ch[j] - '0';
    return b;
}
int main()
{
    long long ans=0;
    int p1;
    cin >> c;
    len = strlen(c);
    sign[0] = '+';
    while (c[i+1]>='0' && c[i+1]<='9' && i+1<len)
        i += 1;
    a[0] = aton(c, 0, i);
    while (i<len)
    {
        i += 1;
        n += 1;
        sign[n] = c[i];
        p1 = i+1;
        while (c[i+1]>='0' && c[i+1]<='9' && i<len)
            i += 1;
        a[n] = aton(c, p1, i);
    }
    for (i=n; i>=0; i--)  // multiply
        if (sign[i] == '*')
            a[i-1] *= a[i];
    for (i=0; i<=n; i++)
    {
        if (sign[i] == '+')
            ans += a[i];
        if (sign[i] == '-')
            ans -= a[i];
    }
    cout << ans;
    return 0;
}
