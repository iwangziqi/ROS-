//WangTest.c
//CProject
//
//Created by 王先生 on 2022/1/16.
//
//当实参传给形参的时候，形参其实是实参的一份临时拷贝
//对形参的修改不会改变实参，形参是独立又开发出来的一块地址空间，不改变实参的地址。
/*函数的调用——传值调用、传址调用######如果外部参数需要改变就用传址，只获取值的话用传值。
//传值调用——函数的形参和实参分别占有不同的内存块，对形参的修改不会影响实参
//传址调用——把函数外部创建变量的内存地址传递给函数参数的一种调用方式
//这种传参方式可以让函数和函数外边的变量建立起真正的联系，也就是函数的内部可以直接操作函数外部的变量。
//当实参传给形参的时候，形参其实是实参的一份临时拷贝
对形参的修改不会改变实参，形参是独立又开发出来的一块地址空间，不改变实参的地址。
*/
//这是逻辑，不是算数！
//类型char int float short double long longlong
//常见关键字
//auto break case char const continue default do double else enum(枚举) extern(引入外部变量) float for goto if int long register(寄存器关键字) return short signed(signed(省略了) int) [unsigned int](无符号位的数) sizeof static struct(结构体关键字) switch typedef(类型定义，类型重定义) union(联合体/共用体) unsigned void volatile while
//char arr[] = "welcome"==welcome\0  最后一位要减2  sizeof(arr)/sizeof(arr[0])//strlen(arr)-1{求字符串长度到/0就停止}
//if(strcmp(usr_psd,pad)  == 0)//等号不能用来判断两个字符串是否相等，要用库函数  括号内的相等返回0否则返回1
#include <stdio.h>
#include <string.h>//strcpy(arr2,arr1);strlen()字符的长度
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>//字符串比较函数的头文件strcmp
#include <time.h>//时间函数 long型长整型 随机数会用到
#include <stdlib.h>//随机数rand的头文件
//include <curses.h>
//#include <ncurses.h>
#include <math.h>//数学库->sqrt()开平方；
//##################函数的声明和定义(有递归)#########

//斐波那契额数列
//1 1 2 3 5 8 13 21 34 55前两个数之和等于第三个

// int fac(int n){//给递归求阶乘#####################
//     if(n != 1)
//        return n*fac(n-1);
//     else
//         return 1; 
// }
// int main(){
//     int n = 0;
//     printf("请输入要求得的阶乘:>");
//     scanf("%d",&n);
//     int ret = fac(n);
//     printf("%d! = %d",n,ret);
//     return 0;
// }

// int my_strlen(char* len){//模拟一个strlen函数
//     int count = 0;//普通方法需要创建一个临时变量；
//     while(*len != '\0'){
//         count++;
//         len++;//所以这里是进行下一位的判断
//     }
//     return count;
// }
// int my_strlen(char* arr){
//     if(*arr != '\0')
//     {
//         return 1+my_strlen(arr+1);
//     }
//     else
//         return 0;
// }
// int main(){
//     char arr[] = "Hello";//arr :  H e l l o /0
//     //模拟一个strlen函数
//     int len = my_strlen(arr);//arr是数组，数组传参，传过去的不是整个数组，而是第一个元素的地址
//     printf("%d\n",len);
//     return 0;
// }

//代码从前往后执行扫描，函数的定义一定要放在main前面，如果放在后面，要现在main之前对函数进行定义如下
// int Add(int, int);//####函数的定义#放在main前面不需要声明
//此种情况可以自己创建头文件，把声明放在头文件里，把实现放在.c文件里，就可以用双引号引用头文件直接使用
//分模块的项目可以用
// #include "Add.h"//没办法用，P哥会有一个头文件的文件夹，我的没有，所以不知道头文件放在哪
// int main(){
//     int a = 1;
//     int b = 20;
//     int sum = 0;
//     sum = Add(a, b);
//     printf("%d\n",sum);
// }
// int Add(int x, int y){
//     int z = x + y;
//     return z;
// }

//##################函数的嵌套调用和链式访问########################
// int main(){
//     printf("%d\n",printf("%d\n",printf("哈哈哈哈哈")));//printf返回的值是字符的位数
//     return 0;
// }
//##################初识指针和函数###########################
// void Add(int* count){//再次运用指针
//     (*count)++;//##############优先级是先++  所以要把地址引用起来，先抓取地址然后++
//     return *count;
// }
// int main(){
//     int count = 0;
//     // printf("请输入第一个值:>");
//     // scanf("%d",&a);
//     // printf("请输入第二个值:>");
//     // scanf("%d",&b);
//     Add(&count);
//     Add(&count);
//     Add(&count);
//     printf("函数被调用%d次",count);
//     return 0;
// }

