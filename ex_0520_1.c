//
//  main.c
//  ex_0520_1
//
//  Created by 下田将斉 on 2016/05/20.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    double s = 0.0;
    int i ;
    
    for (i = 0; i <= 3; i++) {
        s = s+ pow(2.0, (double)i);
    }
    
    printf("実行結果%f\n", s);
    return 0;
}
