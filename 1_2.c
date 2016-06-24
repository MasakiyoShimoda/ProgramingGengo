//
//  main.c
//  1_2
//
//  Created by 下田将斉 on 2016/06/24.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
double area = 0;

void trapezoid(int u_base,int b_base, int height);

int main(int argc, const char * argv[]) {
    // insert code here...
    trapezoid(3,8,6);
    printf("%lf\n", area);
    return 0;
}

void trapezoid(int u_base,int b_base, int height){
    area = (u_base + b_base) * height /2.0;
}
