//
//  main.c
//  2
//
//  Created by 下田将斉 on 2016/06/24.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>

int mystrlen(char st[]);

int main(int argc, const char * argv[]) {
    // insert code here...
    char str[256];
    scanf("%s", str);
    printf("文字列の長さ:%d\n", mystrlen(str));
    return 0;
}

int mystrlen(char st[]){
    int i = 0;
    while (st[i] != '\0') {
        i++;
    }
    return i;
}
