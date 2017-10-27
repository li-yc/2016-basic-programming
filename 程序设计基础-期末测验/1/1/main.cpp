//
//  main.cpp
//  1
//
//  Created by lyc on 2017/1/12.
//  Copyright © 2017年 lyc. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int i,n,sum=0,a,numof3,i0;
    cin >> n;
    for (i=(n==1)? 1 : pow(10,n-1); i<pow(10, n); i++)
    {
        numof3 = 0;
        i0 = i;
        while (i0>=10)
        {
            a = i0 % 10;
            i0 = (i0-a)/10;
            if (a == 3)
            {
                numof3++;
            }
        }
        if (i0 == 3)
            numof3++;
        if (i == 132)
            a++;
        if (numof3 % 2 == 0)
        {
            sum++;
            //cout << i << ' ';  //  test
        }
    }
    cout << sum << endl;
    return 0;
}
