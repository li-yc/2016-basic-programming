//
//  main.cpp
//  2
//
//  Created by lyc on 2016/10/25.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a,b,c,d,m;
    for (a=1; a<10; a++)
        for (b=0; b<10; b++)
            for (c=0; c<10; c++)
                for (d=0; d<10; d = d+2){
                    m = a*1000 + b*100 + c*10 + d;
                    if ((m*4) == (d*1000 + c*100 + b*10 +a)){
                        cout << m;
                        return 0;
                    }
                }
    return 0;
}
