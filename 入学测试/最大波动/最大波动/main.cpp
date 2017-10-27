//
//  main.cpp
//  最大波动
//
//  Created by lyc on 2016/11/9.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int i,n,a,b,c,max = 0;
    cin >> n >> a;
    for (i=1; i<n; i++)
    {
        cin >> b;
        if (a > b)
            c = a-b;
        else
            c = b-a;
        if (max < c)
            max = c;
        c = a;
        a = b;
        b = c;
    }
    cout << max;
    return 0;
}
