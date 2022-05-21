#include <stdio.h>
int fac(int n){//给递归求阶乘#####################
    if(n != 1)
       return n*fac(n-1);
    else
        return 1; 
}
int main(){
    int n = 0;
    printf("请输入要求得的阶乘:>");
    scanf("%d",&n);
    int ret = fac(n);
    printf("%d! = %d",n,ret);
    return 0;
}