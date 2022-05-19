////
////  main.c
////  CProject
////
////  Created by 王先生 on 2022/1/16.
////
////小王要动脑啊！这是逻辑，不是算数！
//类型char int float short double long longlong
//常见关键字
//auto break case char const continue default do double else enum(枚举) extern(引入外部变量) float for goto if int long register(寄存器关键字) return short signed(signed(省略了) int) [unsigned int](无符号位的数) sizeof static struct(结构体关键字) switch typedef(类型定义，类型重定义) union(联合体/共用体) unsigned void volatile while
#include <stdio.h>
#include <string.h>
#include <unistd.h>//导入库
#include <stdlib.h>
#include <curses.h>
//int sum(int a)//static保留函数
//{
//    int c = 0;
//    static int b = 3;
//    c += 1;
//    b += 2;
//    return (a + b + c);
//}
//int main()
//{
//    int i;
//    int a = 2;
//    for(i=0;i<5;i++)
//        printf("%d ",sum(a));
//    return 0;
//}
//int main()//对比两个字符串是否相等
//{
//    char usr_psd[] = "123a";
//    char pad[10] = {0};
//    int i = 0;
//    printf("请输入您的密码:->");
//    scanf("%s",&pad);
//    while(strcmp(usr_psd,pad) != 0)
//        if(strcmp(usr_psd,pad)  == 0)//等号不能用来判断两个字符串是否相等，要用库函数
//        {
//            printf("密码正确！！！\n");
//            break;
//        }
//    else if(2 == i)
//    {
//        printf("错误警告！\n");
//        break;
//    }
//    else
//    {
//        printf("密码错误，请重新输入:->");
//        scanf("%s",&pad);
//        i++;
//    }
//    if(strcmp(usr_psd,pad) == 0)
//        printf("密码正确！！！\n");
//    return 0;
//}
//int main()
//{
//    char arr1[] = "welcome to bit";
//    char arr2[] = "##############";
//    int left = 0;
//    int right = strlen(arr1)-1;
//    while(left<=right)
//    {
//        arr2[left]=arr1[left];
//        arr2[right]=arr1[right];
//        left++;
//        right--;
//        sleep(1);//睡眠函数
//
//        printf("%s\n",arr2);
//        system("clear");
//    }
//    printf("welcome to bit\n");
//    return 0;
//}
//{//  二分法查找顺序数组
//    int arr[] = {1,2,3,4,5,6,7,8,9,10};
//    int k = 0;
//    printf("输入要查找的数：");
//    scanf("%d",&k);
//    int left = 0;//标识左下标
//    int sz = sizeof(arr)/sizeof(arr[0]);//计
//    int right = sz - 1;//右下标
//
//    while(left<=right)
//    {
//        int mid = (left + right)/2;//中间标
//        if(arr[mid] > k)
//        {
//            right = mid - 1;
//        }
//        else if(arr[mid] < k)
//        {
//            left = mid + 1;
//
//        }
//        else
//        {   printf("找到了，下标是%d\n",mid);
//            break;}
//    }
//    if(right < left)
//        printf("找不到\n");
//
//    return 0;
//}
//{//这个算法是遍历查找，相对来说效率低，用二分查找
//    int arr[] = {1,2,3,4,5,6,7,8,9,10};
//    int k = 19;//写一个代码在arr数组中找到7这个数字
//    int sz = sizeof(arr)/sizeof(arr[0]);//判断arr里有多少个元素
//    int i = 0;
//    for(i = 0; i < sz ; i++)
//    {
//        if(k == arr[i])
//        {
//            printf("找到了，下标是%d\n",i);
//            break;}
//    }
//    if(i == sz)
//        printf("没找到\n");
//    printf("%d\n",sz);
//    return 0;
//}
//{
//    int i = 0;
//    char user_password = 123;
//    int password = 0;
//    printf("请输入密码：->");
//    scanf("%d",&password);
//    for(i<2){//这里有问题，最后一次对的话 不会成功
//        if(password == user_password)
//        {
//            printf("密码正确\n");
//            break;
//        }
//        else if(password != user_password){
//            printf("密码错误，请重新输入:->");
//            scanf("%d",&password);
//            i++;
//        }
//        }
//    if(2 == i)
//        printf("系统报警！\n");
//    return 0;
//}
//{//  计算前10阶乘相加 简化。
//    int n = 0;
//    int j = 1;
//
//    //printf("请输入计算的阶乘数:->");
//    //scanf("%d",&n);
//    for(int i = 1;i <= 10;i++)
//        {
//            j *= i;
//            n += j;
//    }
//    printf("10的阶乘 = %d\n",n);
//    return 0;
//}
//{//  计算前10阶乘相加 复杂了 两个for 可以优化 要有脑子，走逻辑；
//    int n = 0;
//    int j = 1;
//    int i = 1;
//    //printf("请输入计算的阶乘数:->");
//    //scanf("%d",&n);
//    for(int o = 1;o <= 10;o++){
//        for(;i <= o;i++)
//        {
//            j *= i;
//        }
//        n += j;
//    }
//    printf("10的阶乘 = %d\n",n);
//    return 0;
//}
//{//  计算n的阶乘
//    int n = 0;
//    int j = 1;
//    printf("请输入计算的阶乘数:->");
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i++)
//    {
//         j *= i;
//    }
//    printf("%d的阶乘 = %d\n",n,j);
//    return 0;
//}
//{//do while 循环,直接先循环一次，然后判断是否继续循环
////do
////    循环语句
////while(表达式判断);
//    int i = 1;
//    do
//    {
//        if(5 == i)
//            continue;//死循环
//        printf("%d\n",i);
//        i++;
//    }
//    while(i<11);
//    return 0;
//}
////变种2
//{
//    int i = 0;
//    int k = 0;
//    for(i = 0, k = 0; k = 0;i++, k++)//循环0次，判断语句k=0，判断为0为假，不循环。
//
//        k++;
//    return 0;}
//{
//    int i = 0;
//    int j = 0;
//    for(;i<10;i++)//不能随便的省略，次代码只会打印10个haha。因为当j等于10的时候，返回到i++，再继续j循环的时候，是进不去的，因为j=10 没有初始化，所以进不去循环。
//    {
//
//        for(;j < 10;j++)
//        {
//            printf("haha%d,%d\n",i,j);
//        }
//    }
//    return 0;
//}
//{//for的变种
//    for(;;)
//        printf("哈哈\n");
//    //死循环，for的初始化，判断，调整都可以省略但是判断部分被省略，那判断条件就是：恒为真
//    //如果不是非常熟练，不要随便省略
//    return 0;
//}
//{
//    int re = 0;
//    int ch = 0;
//    char password[20] = {0};
//    printf("请输入密码：");
//    scanf("%d",&password);
//	printf("请确认(Y/N)>");
//    while((ch = getchar()) != '\n'){
//        ;
//    }
//    re = getchar();
//    if('Y' == re){
//        printf("确认成功！\n");
//    }
//    else{
//        printf("放弃确认！\n");
//    }
//    printf("密码等于%s\n",password);//此时的密码已经被getchar获取了不准确。
//    return 0;
//    }
//1.16 常量
//1、const常量
//    const int num = 4;
//    int arr[num] = {0};
//    printf("%d\n",num);
//    return 0;
//}
//2、define定义标识符
//#include <stdio.h>
//#define MAX 10
////#define 定义的标识符常量 无法修改与const一样不能修改
//int main(){
//    printf("MAX=%d\n",MAX);
//    return 0;
//}


