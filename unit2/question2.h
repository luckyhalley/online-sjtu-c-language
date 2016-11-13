//
//  question2.h
//  online-sjtu-c-language
//
//  Created by 严明坤 on 16/11/12.
//  Copyright © 2016年 严明坤. All rights reserved.
//  编写程序，求1！+2！+3！+…+10！

void question2 () {
    int result = 0;
    for (int i = 1; i <= 10; i++){
        int sumer = 1;
        for (int j = 1; j <= i; j++){
            sumer = sumer * j;
        }
        result += sumer;
    }
    printf("1! + 2! + 3! + … + 10! = %d", result);
}
