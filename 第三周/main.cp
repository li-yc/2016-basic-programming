//
//  main.cpp
//  作业w3-1
//
//  Created by lyc on 16/9/27.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int s=0,k=0;
    char tm;
    for (k=0;k<4;k++)
    {
        s=0;
        tm = 'A' + k;
        if (tm != 'A')
            s=s+1;
        if (tm == 'B')
            s=s+1;
        if (tm != 'B')
            s=s+1;
        if (tm == 'C')
            s=s+1;
        if (s == 3)
            cout << tm << endl;
    }
    return 0;
}
