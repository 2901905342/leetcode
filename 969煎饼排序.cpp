//给你一个整数数组 arr ，请使用 煎饼翻转 完成对数组的排序。
//一次煎饼翻转的执行过程如下：
//选择一个整数 k ，1 <= k <= arr.length
//反转子数组 arr[0...k - 1]（下标从 0 开始）
//例如，arr = [3, 2, 1, 4] ，选择 k = 3 进行一次煎饼翻转，反转子数组[3, 2, 1] ，得到 arr = [1, 2, 3, 4] 。
//以数组形式返回能使 arr 有序的煎饼翻转操作所对应的 k 值序列。
//任何将数组排序且翻转次数在 10 * arr.length 范围内的有效答案都将被判断为正确。

/////注意：题目中没有要求k值序列的长度最短，只要是有效的都可以
///一种有效的解决方案是：
//设一个元素的下标是 index，我们可以通过两次煎饼排序将它放到尾部：
//第一步选择 k = index + 1，然后反转子数组 arr[0...k−1]，此时该元素已经被放到首部。
//第二步选择k = n，其中 n 是数组 arr 的长度，然后反转整个数组，此时该元素已经被放到尾部。
//通过以上两步操作，我们可以将当前数组的最大值放到尾部，然后将去掉尾部元素的数组作为新的处理对象，
//重复以上操作，直到处理对象的长度等于一，此时原数组已经完成排序，
//且需要的总操作数是 2×(n−1)，符合题目要求。如果最大值已经在尾部，我们可以省略对应的操作。

//// max_element函数需要<algorithm>库，返回一个左闭右开区间内的最大值元素的迭代器（可以理解为最大值元素的地址）
/// 用该迭代器减去容器第一个元素的迭代器就得到最大值元素在数组中的索引位置
///  与之对应的还有min_element函数
#include "myhead.h"
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        for (int n = arr.size(); n > 1; n--) {
            int max_index = max_element(arr.begin(), arr.begin() + n) - arr.begin();
            if (max_index == n - 1) continue;
            reverse(arr.begin(), arr.begin() + max_index + 1); //将最大值翻转到容器首部
            reverse(arr.begin(), arr.begin() + n);    //将位于容器首部的最大值翻转到n-1的位置
            res.push_back(max_index + 1);
            res.push_back(n);
        }
        return res;
    }
};