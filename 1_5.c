//
//  main.c
//  1_5
//
//  Created by 下田将斉 on 2016/06/24.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

char mytoupper(int c);

int main()
{
    int c;
    
    while((c=getchar()) != EOF)
        printf("%c", mytoupper(c));
    
    return 0;
}

char mytoupper(int c)
{
    
    if('a' <= c && c <= 'z')
        c -= 'a'-'A';
    
    
    return c;
}
