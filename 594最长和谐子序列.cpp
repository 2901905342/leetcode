
//��г������ָһ��������Ԫ�ص����ֵ����Сֵ֮��Ĳ�� ������ 1 ��
//
//���ڣ�����һ���������� nums �����������п��ܵ����������ҵ���ĺ�г�����еĳ��ȡ�
//
//�������������һ���������������������У�������ͨ��ɾ��һЩԪ�ػ�ɾ��Ԫ�ء��Ҳ��ı�����Ԫ�ص�˳����õ���




#include <iostream>
#include <vector>
#include<unordered_map>   
#include <algorithm>
using namespace std;


//
//ͷ�ļ���#include<unordered_map> ��������������������
//
//������ unordered_map<key, value> Map_name;
//
//��ʼ�� Map_name[key] = value(key, value ��ָ��������)
//
//����Ԫ�� ��Map_name[key] = value;
//�� Map_name.insert(pair<int, int>(key, value));
//�� unordered_map<int, int>Map_name = { {key1,value1},{key2,value2} };
//
//���Ҽ�ֵ table_name.find(key)
//
//���������� unordered_map<key, value>::iterator iterator_name;
//
//�õ���������Ԫ�صļ�ֵ it->first
//�õ���������Ԫ�صļ�ֵ��Ӧ��Ԫ��ֵ it->second
//
//���ú�����
//
//Map_name.emty()����Ϊ�棬�ǿ�Ϊ�١�
//
//Map_name.erase(keyֵ)�����û���ҵ�����0��
//
//Map_name.find(Ҫ���ҵ�ֵ)���ҵ��Ļ����򷵻�key�������ڵĻ�������.end������ һ��ͨ��Map_name.find(key) == Map_name.end()���ж�keyֵ�Ƿ���ڡ�
//
//Map_name.count��key������������ͳ��keyֵ��unordered_map�г��ֵĴ�����c++ unordered_map���������ظ���key����ˣ����key���ڣ���count����1����������ڣ���count����0��
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
            //auto & key : cnt  ������ϣ��
            //�õ���������Ԫ�صļ�ֵ it->first
            // �������key.first +1�ļ�ֵ���ڣ���¼��г���еĳ���
            //�õ���������Ԫ�صļ�ֵ��Ӧ��Ԫ��ֵ it->second
            //cnt[key.first]��Ч��key.second
        }
        return res;
    }
};