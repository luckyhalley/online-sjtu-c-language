//
//  question1.h
//  online-sjtu-c-language
//
//  Created by 严明坤 on 16/11/17.
//  Copyright © 2016年 严明坤. All rights reserved.
//  使用递归方法求解斐波那契数列的前30项
void question2() {
    printf("斐波那契数列第30项为 %d.", fib(30));
}

int fib(int index) {
    if (index <= 2) {
        return index - 1;
    } else {
        return (fib(index - 2) + fib(index - 1));
    }
}
