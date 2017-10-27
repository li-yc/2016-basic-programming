//
//  main.cpp
//  登山问题
//
//  Created by lyc on 2017/2/16.
//  Copyright © 2017年 lyc. All rights reserved.
//

//  condition transition :

#include <iostream>
using namespace std;
struct person
{
    unsigned int consume, carry;
    float day = -0.1;
    bool chosen = 0;
}per[10];
unsigned int n,p;
unsigned int plan1_least_food=2^30,plan1_least_man=100,plan2_least_food=2^30,plan2_least_man=100,plan1_food_of_last_man=0,plan2_food_of_last_man=0,group[10],daily_consume,total_food,plan1[10],plan2[10];

bool cmp(person a, person b)
{
    return a.day > b.day;
}
void display_plan()
{
    
}

void climb(int help_height, int food_need, int member_id)
{
    if (help_height<=0)
    {
        total_food += food_need;
        if (total_food < plan1_least_food || (total_food == plan1_least_food && member_id < plan1_least_man))
        {
            int i;
            for (i=0; i<member_id; i++)
                plan1[i] = group[i];
            plan1_food_of_last_man = per[member_id-1].carry + food_need;
            plan1_least_food = total_food;
            plan1_least_man = member_id;
        }
        if (member_id < plan2_least_man || (member_id == plan2_least_man && total_food < plan1_least_food))
        {
            int i;
            for (i=0; i<member_id; i++)
                plan2[i] = group[i];
            plan2_least_food = total_food;
            plan2_least_man = member_id;
        }
        return;
    }
    
    unsigned int man;
    for (man=0; man<p; man++)
    {
        if (!per[man].chosen && per[man].carry > per[man].consume * help_height)
        {
            per[man].chosen = 1;
            daily_consume += per[man].consume;
            total_food += per[man].consume * help_height;
            group[member_id] = man;
            climb((food_need-1) / daily_consume +1, food_need+help_height*per[man].consume-per[man].carry, member_id+1);
            per[man].chosen = 0;
            total_food -= per[man].consume * help_height;
            daily_consume -= per[man].consume;
        }
    }
}

int main()
{
    cin >> n >> p;
    unsigned int k;
    for (k=0; k<p; k++)
        cin >> per[k].consume;
    for (k=0; k<p; k++)
    {
        cin >> per[k].carry;
        per[k].day = float(per[k].carry) / per[k].consume;
    }
    climb(n, 0, 0);
    
    
    return 0;
}
