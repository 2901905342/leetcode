//С�����������ڴ������� numExchange ���վ�ƿ���Զһ�һƿ�¾ơ��㹺���� numBottles ƿ�ơ�
//����ȵ��˾�ƿ�еľƣ���ô��ƿ�ͻ��ɿյġ�
//������� ��� �ܺȵ�����ƿ�ơ�




#include "myhead.h"

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;  //���ƺȹ�
        while (numBottles >= numExchange) {
            res += numBottles / numExchange;  //���վ�ƿ�����ܶ�ػ��ɾƲ��ȹ�
            numBottles = numBottles % numExchange + numBottles / numExchange;  //������һ�ֵĿվ�ƿ��Ŀ
        }
        return res;
    }
};