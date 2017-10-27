//  uncompleted
//  main.cpp
//  作业w8-2合质数排序
//
//  Created by lyc on 2016/11/2.
//  Copyright © 2016年 lyc. All rights reserved.
//
#include <iostream>
#include <memory.h>
using namespace std;
int a[302],b[302];  //a is prime
void de(int *pf, int *af){
    int w,x;
    for(w=0; w<*pf-1; w++)
        if (af[w] == af[w+1]){
            for (x=w+1; x<*pf-1; x++)
                af[x] = af[x+1];
            *pf -= 1;
        }
}
void paixu(long m0, long n0, int *af){
    if (m0>n0){
        long a0;
        a0 = m0;
        m0 = n0;
        n0 = a0;
    }
    long i0,j0;
    int b0;
    for (i0 = n0;i0 > m0;i0--){
        for (j0 = m0;j0 < i0;j0++)
            if (af[j0] > af[j0+1]){
                b0 = af[j0];
                af[j0] = af[j0+1];
                af[j0+1] = b0;
            };
    }
}
//  使用折半查找，尝试使用链表来储存所有的质数，合数
void in(int *af, int cf, int pf){  //  in = insert number in the order of from min to max
    af[pf] = cf;
}
int main() {
    int c,n,i,j;
    int pa=0,pb=0;
    bool prime[10001];
    cin >> n;
    memset(prime, true, 10001);
    for(i=2; i<100; i++){
        if (prime[i])
            for(j=i*2; j<10001; j+=i)
                prime[j] = false;
    }
    for(i=0; i<n; i++){
        cin >> c;
        if (c>1){
            if (prime[c]){
                in(a,c,pa);
                pa++;
            }
            else{
                in(b,c,pb);
                pb++;
            }
        }
    }
    paixu(0, pa-1, a);
    paixu(0, pb-1, b);
    
//    de(&pa, a);
//    de(&pb, b);
    for(i=pb-1; i>-1; i--)
        cout << b[i] << ' ';
    cout << endl;
    for(i=0; i<pa; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
