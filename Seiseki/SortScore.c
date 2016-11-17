//
//  main.c
//  seiseki
//
//  Created by 下田将斉 on 2016/10/03.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBER 51
#define M 20
#define N 10

int reSelect(int, int);
void menuDisp();
void inputMenu();
void sortMenu();
int inputData();
int sortData();
void inputSeiseki(int, int);
void show();

typedef struct seiseki{
    char name[M];	// Mは #defineで定義済みとする(最大20文字)
    int member, no, exam[N], number, exam0;	// Nは #define で定義済みとする（最大10科目）
    double ave, total;
} Seiseki;

Seiseki data[MAX_MEMBER]; //MAX_MEMBERは#defineで定義済み(最大50名)

int main(int argc, const char * argv[]) {
    menuDisp();
    return 0;
}

/*メインメニュー*/
void menuDisp(){
    puts("*------------成績処理プログラム------------*");
    puts("1:成績登録");
    puts("2:データ整理");
    puts("0:終了");
    puts("*-----------------------------------------*");
    
    switch (reSelect(0, 2)) {
        case 1:
            inputMenu();
            break;
        case 2:
            sortMenu();
            break;
        case 0:
            puts("終了します。");
            exit(0);
        default:
            puts("異常があるの終了します");
            exit(9);
    }
}

/*異常な値が入力されたら再入力を求める*/
int reSelect(int min, int max){
    int selectNumber;
    printf(">>");
    scanf("%d", &selectNumber);
    while(min > selectNumber || selectNumber > max){
        puts("もう1度選択してください");
        printf(">>");
        scanf("%d", &selectNumber);
    }
    return selectNumber;
}

/*生徒の人数と科目数を入力させて構造体に代入する*/
void inputMenu(){
    int selectNumber, selectSubject;
    puts("\n-----成績登録メニュー-----");
    puts("生徒の人数を入力してください(最大50人)\n0:戻る");
    selectNumber = data[0].number = reSelect(0, MAX_MEMBER);
    if(selectNumber == 0)
        menuDisp();
    else if(selectNumber < 50){
        puts("科目数を入力してください(最大10科目)\n0:戻る");
        selectSubject = data[0].exam0 = reSelect(0, N);
        
        if (selectSubject == 0)
            menuDisp();
        else if (selectSubject < N)
            inputSeiseki(selectSubject, selectNumber);
    }else{
        puts("異常があるの終了します");
        exit(9);
    }
}

/*生徒の人数と科目数から点数を入力し、構造体に代入*/
void inputSeiseki(int subject, int number){
    int i, j;
    
    for (i = 1; i <= number; i++) {
        data[i].no = i;
        printf("-----------%d人目------------\n", data[i].no);
        printf("名前>>");
        getchar();
        fgets(data[i].name, M, stdin);
        
        for (j = 1; j <= subject; j++){
            printf("科目%d>>",j);
            scanf("%d", &data[i].exam[j]);
            data[i].total += data[i].exam[j];
        }
        data[i].ave = data[i].total / subject;
    }
    puts("登録を終了します");
    menuDisp();
}

/*ソートメニュー*/
void sortMenu(){
    int i, j, min, tmp;
    puts(" ");
    puts("-----データ整理メニュー-----");
    puts("1:出席番号順");
    puts("2:名前順");
    puts("3:指定した科目の成績順");
    puts("4:平均順");
    puts("5:総点順");
    puts("0:戻る");
    switch (reSelect(0, 5)) {
        case 1:/*出席番号順*/
            for (i = 1; i < data[0].number; i++) {
                min = i;
                for (j = i+1; j < data[0].number; j++)
                    if (data[j].no < data[min].no){
                        min = j;
                        tmp = data[i].no;
                        data[i].no = data[j].no;
                        data[j].no = tmp;
                    }
            }
            
            break;
        case 2:/*名前順は未実装*/
            break;
        case 3:/*各科目点数順*/
            for (i = 0; i < data[0].exam[0]; i++) {
                min = i;
                for (j = i+1; j < data[0].exam[0]; j++)
                    if (data[j].exam[0] < data[min].exam[0]){
                        min = j;
                        tmp = data[i].exam[0];
                        data[i].exam[0] = data[j].exam[0];
                        data[j].exam[0] = tmp;
                    }
            }
            break;
        case 4:/*平均点順*/
            for (i = 0; i < data[0].number; i++) {
                min = i;
                for (j = i+1; j < data[0].number; j++)
                    if (data[j].ave < data[min].ave){
                        min = j;
                        tmp = data[i].ave;
                        data[i].ave = data[j].ave;
                        data[j].ave = tmp;
                    }
            }
            break;
        case 5:/*合計点順*/
            for (i = 0; i < data[0].number; i++) {
                min = i;
                for (j = i+1; j < data[0].number; j++)
                    if (data[j].total < data[min].total){
                        min = j;
                        tmp = data[i+1].total;
                        data[i+1].total = data[j].total;
                        data[j+1].total = tmp;
                    }
            }
            break;
        case 0:
            menuDisp();
        default:
            puts("異常があるの終了します");
            exit(9);
    }
    show();
    menuDisp();
}

/*ソート結果を表示*/
void show(){
    int i, j;
    for (i = 0; i < data[0].number; i++) {
        printf("%d\t", data[i+1].no);
        for (j = 0; j < data[0].exam0; j++)
            printf("%d\t", data[i+1].exam[j+1]);
        printf("%.2f\t%.2f\n", data[i+1].total, data[i+1].ave);
    }
}
