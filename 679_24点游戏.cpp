//给定一个长度为4的整数数组 cards 。你有 4 张卡片，每张卡片上都包含一个范围在[1, 9] 的数字。
//您应该使用运算符 ['+', '-', '*', '/'] 和括号 '(' 和 ')' 将这些卡片上的数字排列成数学表达式，以获得值24。
//你须遵守以下规则 :
//除法运算符 '/' 表示实数除法，而不是整数除法。
//例如， 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12 。
//每个运算都在两个数字之间。特别是，不能使用 “ - ” 作为一元运算符。
//例如，如果 cards = [1, 1, 1, 1] ，则表达式 “ - 1 - 1 - 1 - 1” 是 不允许 的。
//你不能把数字串在一起
//例如，如果 cards = [1, 2, 1, 2] ，则表达式 “12 + 12” 无效。
//如果可以得到这样的表达式，其计算结果为 24 ，则返回 true ，否则返回 false 。
//cards.length == 4
//1 <= cards[i] <= 9


/////思路；游戏的第一步是挑出两个数，算出一个新数替代这两个数。
//然后，在三个数中玩 24 点，再挑出两个数，算出一个数替代它们。
//
//然后，在两个数中玩 24 点……
//
//很明显的递归思路。每次递归都会挑出两个数，我们尝试挑出不同的两数组合：
//
//挑 1、2，基于它，继续递归。
//挑 1、3，基于它，继续递归。
//挑 ……
//即通过两层 for 循环，枚举所有的两数组合，展开出不同选择所对应的递归分支。
//
//挑出的每一对数，我们…
//枚举出所有可能的运算操作：加减乘除…——（对应不同的递归调用）
//逐个尝试每一种运算——（选择进入一个递归分支）
//传入长度变小的新数组继续递归——（递归计算子问题）
//当递归到只剩一个数——（到达了递归树的底部），看看是不是 24 。
//是就返回 true——结束当前递归，并且控制它不进入别的递归分支，整个结束掉。
//否则返回 false，离开错误的分支，进入别的递归分支，尝试别的运算。


#include "myhead.h"
class Solution {
public:
    bool backtrack(vector<double>& list) {
        int n = list.size();
        if (n == 1) return abs(list[0] - 24.0) <= 1e-3;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<double>list2;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    list2.push_back(list[k]);
                }
                  // 标识变量isValid初始为 false，默认会执行||后面的递归。
                // 一旦某个递归返回真，isValid就变为真，由于||的短路特性，后面的递归不会执行
                bool flag = false;
                //计算加法
                list2.push_back(list[i] + list[j]);
                flag = flag || backtrack(list2);
                list2.pop_back();
                //计算乘法
                list2.push_back(list[i] * list[j]);
                flag = flag || backtrack(list2);
                list2.pop_back();
                //计算减法
                list2.push_back(list[i] - list[j]);
                flag = flag || backtrack(list2);
                list2.pop_back();

                list2.push_back(list[j] - list[i]);
                flag = flag || backtrack(list2);
                list2.pop_back();
                //计算除法
                if (list[j] != 0) {
                    list2.push_back(list[i] / list[j]);
                    flag = flag || backtrack(list2);
                    list2.pop_back();
                }

                if (list[i] != 0) {
                    list2.push_back(list[j] / list[i]);
                    flag = flag || backtrack(list2);
                    list2.pop_back();
                }
                if (flag) return true;

            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double>dcards;
        for (int card : cards) {
            dcards.push_back(double(card));
        }
        return backtrack(dcards);
    }
 
};