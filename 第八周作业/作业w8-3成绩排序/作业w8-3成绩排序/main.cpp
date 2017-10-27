//
//  main.cpp
//  作业w8-3成绩排序
//
//  Created by lyc on 2016/11/3.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
struct score //  chain list
{
    int sn; //  student number
    int m;  //  maths
    int e;  //  english
    int c;  //  chinese
    score *next;  // next student in the order of score
}stu[100];  //  head is the head of the chain list
bool com(score st1,score st2){  //if (student1 > student2) return true
    if ((st1.m+st1.e+st1.c) > (st2.m+st2.e+st2.c))
        return true;
    if ((st1.m+st1.e+st1.c) < (st2.m+st2.e+st2.c))
        return false;
    if ((st1.m+st1.e+st1.c) == (st2.m+st2.e+st2.c))
    {
        if (st1.m>st2.m)
            return true;
        if (st1.m<st2.m)
            return false;
        if (st1.m==st2.m)
        {
            if (st1.e>st2.e)
                return true;
            if (st1.e<st2.e)
                return false;
            if (st1.e==st2.e)
            {
                if (st1.sn<st2.sn)
                    return true;
                if (st1.sn>st2.sn)
                    return false;
            }
        }
    }
    return false;
}
void in(score stud, int pos, int le) //  stud = student, pos = position
{
    int k;
    score a;
    for (k=le; k > pos; k--)
    {
        a = stu[k];
        stu[k] = stu[k-1];
        stu[k-1] = a;
    }
    stu[pos] = stud;
}
void insert(score st,int len){  //len = length of the string before st was inserted in
    int max=len-1,min=0;
    while (max>=min)
    {
        if (com(st, stu[(max+min)/2]))
            max = (max + min) / 2 - 1;
        else
            min = (max + min) / 2 + 1;
    }
    in(st, min, len);
}
int main() {
    int i,n;
    score a;
    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> a.m >> a.e >> a.c;
        a.sn = i+1;
        insert (a,i);
    }
    for (i=0; i<n; i++)
    {
        cout << stu[i].m << ' ' << stu[i].e << ' ' << stu[i].c << ' ' << stu[i].sn;
        cout << '\n';
    }
    return 0;
}
