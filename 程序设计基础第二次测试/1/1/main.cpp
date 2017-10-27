//
//  main.cpp
//  1
//
//  Created by lyc on 2016/11/22.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    int i,c=1,d=1;
    string a,b;
    cin >> a >> b;
    for (i=0; i<a.size(); i++)
        c = c*(a[i] - 'A'+1) % 47;
    for (i=0; i<b.size(); i++)
        d = d*(b[i] - 'A'+1) % 47;
    if (c==d)
        cout << "GO";
    else
        cout << "STAY";
    return 0;
}
