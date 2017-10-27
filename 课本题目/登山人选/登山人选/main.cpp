//
//  main.cpp
//  登山人选
//
//  Created by lyc on 2016/12/26.
//  Copyright © 2016年 lyc. All rights reserved.
//  第n个人的任务：爬到h【n】高度支援第n-1个人

#include <iostream>
using namespace std;
int fuzai[100],xiaohao[100],h[100],H,d[100],take[100],need[100],minman=10000,minfood=2^30,p;  //  负载，消耗
bool chosen[100];
void save1(int n)
{
    
}
void save2(int n)
{
    
}
void chooseman(int n)
{
    int man;
    for (man=0; man<p; man++)
    {
        need[n] = need[n-1] + xiaohao[man]*h[n];
        
        if (chosen[man])
            continue;
        if (d[n]>0)
        {
            if (n<minman || take[n]<minfood)
                chooseman(n+1);
        }
        else
        {
            if (n<minman || (n==minman && need[n]<minfood))
                save1(n);
            if (need[n]<minfood && (need[n]==minfood && n<minman))
                save2(n);
        }
    }
}
int main()
{
    int i;
    cin >> p >> H;
    for (i=0; i<p; i++)
        cin >> fuzai[i];
    for (i=0; i<p; i++)
        cin >> xiaohao[i];
    return 0;
}
