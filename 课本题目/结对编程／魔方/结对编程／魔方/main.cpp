//
//  main.cpp
//  结对编程／魔方
//
//  Created by lyc on 2016/12/13.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;
struct cube
{
    int color[6][9];
};
void describe_digit(cube *c)
{
    
}
void describe_char(cube *c)
{
    
}
void output(cube c, bool digit)
{
    
}
void rotate(cube *c, string order)
{
    
}
int main()
{
    ifstream fin("config.ini");
    string a;
    cube c1;
    bool digit=false;
    cin >> a;
    if (a == "NAME = digit")
    {
        describe_digit(&c1);
        digit = true;
    }
    if (a == "NAME = ascii")
        describe_digit(&c1);
    output(c1, digit);
    while (cin >> a && (a[0]=='L' || a[0]=='R' || a[0]=='F' || a[0]=='B' || a[0]=='U' || a[0]=='D') && a[1]=='i')
        rotate(&c1, a);
    cout << "\n操作非法\n";
    return 0;
}
