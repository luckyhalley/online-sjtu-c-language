//
//  main.c
//  online-sjtu-c-language
//
//  Created by 严明坤 on 16/11/15.
//  Copyright © 2016年 严明坤. All rights reserved.
//  主函数入口

#include <stdio.h>
#include "question1.h"

void main () {
    int selected;
    printf("运行题目, 请选择（1 or 2 or 3 or 4）\n");
    scanf("%d", &selected);
    switch (selected) {
        case 1:
            question1();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            printf("并没有你所选择的题号！");
            break;
    }
}