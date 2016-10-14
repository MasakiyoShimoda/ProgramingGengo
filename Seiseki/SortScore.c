//
//  main.c
//  seiseki
//
//  Created by 下田将斉 on 2016/10/03.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBER 51
#define M 20
#define N 3
#define FILE_PASS "/Users/MasakiyoS/Desktop/ProgramingExercise/プロ言/seiseki/seiseki/seiseki.txt"

int menuDisp(FILE **fp);
int inputMenu(FILE **fp);
int sortMenu();
int inputData();
int sortData();
int inputStudent(int, FILE **fp);
int inputSubjectName(int, FILE **fp);
int inputSubject (int, FILE **fp);

//個人成績の構造体宣言
typedef struct seiseki{
    int no;
    char name[M];	// Mは #defineで定義済みとする(最大20文字)
    char examName[N][M];
    int exam[N];	// Nは #define で定義済みとする（最大10科目）
    int total;
    double ave;
} Seiseki;

Seiseki data[MAX_MEMBER]; //MAX_MEMBERは#defineで定義済み(最大50名)



int main(int argc, const char * argv[]) {
    // insert code here...
    FILE *fp;
    char *test = NULL;
    char str[30];
    int number = 0, buff;
    
    /*DATAファイルが有る場合は開き、ない場合は新規作成*/
    if ((fp = fopen(FILE_PASS, "r+")) == NULL) {
        fp = fopen(FILE_PASS, "w+");
    }
    /*DATAファイルの1行目を読み、データが有るならば続きから。まだ途中。#s(2行目)が入力されると不具合*/
    while (fgets(str, 20,fp) != NULL){
        test = strstr(str, "#m");
        number = atoi(&test[2]);
    }
    if(number < 50 && number > 1){
        printf("入力途中のデータが有りますが、続きから再開しますか？\n1:yes\n0:no\n>>");
        scanf("%d", &buff);
        while(0 > buff || buff > 1){
            puts("もう1度選択してください");
            printf(">>");
            scanf("%d", &buff);
        }
        switch (buff) {
            case 1:
                printf("生徒数%d", number);
                
                break;
            case 0:
                fp = fopen(FILE_PASS, "w+");
                menuDisp(&fp);
                break;
            default:
                puts("異常があるの終了します");
                exit(1);
                break;
        }
    }
    
    menuDisp(&fp);
    
    
    fclose(fp);
    
    return 0;
}
/*メインメニューまだ改造予定*/
int menuDisp(FILE **fp){
    int select;
    puts(" ");
    puts("*------------------------*");
    puts("成績処理プログラム");
    puts("1:成績登録");
    puts("2:データ整理");
    puts("0:終了");
    puts("*------------------------*");
    printf(">>");
    scanf("%d", &select);
    while(0 > select || select > 2){
        puts("もう1度選択してください");
        printf(">>");
        scanf("%d", &select);
    }
    switch (select) {
        case 1:
            while(inputMenu(fp) == 1)
                menuDisp(fp);
            break;
        case 2:
            while (sortMenu() == 1)
                menuDisp(fp);
        case 0:
            puts("終了します。");
            exit(0);
        default:
            puts("異常があるの終了します");
            exit(1);
            break;
    }
    return 0;
}
/*入力用メニュー。のちのち入力も自作関数に移行*/
int inputMenu(FILE **fp){
    int selectNumber, selectSubject;
    puts(" ");
    puts("-----成績登録メニュー-----");
    puts("生徒の人数を入力してください(最大50人)");
    puts("0:戻る");
    printf(">>");
    scanf("%d", &selectNumber);
    while(0 > selectNumber || selectNumber > 50){
        puts("もう1度選択してください");
        printf(">>");
        scanf("%d", &selectNumber);
    }
    if(selectNumber == 0){
        return 1;
    }else if(selectNumber < 50){
        fprintf(*fp, "#m%d\n", selectNumber);
        printf("生徒数:%d人\n", selectNumber);
        puts("科目数を入力してください(最大10科目)");
        puts("0:戻る");
        printf(">>");
        scanf("%d", &selectSubject);
        while (0 > selectSubject || selectSubject > 10) {
            puts("もう1度入力してください");
            printf(">>");
            scanf("%d", &selectSubject);
        }
        if (selectSubject == 0) {
            return 1;
        }else if (selectSubject < 10){
            fprintf(*fp, "#s%d\n", selectSubject);
            printf("生徒数:%d人\n", selectNumber);
            inputSubjectName(selectSubject, fp);
        }
    }else{
        puts("異常があるの終了します");
        exit(1);
    }
    return 1;
}

int inputSubjectName(int subject, FILE **fp){
    int i;
    printf("科目数:%d\n", subject);
    puts("科目名を入力してください");
    puts("0:戻る");
    for (i = 0; i < subject; i++) {
        /*科目名を構造体に代入し、0で戻る判定*/
        printf(">>");
        scanf("%s", data[0].examName[i]);
        fprintf(*fp, "#e%d%s\n", i+1, data[0].examName[i]);
    }
    return 1;
}

int inputSubject(int subject, FILE **fp){
    
    return 1;
}

int inputStudent(int sutudent, FILE **fp){
    
    return 1;
}

/*ソートメニュー。まだ手を付けれず*/
int sortMenu(){
    int select;
    puts(" ");
    puts("-----データ整理メニュー-----");
    puts("0:戻る");
    printf(">>");
    scanf("%d", &select);
    while(0 > select || select > 2){
        puts("もう1度選択してください");
        printf(">>");
        scanf("%d", &select);
    }
    switch (select) {
        case 1:
            
            break;
        case 2:
            
            break;
        case 0:
            return 1;
            break;
        default:
            puts("異常があるの終了します");
            exit(1);
            break;
    }
    return 10;
}
