//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。



////双指针法
//对于字符串，我们定义两个指针（也可以说是索引下表），
//一个从字符串前面，一个从字符串后面，两个指针同时向中间移动，并交换元素

#include "myhead.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        int left = 0;
        int right = n - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }

    }
};