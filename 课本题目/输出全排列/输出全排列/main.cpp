//
//  main.cpp
//  输出全排列
//
//  Created by lyc on 2016/12/19.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int n,digit[100];
bool nused[101];
void dg(int djgs)  //  djgs = di ji ge shu.
{
    int i=1;
    if (djgs >= n)
    {
        for (i=0; i<n; i++)
            cout << digit[i] << ' ';
        cout << endl;
    }
    else
        for (i=1; i<=n; i++)
            if (nused[i])
            {
                digit[djgs] = i;
                nused[i] = 0;
                dg(djgs+1);
                nused[i] = 1;
            }
}
int main()
{
    cout << "Please input 'n'" << endl;
    cin >> n;
    int i;
    for (i=0; i<101; i++)
        nused[i] = 1;
    dg(0);
    return 0;
}
