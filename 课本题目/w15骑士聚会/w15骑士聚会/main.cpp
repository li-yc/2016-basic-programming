//
//  main.cpp
//  w15骑士聚会
//
//  Created by lyc on 2016/12/19.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
struct position
{
    int x,y;
}cal[20];
int m,n,minstep[20][10][10];  //  n<=100. m<=20. m = cal number  debug
const int jpx[8]={1,2,2,1,-1,-2,-2,-1},jpy[8]={-2,-1,1,2,-2,-1,1,2},max_int=2147483647;
position makepos(int x, int y)
{
    position a={x,y};
    return a;
}
bool canjump(int x, int y, int id)
{
    if (x>=0 && y>=0 && x<n && y<n && minstep[id][x][y] == -1)
        return 1;
    else
        return 0;
}
void min_step_of_cal(int id, position pos)
{
    int i,head=0,tail=0,step=0;
    position list[25] = {{pos.x, pos.y}};  //  debug
    minstep[id][pos.x][pos.y] = 0;
    while (head < n*n)
    {
        step++;
        int tmp_tail=tail;
        for (; head<=tmp_tail; head++)
            for (i=0; i<8; i++)
                if (canjump(list[head].x + jpx[i], list[head].y + jpy[i], id))
                {
                    list[++tail].x = list[head].x + jpx[i];
                    list[tail].y = list[head].y + jpy[i];
                    minstep[id][ list[tail].x ][ list[tail].y ] = step;
                }
    }
}
void display_minstep(int id)
{
    int i,j;
    cout << "======" << id+1 << " cavalry=======\n";
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            cout << minstep[id][i][j] << ' ';
        cout << endl;
    }
    cout << "======================" << endl;
}
int maxstepofablock,sum;
void max_step_of_a_block(int x, int y)
{
    int id;
    sum = 0;
    maxstepofablock = 0;
    for (id=0; id<m; id++)
    {
        if (maxstepofablock < minstep[id][x][y])
            maxstepofablock = minstep[id][x][y];
        sum += minstep[id][x][y];
    }
}
void min_step()
{
    int minstep=max_int,x=-1,y=-1,i,j,min_sum_step=max_int;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            max_step_of_a_block(i, j);
            if (minstep > maxstepofablock || (minstep == maxstepofablock && sum < min_sum_step))
            {
                minstep = maxstepofablock;
                min_sum_step = sum;
                x = i;
                y = j;
            }
        }
    cout << "meeting place : (" << x+1 << ',' << y+1 << ")\n";
    cout << "min step : " << minstep << endl;
    cout << "min sum step : " << min_sum_step << endl;
}
int main()
{
    int i,size = sizeof(minstep) / sizeof(int);
    cout << "Please input width of the cupboard.\n";
    cin >> n;
    cout << "Please input number of cavalries.\n";
    cin >> m;
    cout << "Please input cavalries‘ position.\n";
    for (i=0; i<m; i++)
        cin >> cal[i].x >> cal[i].y;
    for (i=0; i<size; i++)  //  debug
        *(**minstep + i) = -1;
    for (i=0; i<m; i++)
    {
        min_step_of_cal(i, cal[i]);
        display_minstep(i);
    }
    min_step();
    return 0;
}
