//
//  main.cpp
//  作业w8-4字典排序
//
//  Created by lyc on 2016/11/4.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main() {
    char s[100][257];
    char a[257];
    int n,i,j,p;
    cin >> n;
    for (i=0; i<n; i++)
        cin >> s[i];
    for (i=0; i<n-1; i++)
    {
        p = i;
        for (j=i+1; j<n; j++)
        {
            if (strcmp(s[j], s[p]) < 0)
                p = j;
        }
        strcpy(a, s[p]);
        strcpy(s[p], s[i]);
        strcpy(s[i], a);
    }
    for (i=0; i<n; i++)
        cout << s[i] << endl;
    return 0;
}
