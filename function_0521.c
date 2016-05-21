//
// main.c
// function_0521
//
// Created by 下田将斉 on 2016/05/21.
// Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//
#include <stdio.h>
#include <math.h>

int myabs(int);
int main(int argc, const char * argv[]) {
  // insert code here...
  int data, abs;
  
  scanf("%d", &data);
  abs = myabs(data);
  printf("%dの絶対値 = %d\n", data, abs);
  
  return 0;
}

int myabs(int n){
  if(n < 0)
    return -n;
  else
    return n;
}
