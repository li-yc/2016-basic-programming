//
//  main.cpp
//  6.5-几条鱼
//
//  Created by lyc on 2016/11/3.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int fish[6],i=1,j;
    bool find = false;
    memset (fish, 0, 6);
    while (!find){
        find = true;
        fish[0] = i;
        for (j=1; j<=5; j++){
            if (fish[j-1] % 4 == 0){
                fish[j] = fish[j-1] / 4 * 5 + 1;
            }
            else{
                find = false;
                break;
            }
        }
        i = i+1;
    }
    cout << fish[5];
    return 0;
}
