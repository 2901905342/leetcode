//你的任务是为一个很受欢迎的银行设计一款程序，以自动化执行所有传入的交易（转账，存款和取款）。
//银行共有 n 个账户，编号从 1 到 n 。每个账号的初始余额存储在一个下标从 0 开始的整数数组 balance 中，其中第(i + 1) 个账户的初始余额是 balance[i] 。
//
//请你执行所有 有效的 交易。如果满足下面全部条件，则交易 有效 ：
//
//指定的账户数量在 1 和 n 之间，且
//取款或者转账需要的钱的总数 小于或者等于 账户余额。
//实现 Bank 类：
//
//Bank(long[] balance) 使用下标从 0 开始的整数数组 balance 初始化该对象。
//boolean transfer(int account1, int account2, long money) 从编号为 account1 的账户向编号为 account2 的账户转帐 money 美元。如果交易成功，返回 true ，否则，返回 false 。
//boolean deposit(int account, long money) 向编号为 account 的账户存款 money 美元。如果交易成功，返回 true ；否则，返回 false 。
//boolean withdraw(int account, long money) 从编号为 account 的账户取款 money 美元。如果交易成功，返回 true ；否则，返回 false 。

/////思路：简单模拟
#include "myhead.h"
class Bank {
public:
    vector<long long>record;
    Bank(vector<long long>& balance) {
        record = balance;
    }

    bool transfer(int account1, int account2, long long money) {
        int n = record.size();
        if (account1 <= 0 || account1 > n || account2 <= 0 || account2 > n) return false;
        if (record[account1 - 1] < money) return false;
        record[account1 - 1] -= money;
        record[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {

        if (account <= 0 || account > record.size()) return false;
        record[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account <= 0 || account > record.size()) return false;
        if (record[account - 1] < money) return false;
        record[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */