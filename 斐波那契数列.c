#include <stdio.h>
//斐波那契额数列
//1 1 2 3 5 8 13 21 34 55前两个数之和等于第三个
int Fib(int n){
    int a = 1;
    int b = 1;
    int c = 1;
    while(n >= 3)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}
// int Fib(int n){//时间复杂度太大了###################
//     count++;
//     if(1 <= n && n <= 2)
//         {
//             return 1;
//         }
//     else if(n >= 3)
//     {
//         return Fib(n-1) + Fib(n-2);
//     }
//     else
//         return -1;
// }
int main(){
    int n;
    printf("请输入你要求得的斐波那契数列的项:>");
    scanf("%d",&n);
    printf("第%d项为:>%d\n",n,Fib(n));
    return 0;

}