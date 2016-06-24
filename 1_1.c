//
//  main.c
//  1_1
//
//  Created by 下田将斉 on 2016/06/24.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>

void slash(int size){
    int i, j, k = 1;
    for (i = 0; i < size; i++) {
        for (j = k; j < size; j++)
            printf(" ");
        printf("*\n");
        k++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    slash(5);
    return 0;
}
