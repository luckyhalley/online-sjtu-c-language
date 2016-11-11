//
//  question1.h
//  online-sjtu-c-language
//
//  Created by 严明坤 on 16/11/12.
//  Copyright © 2016年 严明坤. All rights reserved.
//  编写程序输入三角形的3条边长，计算并输出三角形的面积。
//  提示：三角形的面积S=sqrt((p(p-a)(p-b)(p-c)) 其中，p=(a+b+c)/2

#include <math.h>

void question1 () {
    double Sa, Sb, Sc, Rp, Vs;
    printf("请输入三角形的3条边长，以“,”分割:\n");
    scanf("%lf,%lf, %lf", &Sa, &Sb, &Sc);
    Rp = (Sa + Sb + Sc) / 2;
    Vs = sqrt(Rp * (Rp - Sa) * (Rp - Sb) * (Rp - Sc));
    printf("三角形面积为%.2f", Vs);
}
