//最大公约数（英语：greatest common divisor，gcd）是数学词汇，指能够整除多个整数的最大正整数。
//一般求法辗转相除法：两数相除，取余数重复进行相除，直到余数为0时，前一个除数即为最大公约数。


//1.while循环（常速）
//此段代码a、b可以为0
//迭代算法
int gcd(int a, int b)  
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//2.三目运算符（较快）
//此段代码a、b可以为0

int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a % b) : a;
}

//3.位运算（超快）
//此段代码a、b不能为0

int gcd(int a, int b)
{
    while (b ^= a ^= b ^= a %= b);
    return a;
}

//4.if + while + 位运算（超快）
//此段代码a、b可以为0
 int gcd(int a, int b)
{
    if (b) while ((a %= b) && (b %= a));
    return a + b;
}

//5.辗转相除法（较快）  递归算法
//此段代码a、b不能为0
 int gcd(int a, int b)
 {
     if (a % b == 0)
         return b;
     else return (gcd(b, a % b));
 }

 //6.gcd库函数（较慢）
 //    此段代码a、b可以为0
 // 奇怪的事情：我的algorithm库并不能识别_gcd库函数
//#include <algorithm>
// inline int gcd(int a, int b) {
//     return __gcd(a, b);
