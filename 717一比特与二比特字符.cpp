//有两种特殊字符：
//第一种字符可以用一个比特 0 来表示
//第二种字符可以用两个比特(10 或 11)来表示、
//给定一个以 0 结尾的二进制数组 bits ，如果最后一个字符必须是一位字符，则返回 true 。

/////思路：一种朴素的想法是将最后一个字符0去掉后，从前往后遍历字符串仍然是有效的
//对于去掉最后一位的字符串，从前遍历的时候，遇到0便是0，遇到1则必然是10或者11，若能恰好使得i遍历完所有，则说明有效

#include "myhead.h"

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() == 1) return true;
        bits.pop_back(); //去掉容器尾部元素
        int i = 0;
        while (i < bits.size() ) {
            if (bits[i] == 0) i++;
            else  i += 2;
        }
        return i == bits.size() ;

    }
};

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() == 1) return true;
        //bits.pop_back();  
        int i = 0;
        while (i < bits.size() - 1) {  //其实不必去掉尾部元素，直接在遍历的时候设置上限减一
            if (bits[i] == 0) i++;
            else  i += 2;
        }
        return i == bits.size() - 1;

    }
};

//////思路二：事實上因為只要數組最後一個數是0，那麼這個數組肯定可以被0，10，11分割。
//那麼只需要考慮最後一個0前面連續1的個數，個數是偶數則TRUE，否則FALSE。所以從數組末尾開始遍歷效率會更高。
//假设倒数第二个0的位置为i(i等于-1时表示字符串中只有末尾0），这中间1的个数为n-1-i-1=n-i-2,由于n-i-2与n-i的奇偶性相同，只用判断n-i的奇偶性就行
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), i = n - 2;
        while (i >= 0 and bits[i]) {
            i--;
        }
        return (n - i) % 2 == 0;
    }
};

