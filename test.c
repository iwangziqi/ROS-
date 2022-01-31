//
//  test.c
//  CProject
//
//  Created by 王先生 on 2022/1/17.
//

////#include <stdio.h>
//static int Add(int x, int y)
//{
//    int z = 0;
//    z = x + y;
//    return z;
//}





//      学习笔记
//#include <stdio.h>
//int main()
//{
//    //先定义几个后面用到的数据
//    int a = 10;
//    int b = 20;
//    int num1 = 1;
//    int num2 = 2;
//    // + 加法操作符
//    int sum = a + b;
//    printf("a + b = %d\n",sum);// a + b = 30
//    // - 减法操作符
//    int dis = a - b;
//    printf("a - b = %d\n",dis);// a - b = -10
//    // * 乘法操作符
//    int mul = a * b;
//    printf("a * b = %d\n",mul);// a * b = 200
//    // / 除法操作符
//    int div = b / a;
//    printf("b / a = %d\n",div);// b / a = 2
//// 位操作符
//    // & 与  二进制与 一假则假(遇0则0)
//    int And = num1 & num2;
//    printf("num1 & num2 = %d\n",And);// num1 & num2 = 0
//        //要将num1 num2 转换为二进制数按位与
//        // 1 -> 01
//        // 2 -> 10  第一位相与 -> 0；第二位相与 -> 0；=>> 00; 00在二进制中表示为0 所以num1&num2=0；
//    // | 或  二进制或 一真则真(遇1则1)
//    int Or = num1 | num2;
//    printf("num1 | num2 = %d\n",Or);// num1 | num2 = 3
//        //位操作符都要将数转换为二进制计算
//        // 1 -> 01
//        // 2 -> 10  第一位相或 -> 1;第二位相或 -> 1; ==>>11; 11在二进制中表示为3 所以num1|num2=3;
//    // ^ 异或  二进制异或 同为假 不同为真
//    int xor = num1 ^ num2;
//    printf("num1 ^ num2 = %d\n",xor);//num1 ^ num2 = 3
//        // 1 -> 01
//        // 2 -> 10 第一位异或 ->1 ;为二位异或 ->1 ; ==>>11; 11在二进制中表示为3  所以num1^num2=3;
//    // ~ 二进制位取反
//    printf("a按位取反 ～a = %d\n",~a);//a按位取反 ～a = -11
//        //在计算机中 10 的存储方式为 00000000000000000000000000001010
//        // -11 在计算机是以补码的形式存在的
//    
//    
//    
//    return 0;
//}
//
//
