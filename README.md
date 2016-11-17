# online-sjtu-c-language
### 交大网校C语言课程作业
#### 顺序结构与选择结构程序设计
* 编写程序输入三角形的3条边长，计算并输出三角形的面积。 提示：三角形的面积S=sqrt((p(p-a)(p-b)(p-c)) 其中，p=(a+b+c)/2

```c
#include <stdio.h>
#include <math.h>
void main () {
    double Sa, Sb, Sc, Rp, Vs;
    printf("请输入三角形的3条边长，以“,”分割:\n");
    scanf("%lf,%lf, %lf", &Sa, &Sb, &Sc);
    Rp = (Sa + Sb + Sc) / 2;
    Vs = sqrt(Rp * (Rp - Sa) * (Rp - Sb) * (Rp - Sc));
    printf("三角形面积为%.2f", Vs);
}
```

* 编写C程序，求解下列分段函数的值：y = x<sup>2</sup> + 1 (x > 0); y = 0 (x = 0); y = x<sup>2</sup> - 1 (x < 0)
```c
#include <stdio.h>
void main () {
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
```

* 编写C程序，实现输入一个英文字母，判断该字母是大写还是小写

```c
#include <stdio.h>
#include <ctype.h>
void main () {
    /* 方法一 */
    char input;
    int c;
    printf("请输入一个英文字母\n");
    while ((c = getchar()) != '\n' && c != EOF);  //清除缓冲区残留数据
    scanf("%c[^\n]", (char *)&input);
    if(isupper(input)){
        printf("输入字母为大写");
    } else if(islower(input)){
        printf("输入字母为小写");
    } else {
        printf("非法输入！");
    }
    /* 方法二 */
    int c;
    printf("请输入一个英文字母\n");
    while ((c = getchar()) != '\n' && c != EOF);  //清除缓冲区残留数据
    int input = getchar();
    if(input >='a' && input <= 'z') {
        printf("输入字母为小写");
    } else if (input >='A' && input <= 'Z'){
        printf("输入字母为大写");
    } else {
        printf("非法输入！");
    }
}
```

#### 循环结构程序设计和数组的应用
* 有一个分数序列：2/1、3/2、5/3、8/5、13/8、……，编写一个C程序，求出这个数列的前30项之和。
```c
#include <stdio.h>
void main() {
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
```
* 编写程序，求1！+2！+3！+…+10！
```c
#include <stdio.h>
void main(){
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
```
* 编写一个C程序，实现对10个整数进行升序排序输出。
```c
#include <stdio.h>
void main() {
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
```
* 编写一个程序，读入9个裁判所打的分数，去掉一个最高分，去掉一个最低分，求剩余7个分数的平均值（要求用数组实现）。
```c
#include <stdio.h>
void main () {
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

```
#### 函数的使用
* 给定程序中函数fun的功能是：输出M行M列的整数方阵，然后求两条对角线上的元素之和，要求返回此和数。同时，在函数中需完整输出整数方阵和对角线上元素之和。因此，编写程序时需注意方阵元素的排列顺序和求对角线元素之和时不要漏项。
注意：切勿改动主函数main和其他函数中的任何内容，仅在函数fun的花括号中填入编写的语句。
程序如下：
```c
#include <conio.h>
#include <stdio.h>
#define M  5
int fun(int n,int xx[M][M]){
    //答题部分开始
    int Middle = n / 2, SumDiagnals = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            /*条件或使循环经过中心交叉点只纪录1次
            if (i == j || i == (n - j - 1)) {
                SumDiagnals += xx[i][j];
            }*/
            //单独计算两条对角线，使中心点2次都纳入计算
            if (i == j) {
                SumDiagnals += xx[i][j];
            }
            if (i == (n - j - 1)) {
                SumDiagnals += xx[i][j];
            }
            printf("%d ", xx[i][j]);
        }
        printf("\n");
    }
    return SumDiagnals;
    //答题部分结束
}
main()
{
    int aa[M][M] = {{1,2,3,4,5},{4,3,2,1,0},{6,7,8,9,0},{9,8,7,6,5},{3,4,5,6,7}};
    printf("\nThe sum of all elements on 2 diagnals is %d.", fun(M,aa));
}
```
* 使用递归方法求解斐波那契数列的前30项
```
//简单到不知道说啥好了....前面就写过好像...
int fib(int index) {
    if (index <= 2) {
        return index - 1;
    } else {
        return (fib(index - 2) + fib(index - 1));
    }
}
```






