//给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。
//所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。

///思路1：遍历+替换
#include "myhead.h"
class Solution {
public:
    string defangIPaddr(string address) {
        string res = address;
        vector<int>record;
        for (int i = 0; i < address.size(); i++) {
            if (address[i] == '.') record.push_back(i);
        }
        for (int i = 0; i < record.size(); i++) {
            res.replace(record[i] + 2 * i, 1, "[.]");
        }
        return res;
    }
};

///官方写法 ：速度更快，空间更小
class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (auto& c : address) {
            if (c == '.') {
                ans.append("[.]");
            }
            else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};

