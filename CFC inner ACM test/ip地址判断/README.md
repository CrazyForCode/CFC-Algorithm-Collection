# ip地址判断
### 题目描述
小明计算机网络课睡觉被老师发现了，老师让他判断黑板上写的是不是一个ip地址，小明表示不会。老师于是给了他一张专门练习判断是否是ip地址的作业让他下节课前完成。小明因为完全没听课只能拜托同宿舍的你帮忙，本着永远保持高逼格的原则你决定写一个小程序帮助他完成作业。
请完成上面提到的程序。
### 输入
第一行输入N，表示有N组测试数据，接下来的N行为需要判断的N组数据。

###输出
如果这个字符串是ip地址的话，输出1，否则输出0。

###样例输入
3
127.0.0.1
127.256.1.1
300.7.234.1
###样例输出
1
0
0

```c

#include <stdio.h>
char str[50];
int result;
//1 -> number,2 ->'.',0 -> other
int check(char ch)
{
    if(ch >= '0' && ch <= '9') return 1;
    if(ch == '.') return 2;
    return 0;
}

int main()
{
    int dot,dignum,a,dotsum;
    while(gets(str))
    {
        dotsum=a=dot=dignum=0;
        int i;
        for(i=0;str[i];i++)
        {
            if(check(str[0])==2)
            {
                result=0; break;
            }
            result = check(str[i]);
            if(!result)
            {
                break;
            }
            if(result == 1)
            {
                dot = 0;
                dignum++;
                a = a * 10 + str[i] - '0';
                if(dignum > 3 || a > 255)
                {
                    result = 0; break;
                }
            }
            else
            {
                dignum = a = 0;
                dot++;dotsum++;
                if(dot > 1 || dotsum > 3)
                {
                    result = 0; break;
                }
            }
        }
        if(dot || dotsum != 3)
        {
            result = 0;
        }
        printf("%d",result);
    }
    return 0;
}

```

> Create by 孙炫

