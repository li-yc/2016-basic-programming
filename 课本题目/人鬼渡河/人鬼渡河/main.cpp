//
//  main.cpp
//  人鬼渡河
//
//  Created by lyc on 2016/12/6.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
bool finish=0;
int gh[15],mh[15],step=0,htot=1, d[5][2]={{0,1},{1,0},{1,1},{2,0},{0,2}};  //  gh = ghost here. go = ghost opposite. mh = man here. htot = here to there.
bool canpasslake(int mn, int gn, int gh, int mh)  //  mn = man number. gn = ghost number.
{
    gh += gn;
    mh += mn;
    if (gh>3 || mh>3 || gh<0 || mh<0)
        return 0;
    if ((gh == mh) || mh == 0 || mh == 3)
        return 1;
    return 0;
}
void ts()  //  try step
{
    int i;
    if (gh[step] == 0 && mh[step] == 0)
    {
        finish = true;
        for (i=0; i<step; i++)
            cout << "人数:" << mh[i] << "。 鬼数：" << gh[i] << "。\n";
    }
    if (finish)
        return;
    for (i=0; i<=4; i++)
    {
        if (canpasslake(d[i][0]*htot, d[i][1]*htot,gh[step],mh[step]))
        {
            htot *= -1;
            step++;
            gh[step] = gh[step-1]+d[i][0];
            mh[step] = mh[step-1]+d[i][1];
            ts();
            htot *= -1;
            step--;
        }
    }
}
int main()
{
    gh[0] = mh[0] = 3;
    ts();
    return 0;
}