// int binary_chop(int arr[],int num,int sz)
// {//函数实现 二分查找
//     int left = 0;
//     int right = sz - 1;
//     while(left<=right){
//         int mid = (left+right)/2;
//         if(num<arr[mid])
//             right = mid - 1;
//         else if(num>arr[mid])
//             left = mid + 1;
//         else
//             return mid;    
//     }
//     return -1;
// }
// int main(){
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int sz = sizeof(arr)/sizeof(arr[0]);//总数组的长度-1就是右下标
//     int num = 0;
//     printf("%d请输入要查找的数值:>",sz);
//     scanf("%d",&num);
//     int ret = binary_chop(arr,num,sz);
//     if(ret == -1)
//         printf("无\n");
//     else   
//         printf("角标=%d\n",ret);
//     return 0;
// }

// int binary_chop(int arr[],int z)//数组要用传址，应该用指针
// {
//     int sz = sizeof(arr)/sizeof(arr[0])
//     int left = 0;
//     int right = sz - 1;
//     while(left<=right){
//     int mid=(left+right)/2;
//     if(z>arr[mid])
//         left = mid+1;
//     else if(z<arr[mid])
//         right = mid-1;
//     else if(z = arr[mid])
//         return 1;
//     }
//     return 0; 
// }
// int main(){
//     int a = 0;
//     int arr[]={1,2,3,4,5,6,7,8,9,10};//普通只能传递首元素，数组要用传址
//     printf("请输入你要查找的数:>");
//     scanf("%d",&a);
//     if(binary_chop(arr,a)==1)
//     {
//         printf("下标为:>%d\n",a);
//     }
//     else
//         printf("数组中无");
    
//     // int arrright=sizeof(arr)/sizeof(arr[0]);
//     // int arrleft=sizeof(arr);
//     // printf("l = %d r = %d\n",arrleft,arrright);

//     return 0;
// }

// int is_leapyear(int y){//四年一润，百年不润，四百年再润
//     if((y%4==0&&y%100!=0)||(y%400==0))
//         return 1;
//     else
//         return 0;//和素数感觉相反，素数必须放在外面return 1，这个必须放在里面return 0；
// }
// int main()
// {
//     int year = 0;
//     for(year = 1000;year<2000;year++)
//         if(is_leapyear(year)==1)
//             printf("%d ",year);
//     return 0;
// }

// int is_prime(int x)//用函数判断是否为素数
// {
//     int num = 2;
//     for(num=2;num<=sqrt(x);num++)
//     {
//         if(x%num == 0)
//             return 0;
        
//     }
//     return 1;//这个必须放在外面不能用else放在里面会出错，因为不能判断一次就直接返回值。
// }
// int main(){
//     for(int i = 100;i<=200;i++)
//     {
//         if(is_prime(i) == 1)
//         {
//             printf("%d ",i);
//         }
//     }
//     return 0;
// }

// void Swap(int* x,int* y){//  简单的指针传递，不需要返回值，所以用void
/*函数的调用——传值调用、传址调用
//传值调用——函数的形参和实参分别占有不同的内存块，对形参的修改不会影响实参
//传址调用——把函数外部创建变量的内存地址传递给函数参数的一种调用方式
//这种传参方式可以让函数和函数外边的变量建立起真正的联系，也就是函数的内部可以直接操作函数外部的变量。
//当实参传给形参的时候，形参其实是实参的一份临时拷贝
对形参的修改不会改变实参，形参是独立又开发出来的一块地址空间，不改变实参的地址。
*/
//     int tmp = 0;
//     tmp = *x;
//     *x = *y;
//     *y = tmp;
// }
// int main(){
//     int a = 10;
//     int b = 20;
//     printf("a=%d,b=%d\n",a,b);
//     Swap(&a, &b);
//     printf("a=%d,b=%d\n",a,b);
//     printf("%p",&a);
//     return 0;
// }

// int get_max(int x,int y)
// {
//     int max;
//     if(x>y){
//         return x;
//     }
//     else if(x<y){
//         return y;
//     }
//     else(x==y);{
//         max = 0;
//     }
//     return max;
// }
// int main()
// {
//     int a, b;
//     printf("请输入第一个数的值:>");
//     scanf("%d",&a);
//     printf("请输入第二个数的值:>");
//     scanf("%d",&b);
//     int max = get_max(a, b);
//     printf("两个数的最大值为:>%d\n",max);
//     printf("若输出0则表示两个数一样大\n");
// }