//3、枚举常量
//枚举-一一列举
//性别：男 女 保密；三原色：红 黄 蓝；星期：1，2，3，4，5，6，7
//枚举关键字 - enum
//enum Sex
//{
//    MALE,//男
//    FEMALE,//女
//    SECRET//保密
//};//枚举常量不能更改 例如 MALE=1（这是不可以的）
////MALE FEMALE SECRET - 枚举常量  对应0，1，2……
//#include <stdio.h>
//int main(){
//    //enum Sex s = MALE;
//    printf("%d\n",MALE);//0
//    printf("%d\n",FEMALE);//1
//    printf("%d\n",SECRET);//2
//    return 0;
//}

//#include <stdio.h>
//enum Color
//{
//    RED,
//    YELLOW,
//    BLUE
//};
//int main(){
//    enum Color color = BLUE;
//    color = YELLOW;
//    return 0;
//}
//字符串char  类型双引号内的字符
//“asdsf”；“hello world”
//#include <stdio.h>
//#include <string.h>
//int main(){
////    char arr1[] = "abc";//数组
////    //"abc" -- 'a' 'b' 'c' '\0' 会默认放一个‘\0’是字符串的结束标志
////    char arr2[] = {'a','b','c',0};//现在版本可以不加也能打印出来
////    printf("%s\n",arr1);
////    printf("%s\n",arr2);
//    char arr1[] = "abc";
//    char arr2[] = {'a','b','c',0};
//    //int n = 123456;
//    printf("%lu\n",strlen(arr1));//strlen string lenght 计算字符串长度
//    printf("%lu\n",strlen(arr2));
//    //printf("%lu\n",strlen(n));无法运行
//    return 0;
//}

