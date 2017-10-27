//
//  main.cpp
//  w9链表解决问题
//
//  Created by lyc on 2016/11/7.
//  Copyright © 2016年 lyc. All rights reserved.
//
using namespace std;
#include <iostream>
#include <ifstream>
struct score
{
    int id,point=0;
    score* next;
};

int main(int argc, const char * argv[]) {
    int i,j;
    cout << "请输入文件名";
    ifstream fin;
    fin.open(file_name);
    score* head = new score;  //  #define chain list
    
    while (!fin.eof())
    {
        score* node = new score;
    }
           
           
    fin.close();
    return 0;
}
