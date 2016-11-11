//
//  question1.h
//  online-sjtu-c-language
//
//  Created by 严明坤 on 16/11/12.
//  Copyright © 2016年 严明坤. All rights reserved.
//  编写C程序，实现输入一个英文字母，判断该字母是大写还是小写

#include <ctype.h>

void question3 () {
    /* 方法一
    char input;
    int c;
    printf("请输入一个英文字母\n");
    while ((c = getchar()) != '\n' && c != EOF);  //清除缓冲区残留数据
    scanf("%c[^\n]", (char *)&input);
    if(isupper(input)){
        printf("输入字母为大写");
    } else if(islower(input)){
        printf("输入字母为小写");
    } else {
        printf("非法输入！");
    }
    */
    
    /* 方法二 */
    int c;
    printf("请输入一个英文字母\n");
    while ((c = getchar()) != '\n' && c != EOF);  //清除缓冲区残留数据
    int input = getchar();
    if(input >='a' && input <= 'z') {
        printf("输入字母为小写");
    } else if (input >='A' && input <= 'Z'){
        printf("输入字母为大写");
    } else {
        printf("非法输入！");
    }
}

