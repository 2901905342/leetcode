//你正在参加一个多角色游戏，每个角色都有两个主要属性：攻击 和 防御 。
//给你一个二维整数数组 properties ，其中 properties[i] = [attacki, defensei] 表示游戏中第 i 个角色的属性。
//如果存在一个其他角色的攻击和防御等级 都严格高于 该角色的攻击和防御等级，则认为该角色为 弱角色 。
//更正式地，如果认为角色 i 弱于 存在的另一个角色 j ，那么 attackj > attacki 且 defensej > defensei 。
//返回 弱角色 的数量。

//////////思路：排序+比较
//在按照攻击降序，且攻击相同时防御升序排列后，记录最大防御，
//假设当前的防御比之前的最大防御小，即可确认当前的是弱角色，
//理由是：在相同的攻击内，防御是升序，出现的防御大于当前，肯定是来自于攻击更大的那些组
#include "myhead.h"

class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b) {
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] > b[0];
    }// 很奇怪，这里得用静态变量，否则会报错
    /*这个问题是指你引用（调用）了非静态函数，但你不是通过类对象来调用的。问题的来源就是sort（）函数的第三个谓词参数。为什么会是这样的呢？
    按照常理来说，同一个类的非静态const成员函数中能相互调用，而不用通过类对象进行访问，为什么这里不行呢？相反如果我们把谓词函数com（）定义为static函数问题就没有了。
    问题的原因其实就是函数参数不匹配的问题。因为我们普通的成员函数都有一个隐含的this指针，表面上看我们的谓词函数com（）只有两个参数，但实际上它有三个参数，而我们调用sort（）排序函数的时候只需要用到两个参数进行比较，所以就出现了形参与实参不匹配的情况（函数有三个形参，但是只输入了两个实参）
     所以，解决办法就是把谓词函数com（）定义为static成员函数。*/
       
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        int maxDef = 0;
        int ans = 0;
        for (int i = 0; i < properties.size(); i++) {
            if (properties[i][1] < maxDef) {
                ans++;
            }
            else {
                maxDef = properties[i][1];
            }
        }
        return ans;
    }
};

/////////官方写法，很奇怪，如果sort()函数排序不使用官方这种lamda隐函数的写法
//////  就一定会超时，太奇怪了。明明过程都是一样的

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? (a[1] < b[1]) : (a[0] > b[0]);
            });

        int maxDef = 0;
        int ans = 0;
        for (auto& p : properties) {
            if (p[1] < maxDef) {
                ans++;
            }
            else {
                maxDef = p[1];
            }
        }
        return ans;

    }
};