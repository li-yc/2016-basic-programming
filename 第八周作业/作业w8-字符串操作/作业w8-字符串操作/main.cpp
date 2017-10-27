//  test passed
//  main.cpp
//  作业w8-字符串操作
//
//  Created by lyc on 2016/11/1.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
int i,j,k;
void op1(int nf, string af){
    for (i=0; i < af.size(); i++){
        if (af[i] >= 97)
            af[i] = af[i] - 32;
    }
    cout << af;
}
void op2(int nf, string af){
    for (i=0; i < af.size(); i++){
        if (af[i] <= 90)
            af[i] = af[i] + 32;
    }
    cout << af;
}
void op3(int nf, string af){
    for (i=int (af.size() - 1); i>=0; i--)
        cout << af[i];
}
void op4(int nf, string af){
    for (i=0; i< af.size(); i++){
        if (af[i]>= 97)
            af[i] = af[i] - 32;
        else
            af[i] = af[i] + 32;
    }
    cout << af;
}
void op5(int nf, string b){
    bool p;
    const int m = b.size();
    char af[m];
    for (i=0; i<b.size(); i++)
        af[i] = b[i];
    int size = m;
    for (i=0; i < size; i++){
        if (af[i] < 97)
            af[i] = af[i] + 32;
    }
    for (i=0; i < size; i++){
        p = true;
        j = 1;  //j represent the number of successive characters, j=3 means 3 successive characters
        while (p && (i+j-1) < size){
            if (af[i]+j == af[i+j])
                j = j+1;
            else
                p = false;
        }
        if (j>2){
            af[i+1] = '-';
            for (k=i+j-1; k < size; k++){
                af[k-j+3] = af[k];
            }
            size = size - j + 3;
        }
    }
    for (i=0; i<size; i++){
        cout << af[i];
    }
}
int main(int argc, const char * argv[]) {
    string a;
    int n;
    cin >> n >> a;
    switch (n) {
        case 1:
            op1(n, a);
            break;
        case 2:
            op2(n, a);
            break;
        case 3:
            op3(n, a);
            break;
        case 4:
            op4(n, a);
            break;
        case 5:
            op5(n, a);
            break;
        default:
            break;
    }
    return 0;
}