// int main()//strcpy的测试字符串拷贝
// {
//     char arr1[] = "Cproject";
//     char arr2[20] = "##########";
//     printf("arr1=%s,arr2=%s\n",arr1,arr2);
//     strcpy(arr2,arr1);//会把字符串里的\0一起复制过来，所以除了复制的，原本字符串里的东西都不显示了
//     printf("arr1=%s,arr2=%s\n",arr1,arr2);
//     return 0;
// }

// int Add(int a, int b){
//     int z = a + b;
//     return z;
// }
// int main(){
//     int a = 10;
//     int b = 20;
//     int z = Add(a, b);
//     printf("%d\n",z);
//     return 0;
// }

// int main(){//goto语句的简单应用跳出程序 或者重新执行其他的
//     char input[20]={0};
//     system("shutdown -s -t 600");
//     anain:
//     printf("请注意，你的电脑在10分钟后关机，如果输入>:我是猪,则取消关机！\n请输入:>");
//     scanf("%s",input);
//     if(strcmp(input,"我是猪")==0)//比较两个字符串
//         {
//             system("shutdown -a");
//             printf("好的猪，我已取消关机指令\n");
//             system("pause");
//         }
//     else{
//             goto anain;
//         }
//         //shutdown -s -t 60 //60秒关机 shutdown -a 取消关机
//     return 0;
// }


// void meun(){//猜数字游戏无限循环time函数，rand产生随机数
//     printf("****************************************\n");
//     printf("******   1.开始游戏   0.退出游戏  ******\n");
//     printf("****************************************\n");
// }
// void game(){
//     int guess = 0;
//     int urs = 0;
//     //通过rand产生随机数需要配合time函数，不然每一次的随机数是固定的,生成1-100之间的数
//     urs = rand()%100+1;
//     printf("随机数字为：%d\n",urs);
//     printf("请输入您的数字>:");
//     while(1){
//         scanf("%d",&guess);
//         if(guess>urs){
//             printf("猜大了,继续>:");
//             continue;
//         }
//         else if(guess<urs){
//             printf("猜小了,继续>:");
//             continue;
//         }
//         else
//             printf("恭喜你，猜中了！\n");
//             break;
//     }
// }
// int main(){
//     int re = 0;
//     //固定的time函数为当前时间减去1940.1.1.0.0.0；
//     srand((unsigned int)time(NULL));
//     do
//     {
//         meun();
//         printf("请选择是否游戏>:");
//         scanf("%d",&re);
//         switch(re){
//             case 1:
//                 printf("游戏开始！\n");
//                 game();
//                 break;
//             case 0:
//                 printf("游戏结束！\n");
//                 break;
//             default:
//                 printf("选择出错，请重新选择\n");
//                 break;
//         }
        
        
//     } while (re);
    
//     return 0;
// }

// int main(){//99乘法表
//     int i = 1;
    
//     for(;i<=9;i++){
//         int j = 1;//j为什么在这定义可以，在for外面不可以。
//         for(;j<=i;j++)
//             printf("%d*%d=%-2d ",j,i,i*j);
//         printf("\n");
//     }

//     return 0;
// }

// int main(){//输出1/1-1/2+1/3....-1/100
//     int i =1;
//     double count = 0.0;
//     for(;i<=100;i++)
//         if(i % 2 == 0)
//             count -= 1.0/i;
//         else if(i % 2 != 0)
//             count += 1.0/i;
//     printf("1/1-1/2+1/3....-1/100＝%lf",count);
//     return 0;
// }

//1-100出现9的个数
// int main(){
//     int i = 1;
//     int count1 = 0;
//     for(;i<100;i++){
//         if(i % 10 == 9)
//             count1++;
//         if(i / 10 == 9)
//             count1++;
//     }
//     printf("i = %d,1-100中出现了%d次9",i,count1);

//     return 0;
// }

//int main(){
//    double a;
//    a = 17;
//    printf("%f\n",sqrt(a));
//    return 0;
//
//}
////判断素数，只能被1和本身除尽，2-n-1；
// int main(){
//    int i = 0;
//    int n = 2;
//    for(i=100;i<=200;i++)
//    {
//        for(n=2;n<i;n++)
//            {if(i%n==0){
//                break;}}
//        if(i==n)
//            printf("%d ",i);
//    }

//    return 0;
// }
// 最大公约数
// int main(){
//    int n,m,r=0;
//    scanf("%d%d",&n,&m);
//    while(r=n%m)
//    {
//        n=m;
//        m=r;
//    }
//    printf("%d\n",m);
//    return 0;
// }
// int sum(int a)//static保留函数
// {
//    int c = 0;
//    static int b = 3;
//    c += 1;
//    b += 2;
//    return (a + b + c);
// }
// int main()
// {
//    int i;
//    int a = 2;
//    for(i=0;i<5;i++)
//        printf("%d ",sum(a));
//    return 0;
// }
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

