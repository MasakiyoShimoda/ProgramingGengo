//
//  main.c
//  1_3
//
//  Created by 下田将斉 on 2016/06/24.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int *a, *b;
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
