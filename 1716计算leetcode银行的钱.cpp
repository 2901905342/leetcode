//Hercy 想要为购买第一辆车存钱。他 每天 都往力扣银行里存钱。
//最开始，他在周一的时候存入 1 块钱。从周二到周日，他每天都比前一天多存入 1 块钱。
//在接下来每一个周一，他都会比 前一个周一 多存入 1 块钱。
//给你 n ，请你返回在第 n 天结束的时候他在力扣银行总共存了多少块钱。

///////////////思路   等差数列求和公式  sum=(首项+末项）*项数/2

#include "myhead.h"

///////////////初版////////
class Solution {
public:
    int totalMoney(int n) {
        int row = n / 7;
        int last = n % 7;
        int res = 0;
        int i = 1;
        while (i <= row) {
            int temp = 7 * i + 21;
            res += temp;
            i++;
        }
        if (last) {
            res += (2 * row + last + 1) * last / 2;
        }
        return res;
    }
};

//////////////////再版//////////
class Solution {
public:
    int totalMoney(int n) {
        int row = n / 7;
        int last = n % 7;
        int res = 0;
        int i = 1;
        res += (7 * row + 49) * row / 2;
        if (last) {
            res += (2 * row + last + 1) * last / 2;
        }
        return res;
    }
};