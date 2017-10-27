//
//  main.cpp
//  1
//
//  Created by lyc on 2016/10/25.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,i,j;
    char p;
    cin >> n;
    for (i=0; i<n; i++){
        p='*';
        for (j=1; j<=2*n-1; j++){
            if ((j < (n-i)) || (j > (n+i))) cout << ' ';
            else{
                cout << p;
                if (p == '*')
                    p = ' ';
                else
                    p = '*';
            }
        }
        cout << endl;
    }
    return 0;
}
