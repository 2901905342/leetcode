
//和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。
//
//现在，给你一个整数数组 nums ，请你在所有可能的子序列中找到最长的和谐子序列的长度。
//
//数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。




#include <iostream>
#include <vector>
#include<unordered_map>   
#include <algorithm>
using namespace std;


//
//头文件：#include<unordered_map> ！！！！！！！！！！
//
//创建表 unordered_map<key, value> Map_name;
//
//初始化 Map_name[key] = value(key, value 是指数据类型)
//
//插入元素 ①Map_name[key] = value;
//② Map_name.insert(pair<int, int>(key, value));
//③ unordered_map<int, int>Map_name = { {key1,value1},{key2,value2} };
//
//查找键值 table_name.find(key)
//
//创建迭代器 unordered_map<key, value>::iterator iterator_name;
//
//用迭代器访问元素的键值 it->first
//用迭代器访问元素的键值对应的元素值 it->second
//
//常用函数：
//
//Map_name.emty()：空为真，非空为假。
//
//Map_name.erase(key值)：如果没有找到返回0。
//
//Map_name.find(要查找的值)：找到的话，则返回key，不存在的话，返回.end（）， 一般通过Map_name.find(key) == Map_name.end()来判断key值是否存在。
//
//Map_name.count（key）函数：用以统计key值在unordered_map中出现的次数。c++ unordered_map不允许有重复的key。因此，如果key存在，则count返回1，如果不存在，则count返回0。
//



class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int res = 0;
        for (int num : nums) {
            cnt[num]++;
        }
        
        for (auto & key : cnt) {
            if (cnt.count(key.first + 1)) {
                res = max(res, key.second + cnt[key.first + 1]);
            }
            //auto & key : cnt  遍历哈希表
            //用迭代器访问元素的键值 it->first
            // 如果等于key.first +1的键值存在，记录和谐序列的长度
            //用迭代器访问元素的键值对应的元素值 it->second
            //cnt[key.first]等效于key.second
        }
        return res;
    }
};