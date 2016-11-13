//
//  main.c
//  online-sjtu-c-language
//
//  Created by 严明坤 on 16/11/12.
//  Copyright © 2016年 严明坤. All rights reserved.
//  主函数入口

#include <stdio.h>
#include "question1.h"
#include "question2.h"
#include "question3.h"
#include "question4.h"

void main () {
    int selected;
    printf("运行题目, 请选择（1 or 2 or 3 or 4）\n");
    scanf("%d", &selected);
    switch (selected) {
        case 1:
            question1();
            break;
        case 2:
            question2();
            break;
        case 3:
            question3();
            break;
        case 4:
            question4();
            break;
        default:
            printf("并没有你所选择的题号！");
            break;
    }
}