/*转译字符，\ddd为八进制，\xdd为十六进制
#include <stdio.h>
int main(){
    printf("c:\\test\141\\test\n");
    printf("%c\n",'\'');
    printf("%s\n","\"");
    return 0;
}

#include <stdio.h>
#include <string.h>
int main(){
    printf("%d\n",strlen("c:\test\32\test.c"));
    return 0;
}
*/
//#include <stdio.h>//无法运行有问题
//int main(){
//    int Sex = 0;
//    printf("请选择你的性别(男0/女1):>\n");
//    scanf(" %d\n",&Sex);
//    //fflush(stdin); //C语言清空输入缓冲区函数
//    if(Sex == 0)
//        printf("你的染色体为XY\n");
//    else
//        printf("你是变态\n");
//    return 0;
//}
////while语句
//#include <stdio.h>
//int main(){
//    int line = 1;
//    printf("认真学习\n");
//
//    while(line<31){
//        printf("敲%d行代码\n",line);
//        line++;
//    }
//    if(line>=20)
//        printf("好offer\n");
//    return 0;
//}
//#include <stdio.h>
//int ADD(int x, int y)//自定义函数————调用方便
//{
//    int z = x+y;
//    return z;
//}
//int main(){
//    int sum = 0;
//    int a = 10;
//    int b = 20;
//    sum = ADD(a,b);
//    printf("%d\n",sum);
//    return 0;
//}
//#include <stdio.h>//数组
//int main(){
//    int arr[10] = {1,2,3,4,5,6,7,8,9,0};//定义一个存放10个整形数字的数组
//    //数组内的数据从0开始
//    //char ch[20];//
//    //float arr2[5];
//    printf("%d\n",arr[8]);
//    int i = 0;
//    while(i<10){//打印整个数组的字符串
//        printf("%d ",arr[i]);
//        i++;
//    }
//    return 0;
//}
//移(二进制)位操作符0000000001整体移动用0补齐
// << 左移操作符
// >> 右移操作符
//#include <stdio.h>
//int main(){
//    int a = 1;
//    int b = a<<3;
//    printf("%d\n",b);
//    printf("%d\n",a);
//    return 0;
//}
////按位(二进制)位操作-位操作符
//#include <stdio.h>
//int main(){
//    int a = 1;//001
//    int b = 3;//011
//    printf("a&b=%d\n",a&b);//与 一假则假
//    printf("a|b=%d\n",a|b);//或 一真则真
//    printf("a^b=%d\n",a^b);//异或 相同为假不同为真
//    return 0;
//}
//复合赋值符
// += -= *= /= %= >>= <<= &= |= ^=
//#include <stdio.h>
//int main(){
//    int a = 10;
//    //a = a + 10;
//    //a += 10;
//    a -= 20;
//    a &= 2;
//    return 0;
//}
//单目操作符
//双目操作符
//三目操作符
//单目操作符[!]真假交换
//sizeof()计算变量/类型所占空间的大小，单位是字节
//#include <stdio.h>
//int main(){
//    int a = 10;// C语言中，0——假；非0——真
//    printf("%d\n",a);//
//    printf("%d\n",!a);//单目操作符[!]真假交换
//    int a = -2;
//    int b = -a;
//    printf("%d\n",b);
//    int arr[10] = {0};//10个整型元素的数组大小为40
//    char a[] = {'a','d','h'};
//    int sz = 0;
//    sz = sizeof(arr)/sizeof(arr[0]);
//    printf("%lu\n",sizeof(long));
//    printf("%lu\n",sizeof(arr));
//    printf("%lu\n",sizeof(a));
//    printf("数组中有多少元素=%d\n",sz);
//    return 0;
//}
//自定义函数的使用！！！！
//自定义函数的使用！！！！
//自定义函数的使用！！！！
//自定义函数的使用！！！！
//自定义函数的使用！！！！
//#include <stdio.h>
//int Max(int x, int y)
//{
//    if(x>y)
//        return x;
//    else
//        return y;
//}
//int main(){
//    int num1 = 10;
//    int num2 = 10;
//    int max = 0;
//    if(num1==num2)
//        printf("两数相等无最大值\n");
//    else
//        max = Max(num1, num2);
//        printf("max = %d\n",max);
//    return 0;
//
//}
//单目操作符
// ~ 二进制按位取反
//a++ 先使用，再++； a-- 先使用 再--
//++a 先++ 再使用；  --a 先-- 再使用
//#include <stdio.h>
//#include <string.h>
//int main(){
//    int a = (int)3.14;//强制类型转换
//    printf("%d\n",a);
////    int a = 10;
//    //int b = a++;
//    int c = ++a;
//    printf("a=%d    c=%d\n",a,c);
//    int a = 0;//000000000000000000000000000000000000
//    int b = ~a;//11111111111111111111111111111111111负数是补码的原码为-1
//    printf("b=%d\n",b);//b=-1
//    int a = 10;
//    int num = 0;
//    int arr[] = { 1, 2, 3, 4, 5, 6 };
//    printf("%lu\n",sizeof(a));
//    printf("%lu\n",sizeof(int));
//    printf("%lu\n",sizeof(arr));
//    num = sizeof(arr)/sizeof(arr[1]);
//    printf("数组中的元素有%d个\n",num);
//    return 0;
//}
// 关系操作符
// > < >= <= != ==
//逻辑操作符
// && 逻辑与 一假则假    || 逻辑或  一真则真
//#include <stdio.h>
//int main(){
//    int a, b, c;
//    a = 0;
//    b = -2;
//    c = a||b;
//    printf("%d\n",c);
//    return 0;
//
//}
//条件操作符
//#include <stdio.h>
//int main(){
//    int a = 10;
//    int b = 20;
//    int max = 0;
//    max = (a>b ? a:b);
//    printf("max = %d\n",max);
//    return 0;
//}


