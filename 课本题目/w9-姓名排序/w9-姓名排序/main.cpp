//
//  main.cpp
//  w9-姓名排序
//
//  Created by lyc on 2016/11/8.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int strcmp1(char * s1, char * s2)  // if s1 is in front of s2, return 1. if s1 is behind s2, return -1. else return 0
{
    int k;
    for (k=0; (s1[k] != '\0' && s2[k] != '\0') ; k++)  // may have a bug because of bracket (括号)
    {
        if (s1[k] < s2[k] || s1[k] == 0)
            return 1;
        if (s1[k] > s2[k] || s2[k] == 0)
            return -1;
    }
    return 0;
}
int main(int argc, const char * argv[])
{
    int i,j,m,groupn;  // gn = group number, sn = singer number
    cout << "please input group number\n";
    cin >> groupn;
    const int gn = groupn;
    int sin[gn];  // sin = singer number
    char ** nl[gn];  // nl = namelist
    char * mid;
    cout <<"please imput singer number of each group\n";
    for (i=0; i<gn; i++)
    {
        cin >> sin[i];
        nl[i] = new char * [sin[i]];
        for (j=0; j<sin[i]; j++)
            nl[i][j] = new char[21];
    }
    cout << "请输入排序要求，1表示按照字典顺序升序，0表示降序";
    while ((i != '0') && (i != '1') && (i>=0))
        i = cin.get();
    if (i<0)
    {
        cout << "imput order failed\n";
        return -1;
    }
    cout << "please imput singer name of "<< gn << " groups\n";
    const bool ao = bool(i-48);  // ao = ascending order(升序).
    for (i=0; i<gn; i++)
        for (j=0; j<sin[i]; j++)
            cin >> nl[i][j];  // get input completed
    for (i=0; i<gn; i++)
        for (j=0; j<sin[i]-1; j++)
            for (m=sin[i]-2; m>=j; m--)
                if (strcmp1(nl[i][m+1], nl[i][m]) == ao*2-1)
                    {
                        mid = nl[i][m];
                        nl[i][m] = nl[i][m+1];
                        nl[i][m+1] = mid;
                    }
    for (i=0; i<gn; i++)
    {
        cout << "group" << i+1 << ":=\n";
        for (j=0; j<sin[i]; j++)
            cout << nl[i][j] << endl;
        cout << endl;
    }
    for (i=0; i<gn; i++)
    {
        for (j=0; j<sin[i]; j++)
            delete [] nl[i][j];
        delete [] nl[i];
    }
    return 0;
}
