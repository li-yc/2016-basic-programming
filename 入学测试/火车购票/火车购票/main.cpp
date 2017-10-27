//
//  main.cpp
//  火车购票
//
//  Created by lyc on 2016/11/9.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int findseat(int * pf)  // pf = piaoform
{
    int pos = 0;
    while (pf[pos] == 0)
        pos += 1;
    return pos;
}
int main(int argc, const char * argv[]) {
    int n,i,j,k,piao[20],num,p; // p=position
    cin >> n;
    bool find;
    for (i=0; i<20; i++)
    {
        piao[i] = 5;
    }
    for (k=0; k<n; k++)
    {
        cin >> num;
        find = false;
        i = 0;
        while (!find)
        {
            if (piao[i] >= num)
            {
                find = true;
                for (j=0; j<num; j++)
                {
                    cout << i*5 + (6 - piao[i]) + j << ' ';
                }
                piao[i] = piao[i] - num;
                cout << endl;
                break;
            }
            if (i>=19)
            {
                j=0;
                for (j=num; j>0;j -= 1)
                {
                    p = findseat(piao);
                    cout << p*5 + (6-piao[p]) << ' ';
                    piao[p] -= 1;
                }
                cout << endl;
                break;
            }
            i += 1;
        }
    }
    return 0;
}

