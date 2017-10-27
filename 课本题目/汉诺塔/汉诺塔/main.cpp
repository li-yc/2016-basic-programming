//
//  main.cpp
//  汉诺塔
//
//  Created by lyc on 2016/11/22.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int plate[3][100], pn[3];  // pn = plate number.
void mtop(int p1, int p2)  // move the top plate from position1 to position2
{
    plate[p2][pn[p1-1]] = plate[p1][pn[p2-1]];
    plate[p1][pn[p2-1]] = 0;
    pn[p1] -= 1;
    pn[p2] += 1;
    cout << p1+1 << "->" << p2 << ". ";
}
void moveplate(int n, int ppo, int gpo)  // ppo = present position. gpo = goal position.
{
    if (n == 1)
    {
        
    }
}
int main(int argc, const char * argv[]) {
    int k;
    cout << "Please input number of plates.\n";
    cin >> pn[0];
    for (k=0; k<pn[0]; k++)
        plate[0][k] = pn[0] - k;
    moveplate(pn[0], 0, 2);
    return 0;
}
