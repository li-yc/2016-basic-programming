//  统计文件中每个(英语)单词出现的次数，并且将结构输出到一个文件中
//  main.cpp
//  写文件
//
//  Created by lyc on 2016/11/5.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string w[100],str,filename,outputname;  //  w = word
    bool find;
    int i,j,count[100],p=0,size; //  p represents the number of words.
    ifstream fin("/Users/lyc/文件/程序设计/课本题目/写文件/写文件/student.txt");
    ofstream fout("/Users/lyc/文件/程序设计/课本题目/写文件/写文件/file out.txt");
    //cout << "please input filename" << endl;
    //cin >> filename;
    //cout << "please input outputname" << endl;
    //cin >> outputname;
    //fin.open(filename);
    //fout.open(outputname);
    if ((!fout) || (!fin))
    {
        cout << "open failed\n";
        return -1;
    }
    fin >> str;
    while (!fin.eof())
    {
        find = false;
        i = 0;
        //cin >> str;
        size = int(str.size());
        if ((str[str.size()-1] == '.') || (str[str.size()-1] == ',') || (str[size-1] == ';'))
            str[size-1] = '\0';
        j = 0;
        while ((!find) && (j<p))
        {
            if (w[j] == str)
                find = true;
            else
                j+=1;
        }
        if (find)
            count[j] += 1;
        else
        {
            w[p] = str;
            count[p] = 1;
            p += 1;
        }
        fin >> str;
    }
    for (i=0; i<p; i+=1)
    {
        cout << w[i] << ":" << count[i] <<"   ";
        if ((i % 2) || (i == p-1))
            cout << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
