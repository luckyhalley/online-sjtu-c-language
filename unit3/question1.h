//
//  question1.h
//  online-sjtu-c-language
//
//  Created by 严明坤 on 16/11/15.
//  Copyright © 2016年 严明坤. All rights reserved.
//  给定程序中函数fun的功能是：输出M行M列的整数方阵，然后求两条对角线上的元素之和，要求返回此和数
#include <stdio.h>
#define M  5

void question1() {
    int aa[M][M] = {
        {1,2,3,4,5},
        {4,3,2,1,0},
        {6,7,8,9,0},
        {9,8,7,6,5},
        {3,4,5,6,7}
    };
    printf("\nThe sum of all elements on 2 diagnals is %d.", fun(M,aa));
}

int fun(int n, int xx[M][M]){
    int Middle = n / 2, SumDiagnals = 0, SumMatrix = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            //条件或使循环经过中心交叉点只纪录1次
            if (i == j || i == (n - j - 1)) {
                SumDiagnals += xx[i][j];
            }
            SumMatrix += xx[i][j];
        }
    }
    printf("The sum of all elements %d.", SumMatrix);
    return SumDiagnals;
}
