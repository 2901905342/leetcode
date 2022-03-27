//请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
//数字 1 - 9 在每一行只能出现一次。
//数字 1 - 9 在每一列只能出现一次。
//数字 1 - 9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
//注意：
//一个有效的数独（部分已被填充）不一定是可解的。
//只需要根据以上规则，验证已经填入的数字是否有效即可。
//空白格用 '.' 表示。
//board.length == 9
//board[i].length == 9
//board[i][j] 是一位数字（1 - 9）或者 '.'

//////////////本代码时空复杂度都是O（1）（1代表常数）
#include "myhead.h"
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false)); //记录某行，某位数字是否已经被摆放
        vector<vector<bool>> col(9, vector<bool>(9, false)); //记录某列，某位数字是否已经被摆放
        vector<vector<bool>> block(9, vector<bool>(9, false));// 记录某 3x3 宫格内，某位数字是否已经被摆放
        for (int i = 0; i < 9; i++) {  //i为行索引
            for (int j = 0; j < 9; j++) {  //j为列索引
                char temp = board[i][j];
                if (temp != '.') {
                    int pos = i / 3 * 3 + j / 3; //这里十分巧妙
                    ///(i/3*3,j)  分别为 （0,0）  （0,1）  （0,2）
                    //////////////////////(3,0)    (3,1)    (3,2)
                    //////////////////////(6,0)    (6,1)    (6,2)
                    int num = temp - '1';   //将char类型的"1"~"9" 转化为int 类型的0~8；
                    if (row[i][num] || col[j][num] || block[pos][num]) return false; //出现重复元素说明无效
                    row[i][num] = true;
                    col[j][num] = true;
                    block[pos][num] = true;
                }
            }
        }
        return true;
    }
};