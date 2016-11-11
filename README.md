# online-sjtu-c-language
### 交大网校C语言课程作业
#### 顺序结构与选择结构程序设计
* 编写程序输入三角形的3条边长，计算并输出三角形的面积。 提示：三角形的面积S=sqrt((p(p-a)(p-b)(p-c)) 其中，p=(a+b+c)/2

```c
#include <math.h>
void question1 () {
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
```

* 编写C程序，实现输入一个英文字母，判断该字母是大写还是小写

```c
#include <ctype.h>

void question3 () {
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


