//
//  question1.h
//  online-sjtu-c-language
//
//  Created by 严明坤 on 16/11/12.
//  Copyright © 2016年 严明坤. All rights reserved.
//  编写一个C程序，实现对10个整数进行升序排序输出。

#include <stdio.h>
void question3() {
    void bubbleSort(), qSort();
    int numbers[] = {29, 66, 19, 98, 14, 7, 69, 3, 59, 23};
    printf("冒泡排序算法实现结果\n");
    bubbleSort(numbers);
}

//基本冒泡排序算法
void bubbleSort(int numbers[]) {
    for (int i = 10; i > 1; i--) {
        for (int j = 0; j < i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    for(int k = 0; k < 10 ; k++){
        if (k == 9)
            printf("%d\n", numbers[k]);
        else
            printf("%d,", numbers[k]);
    }
}