//常见关键字
//auto break case char const continue default do double else enum(枚举) extern(引入外部变量) float for goto if int long register(寄存器关键字) return short signed(signed(省略了) int) [unsigned int](无符号位的数) sizeof static struct(结构体关键字) switch typedef(类型定义，类型重定义) union(联合体/共用体) unsigned void volatile while
//typedef——类型重定义
//#include <stdio.h>
//int main(){
//    typedef signed int s_int;
//    signed int a = 10;
//    s_int b = 20;
//    printf("%d\n%d\n",a,b);
//    return 0;
//}
//static——只运行一次
//#include <stdio.h>
//void test(){
//    static int a = 1;//是静态的局部变量
//    a++;
//    printf("a = %d\n",a);
//}
//int main(){
//    int i = 0;
//    while(i<5){
//        test();
//        i++;
//    }
//    return 0;
//}
//#include <stdio.h>
//int main(){
//    extern int g_val;//引入全局变量g_val
//    printf("引入的  变量g_val = %d\n",g_val);
//    return 0;
//}
// extern 外部引用
//#include <stdio.h>
//extern int Add(int,int);//err引用的外部属性被static改变了全局变量无法引用
//int main(){
//    int a = 20;
//    int b = 20;
//    int sum = 0;
//    sum = Add(a,b);
//    printf("sum = %d \n",sum);
//    return 0;
//}
// # define 定义宏
//#include <stdio.h>
//#define MAX(X,Y) (X>Y?X:Y)
//int main(){
//    int a = 0;
//    int v = 12;
//    int m = 23;
//    int max = 0;
//    a = MAX(v,m);
//    max = 34>63?34:63;
//    printf("MAX = %d\nmax = %d\n",a,max);
//    return 0;
//}


