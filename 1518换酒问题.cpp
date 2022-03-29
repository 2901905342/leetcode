//小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。
//如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。
//请你计算 最多 能喝到多少瓶酒。




#include "myhead.h"

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;  //将酒喝光
        while (numBottles >= numExchange) {
            res += numBottles / numExchange;  //将空酒瓶尽可能多地换成酒并喝光
            numBottles = numBottles % numExchange + numBottles / numExchange;  //计算新一轮的空酒瓶数目
        }
        return res;
    }
};