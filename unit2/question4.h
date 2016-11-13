//
//  question4.h
//  online-sjtu-c-language
//
//  Created by 严明坤 on 16/11/12.
//  Copyright © 2016年 严明坤. All rights reserved.
//  编写程序输入三角形的3条边长，计算并输出三角形的面积。
//  提示：三角形的面积S=sqrt((p(p-a)(p-b)(p-c)) 其中，p=(a+b+c)/2

#include <stdio.h>
void question4 () {
    int number, total = 0, i = 0, max = 0, min = 0 ;
    float average;
    printf("输入9个裁判打分\n");
    for(; i < 9; i++){
        printf("请输入第%d个裁判评分", i + 1);
        scanf("%d", &number);
        total += number;
        if (i == 0) {
            max = min = number;
        } else {
            if(number > max){
                max = number;
            }
            if(number < min){
                min = number;
            }
        }
    }
    average = (float) (total - max - min) / 7;
    printf("去掉一个最高分，去掉一个最低分，最后平均分为：%.2f", average);
}
