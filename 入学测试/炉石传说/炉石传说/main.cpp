//  passed
//  main.cpp
//  炉石传说
//
//  Created by lyc on 2016/11/9.
//  Copyright © 2016年 lyc. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
int sn[2] = {0,0};
struct ser  // ser = servant
{
    int at,hp;
    bool exist=false;
}a[2][8];  // 先手玩家（又叫a玩家）储存在a[0][8], 后手玩家（又叫b玩家）储存在a[1][8]
void die(int po, bool bs)  // po = position. bs = b's servant: if b's servant died, the variable is true.
{  // used when a servant dies, not hero!
    int k;
    for (k=po; k<sn[bs]; k++)
        a[bs][k] = a[bs][k+1];
    a[bs][sn[bs]].exist = false;
    sn[bs] -= 1;
}
void attack(int attacker, int d, bool bturn)  // attacker = attacker, d = defender, snum = servant number
{
    a[bturn][attacker].hp -= a[!bturn][d].at;
    a[!bturn][d].hp -= a[bturn][attacker].at;
    if ((a[bturn][attacker].hp <= 0) && (attacker != 0))
        die(attacker, bturn);
    if ((a[!bturn][d].hp <= 0) && (d != 0))
        die(d, !bturn);
}
void summon(int pos, int att, int hea, ser * turn, int snu)  // snu = servant number
{
    int k;
    for (k=snu; k>=pos; k--)  // push forward servants
        turn[k+1] = turn[k];
    turn[pos].hp = hea;
    turn[pos].at = att;
    turn[pos].exist = true;
}
int main()
{
    int n=0,i,j,gamecon=0,at,def,p,h;
    // at = attack, p = position, h = health, i represents turn number, sernum = servant number
    string op;  // op = operation
    bool atu;  // atu = a's turn: if now is a's turn, the variable is true
    cin >> n;
    i = 0;
    for(j=0; j<2; j++)
    {
        a[j][0].hp = 30; a[j][0].at = 0; a[j][0].exist = 1;
    }
    atu = true;
    for (i=0; (i<n) && (gamecon == 0); i += 1)
    {
        cin >> op;
        if (op == "summon")
        {
            cin >> p >> at >> h;
            summon(p, at, h, a[!atu], sn[!atu]);
            sn[!atu] += 1;
        }
        if (op == "attack")
        {
            cin >> at >> def;
            attack(at, def, !atu);
            if (a[0][0].hp <= 0)
                gamecon = -1;
            if (a[1][0].hp <= 0)
                gamecon = 1;
        }
        if (op == "end")
            atu = !atu;
    }
    cout << gamecon << endl;
    for (j=0; j<2; j++)
    {
        cout << a[j][0].hp << endl;
        cout << sn[j] << ' ';
        for (i=1; i<=sn[j]; i++)
            cout << a[j][i].hp << ' ';
        cout << endl;
    }
    return 0;
}
