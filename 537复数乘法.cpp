//复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：
//实部 是一个整数，取值范围是[-100, 100]
//虚部 也是一个整数，取值范围是[-100, 100]
//给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，返回表示它们乘积的字符串。

///////思路： 先找到加号的位置，从开始到+的前一元素为实部，从+的下一个位置到i之前为虚部
///值得注意的是stoi函数和to_string函数，它们都定义在头文件<string>中
////to_string 函数 将数值类型如int、double、long等转化为string转换并返回
/// stoi 函数 作用是将字符串转化为int型
#include "myhead.h"
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int pos1 = num1.find('+', 0);  //找到i的位置
        int pos2 = num2.find('+', 0);
        int r1 = stoi(num1.substr(0, pos1));  //实部
        int r2 = stoi(num2.substr(0, pos2));
        int v1 = stoi(num1.substr(pos1 + 1, num1.size() - 1 - pos1)); //虚部
        int v2 = stoi(num2.substr(pos2 + 1, num2.size() - 1 - pos2));
        return to_string(r1 * r2 - v1 * v2) + '+' + to_string(r1 * v2 + v1 * r2) + 'i';

    }
};