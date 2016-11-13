//
//  question1.h
//  online-sjtu-c-language
//
//  Created by 严明坤 on 16/11/12.
//  Copyright © 2016年 严明坤. All rights reserved.
//  编写程序输入三角形的3条边长，计算并输出三角形的面积。
//  提示：有一个分数序列：2/1、3/2、5/3、8/5、13/8、……，编写一个C程序，求出这个数列的前30项之和。

#include <stdio.h>
void question1() {
    double result = 0;
    int i = 0;
    while (i < 30) {
        double up = (double)fib(i + 3);
        double down = (double)fib(i + 2);
        result += up / down;
        i++;
    }
    printf("%.2f", result);
}
//斐波那契数列
int fib(int index) {
    if (index <= 2) {
        return 1;
    } else {
        return (fib(index - 2) + fib(index - 1));
    }
}
