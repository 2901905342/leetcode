//自除数 是指可以被它包含的每一位数整除的数。
//例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
//自除数 不允许包含 0 。
//给定两个整数 left 和 right ，返回一个列表，列表的元素是范围 [left, right] 内所有的 自除数 。


////思路：简单模拟
#include "myhead.h"
class Solution {
public:
    bool zhichunumber(int& num) {
        int col = num;
        while (col) {
            int r = col % 10;
            if (!r || num % r) return false;
            col /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (zhichunumber(i)) res.push_back(i);
        }
        return res;
    }
};