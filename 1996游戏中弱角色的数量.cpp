//�����ڲμ�һ�����ɫ��Ϸ��ÿ����ɫ����������Ҫ���ԣ����� �� ���� ��
//����һ����ά�������� properties ������ properties[i] = [attacki, defensei] ��ʾ��Ϸ�е� i ����ɫ�����ԡ�
//�������һ��������ɫ�Ĺ����ͷ����ȼ� ���ϸ���� �ý�ɫ�Ĺ����ͷ����ȼ�������Ϊ�ý�ɫΪ ����ɫ ��
//����ʽ�أ������Ϊ��ɫ i ���� ���ڵ���һ����ɫ j ����ô attackj > attacki �� defensej > defensei ��
//���� ����ɫ ��������

//////////˼·������+�Ƚ�
//�ڰ��չ��������ҹ�����ͬʱ�����������к󣬼�¼��������
//���赱ǰ�ķ�����֮ǰ��������С������ȷ�ϵ�ǰ��������ɫ��
//�����ǣ�����ͬ�Ĺ����ڣ����������򣬳��ֵķ������ڵ�ǰ���϶��������ڹ����������Щ��
#include "myhead.h"

class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b) {
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] > b[0];
    }// ����֣�������þ�̬����������ᱨ��
    /*���������ָ�����ã����ã��˷Ǿ�̬���������㲻��ͨ������������õġ��������Դ����sort���������ĵ�����ν�ʲ�����Ϊʲô�����������أ�
    ���ճ�����˵��ͬһ����ķǾ�̬const��Ա���������໥���ã�������ͨ���������з��ʣ�Ϊʲô���ﲻ���أ��෴������ǰ�ν�ʺ���com��������Ϊstatic���������û���ˡ�
    �����ԭ����ʵ���Ǻ���������ƥ������⡣��Ϊ������ͨ�ĳ�Ա��������һ��������thisָ�룬�����Ͽ����ǵ�ν�ʺ���com����ֻ��������������ʵ�����������������������ǵ���sort������������ʱ��ֻ��Ҫ�õ������������бȽϣ����Ծͳ������β���ʵ�β�ƥ�������������������βΣ�����ֻ����������ʵ�Σ�
     ���ԣ�����취���ǰ�ν�ʺ���com��������Ϊstatic��Ա������*/
       
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

/////////�ٷ�д��������֣����sort()��������ʹ�ùٷ�����lamda��������д��
//////  ��һ���ᳬʱ��̫����ˡ��������̶���һ����

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