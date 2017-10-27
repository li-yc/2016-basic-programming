//
//  main.cpp
//  3
//
//  Created by lyc on 2016/10/25.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    unsigned int i,n,c,m,w[4],p[4]; // c=count, m=murder, w=word
    cin >> n;
    for (i=1; i<=3; i++)
        cin >> w[i] >> p[i];
    for (m=1; m<=3; m++){
        c = 0;
        for (i=1; i<=3; i++){
            if (((w[i] != m) && (p[i] == 1)) || ((w[i] == m) && (p[i] == 0)))
                c++;
        }
        if (c == n)
            cout << m;
    }
    return 0;
}
