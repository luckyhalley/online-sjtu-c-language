//
//  question2.h
//  online-sjtu-c-language
//
//  Created by 严明坤 on 16/11/12.
//  Copyright © 2016年 严明坤. All rights reserved.
//  编写C程序，求解下列分段函数的值：y = x2 + 1 (x > 0); y = 0 (x = 0); y = x2 - 1 (x < 0)

void question2 () {
    float Vx , Vy;
    printf("求解分段函数，请输入X的值:\n");
    scanf("%f", &Vx);
    if (Vx > 0) {
        Vy = Vx * Vx + 1;
    } else if(Vx < 0) {
        Vy = Vx * Vx - 1;
    } else {
        Vy = 0;
    }
    printf("分段函数的求解结果Y的值为%f\n", Vy);
    
}
