//给定圆的半径和圆心的位置，实现函数 randPoint ，在圆中产生均匀随机点。
//实现 Solution 类 :
//Solution(double radius, double x_center, double y_center) 用圆的半径 radius 和圆心的位置(x_center, y_center) 初始化对象
//randPoint() 返回圆内的一个随机点。圆周上的一点被认为在圆内。答案作为数组返回[x, y] 。

//  角度0-2pi均匀分布，半径的平方在0-1均匀分布


#include "myhead.h"
class Solution {
public:
    double  r;
    double x;
    double y;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }

    vector<double> randPoint() {
        // double temp_angle = rand() / double(RAND_MAX) * 2*3.14159;
        double temp_angle = rand() / double(RAND_MAX) * 2 * acos(-1);
        double temp_r = sqrt(r * r * rand() / double(RAND_MAX));
        double mx = x + temp_r * cos(temp_angle);
        double my = y + temp_r * sin(temp_angle);
        return { mx,my };
    }
};