//**************指针*************//
//int* 存地址
//*p 解地址     存的地址&a与p相等
//#include <stdio.h>
//int main(){
//    int a = 10;//4个字节
//    printf("a = %d\n",a);
//    // & 取地址操作符
//    int* p = &a;//指针变量用来存放地址
//    printf("p = %p\n",p);
//    printf("a的地址：%p\n",&a);
//    if(p==&a)
//        printf("等于\n");
//    else
//        printf("不等\n");
//    *p = 20;//通过地址赋值给 a -> 20
//    printf("a = %d\n",a);
//    return 0;
//}
//
//#include <stdio.h>
//int main(){
//    char ch = 'w';
//    char* pc = &ch;
//    *pc = 'C';
//    printf("%c\n",ch);
//    return 0;
//}
//#include <stdio.h>
//int main(){
//    int ch = 3;
//    int* pc = &ch;
//    *pc = 3;
//    printf("%lu\n",sizeof(pc));
//    return 0;
//}
//#include <stdio.h>
//int main(){
//    int a = 10;
//    printf("%p\n",&a);
//    int* p = &a;
//    *p = 20;
//    printf("%p\n",p);
//    printf("%p\n",&a);
//    printf("%d\n",a);
//    return 0;
//}
//#include <stdio.h>
//int main(){
//    double d = 3.141;
//    double* pd = &d;
//    printf("%lf\n",*pd);
//    *pd = 3.1415;
//    printf("%lf\n",d);
//    printf("%lu\n",sizeof(d));
//    printf("%lu\n",sizeof(char*));
//    printf("%lu\n",sizeof(int*));
//    printf("%lu\n",sizeof(short*));
//    printf("%lu\n",sizeof(double*));
//    return 0;
//}
//结构体
//#include <stdio.h>
//#include <string.h>
////创建一个结构体类型
//struct Book
//{
//    char name[20];
//    short p;
//};
//
//int main(){
//    struct Book b1 = {"C语言程序设计",55};//利用结构体类型创建一个该类型的结构体变量
//    struct Book *pb = &b1;
//    //利用pd打印书名和价格
//    printf("%s\n",(*pb).name);
//    printf("%d\n",pb->p);
//    printf("书名：%s\n",b1.name);
//    printf("价格：%d\n",b1.p);
//    b1.p = 15;
//    strcpy(b1.name,"C++");
//    printf("修改后的书名%s\n",b1.name);
//    printf("修改后的价格 = %d\n",b1.p);
//    return 0;
//}
//********每天一道算法题，猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不过瘾，又多吃了一个。第二天早上又将第一天剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃前一天剩下的一半零一个。到第十天早上想再吃时，发现只剩下一个桃子了。编写程序求猴子第一天摘了多少桃。
//#include <stdio.h>
//int main(){
//    int day,x1,x2;
//    day = 9;
//    x2 = 1;
//    while(day>0)
//    {
//        x1 = (x2+1)*2;
//        x2 = x1;
//        day--;
//    }
//    printf("猴子第一天摘了%d个桃:\n",x2);
//    return 0;
//}
// 2022.1.19
// 中国古代数学家张丘建在他的《算经》中提出了一个著名的“百钱买百鸡的问题”，鸡翁一，值钱五，鸡母一，值钱三，鸡雏三，值钱一，百钱买百鸡，问翁、母、雏各几何？
//翁 <= 20 母 <= 30  雏 <= 300
//#include <stdio.h>
//int main(){
//    int w, m, c;
//    for(w = 0;w <= 20;w++)
//        for(m = 0;m <= 34;m++)
//            for(c = 0; c <= 300; c++)
//                if(c%3==0)
//                    if(w + m + c == 100 && w * 5 + m * 3 + c / 3 * 1 ==100)
//                    printf("翁%d只，母%d只，雏%d只\n价钱为%d\n\n",w,m,c,w * 5 + m * 3 + c /3);
//    return 0;
//}
//***********************分支和循环语句
//#include <stdio.h>
//int main(){
    
//    for(int i = 1;i <= 100;i++){
//        if(i % 2 == 0){
//            printf("1-100之间为偶数的是%d\n",i);
//        }
//        else
//            printf("1-100之间的奇数为%d  ",i);
//    }
//    return 0;
//}
//#include <stdio.h>
//int main(){
//    int day = 0;
//    int a = 0;
//    scanf("%d",&day);
//    switch(day){
//        case 1:
//            if(0 == a)
//                printf("哈哈今天星期一了\n");
//        case 2:
//        case 3:
//        case 4:
//        case 5:
//            printf("工作日\n");
//            break;
//        case 6:
//        case 7:
//            printf("休息日\n");
//            break;
//        default://可有可无，处理非法选项。与case没有顺序，可以随便放，不过建议放在最后；
//            printf("输入错误\n");
//            break;
//    }
//    return 0;
//}
//  while 循环
//#include <stdio.h>
//int main(){
//    int i = 1;
//    while(i<=10){
//        if(5 == i)
//            break;
//        printf("%d ",i);
//        i++;
//    }
//    return 0;
//}
//#include <stdio.h>
//int main(){
//    int i = 1;
//    while(i<=10)
//    {
//        i++;
//        if(5 == i){
//            continue;//后面的不执行，从头开始 停止本次循环，开始下一次循环。
//            }
//        printf("%d ",i);
//
//    }
//    return 0;
//}
//
//#include <stdio.h>
//int main(){
//    int ch = 0;//getchar 是转换为ascll码 所以定义为int类型
    //EOF = end of file -> -1
//    while((ch = getchar()) != EOF)
//    {
//        putchar(ch);
//    }
