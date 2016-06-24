//
//  main.c
//  4
//
//  Created by 下田将斉 on 2016/06/24.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>

void func1(int data){
    char data_b[8]={};
    int i;
    
    for (i=7; i>0; i--) {
        data_b[i] = data % 2;
        data = data / 2;
    }
    
    for (i = 0; i<8; i++)
        printf("%d", data_b[i]);
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    func1(87);
    return 0;
}
