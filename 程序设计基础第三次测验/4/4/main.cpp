//
//  main.cpp
//  4
//
//  Created by lyc on 2016/12/20.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int a,b,p[2000]={1},hws[500000],num=0,pn=0;  //  hws = hui wen shu
void getprime()
{
    int i,j;
    bool prime[10001];
    for (i=2; i<10001; i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (i=2; i<=100; i++)
        if (prime[i])
            for (j=2*i; j<=10000; j+=i)
                prime[j] = 0;
    for (i=2; i<10001; i++)
        if (prime[i])
            p[pn++] = i;
}
void bab(int m)
{
    if (a<=m && m<=b)
        hws[num++] = m;
}
int reverse2(int a)
{
    int d[6],b=a,i,j;
    for (i=0; b>0; i++)
    {
        d[i] = b%10;
        b = b/10;
    }
    for (j=i-1; j>=0; j--)
    {
        a += d[j] * 10^(2*i-j-1);
    }
    return a;
}
int reverse1(int a)
{
    int d[6],b=a,i,j;
    for (i=0; b>0; i++)
    {
        d[i] = b%10;
        b = b/10;
    }
    for (j=i-2; j>=0; j--)
    {
        a += d[j] * 10^(2*i-j-2);
    }
    return 0;
}
void gethuiwenshu(int a, int b)
{
    int a1,a2,a3,a4,a5;
    for (a1=1; a1<10; a1++)
        bab(a1);
    for (a1=1; a1<10; a1++)
        bab(a1*10+a1);
    for (a1=1; a1<10; a1++)
        for (a2=0; a2<10; a2++)
            bab(a1*101+a2*10);
    for (a1=1; a1<10; a1++)
        for (a2=0; a2<10; a2++)
            bab(a1*1001+a2*110);
    for (a1=1; a1<10; a1++)
        for (a2=0; a2<10; a2++)
            for (a3=0; a3<10; a3++)
                bab(a1*10001+a2*1010+a3*100);
    for (a1=1; a1<10; a1++)
        for (a2=0; a2<10; a2++)
            for (a3=0; a3<10; a3++)
                bab(a1*100001+a2*10010+a3*1001);
    for (a1=1; a1<10; a1++)
        for (a2=0; a2<10; a2++)
            for (a3=0; a3<10; a3++)
                for (a4=0; a4<10; a4++)
                    bab(a1*1000001+a2*100010+a3*10100+a4*1000);
    for (a1=1; a1<10; a1++)
        for (a2=0; a2<10; a2++)
            for (a3=0; a3<10; a3++)
                for (a4=0; a4<10; a4++)
                    bab(a1*10000001+a2*1000010+a3*100100+a4*11000);
/*    int i;
    for (i=1; i<10; i++)
        bab(reverse1(i));
    for (i=1; i<10; i++)
        bab(reverse2(i));
    for (i=10; i<10; i++)
        bab(reverse1(i));
    for (i=1; i<10; i++)
        bab(reverse2(i));*/
}  //  not completed.
bool isprime(int a)
{
    int i;
    for (i=0; i<pn; i++)
        if (a%p[i] == 0 && a!=p[i])
            return 0;
    return 1;
}
int main()
{
    int i;
    cin >> a >> b;
    getprime();
    gethuiwenshu(a, b);
    for (i=0; i<num; i++)
        if (isprime(hws[i]))
            cout << hws[i] << endl;
    return 0;
}
