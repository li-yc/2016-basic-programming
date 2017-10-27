//
//  main.cpp
//  作业w8-2合质数排序（新）
//
//  Created by lyc on 2016/11/3.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;
int a[302],b[302];
void ins(int *d, int pos, int len, int number){
    int q;
    for(q=len+1; q>pos; q--)
        d[q] = d[q-1];
    d[pos] = number;
}
bool in(int *f, int nu, int le){  //  le=length, nu=number, p=position
    int p=1;
    if (f[0] == nu)
        return false;
    if (f[0] < nu){
        ins(f,0,le,nu);
        return true;
    }
    while (!((f[p-1]>nu) && (f[p]<nu))){
        if (f[p] == nu)
            return false;
        p+=1;
    }
    ins(f, p, le, nu);
    return true;
}
int main(){
    int c,n,i,j;
    int pa=0,pb=0;
    bool prime[10001];
    cin >> n;
    memset(prime, true, 10001);
    for(i=2; i<100; i++)
    {
        if (prime[i])
            for(j=i*2; j<10001; j+=i)
                prime[j] = false;
    }
    for(i=0; i<n; i++)
    {
        cin >> c;
        if (c>1)
        {
            if (prime[c])
            {
                if (pa != 0){
                    if(in(a,c,pa))
                        pa++;
                }
                else{
                    a[0] = c;
                    pa++;
                }
            }
            else
            {
                if (pb != 0)
                {
                    if(in(b,c,pb))
                        pb++;
                }
                else
                {
                    b[0] = c;
                    pb++;
                }
            }
        }
    }
    for(i=0; i<pb; i++)
    {
        cout << b[i] << ' ';
    }
    cout << endl;
    for(i=pa-1; i>=0; i--)
    {
        cout << a[i] << ' ';
    }
    return 0;
}
