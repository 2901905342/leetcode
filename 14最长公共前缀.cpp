//��дһ�������������ַ��������е������ǰ׺��
//��������ڹ���ǰ׺�����ؿ��ַ��� ""��

//1 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] ����СдӢ����ĸ���

////////////˼·��һ���ɷ�Ϊ���֣����������������������Σ����������⣩
///��������ͷ��εĴ��붼�Ƚϸ��ӣ���Ч�����������һ�£�����ֻ�ռ����������д��
/////����������ȱȽ�ÿһ��

//// �ٷ�д����Ϊ����ܱȱ���д����ʱ�临�Ӷ�������һ��O��m)
#include "myhead.h"
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m = strs.size();
        int m_len = strs[0].size();
        int indexm = 0;
        for (int i = 0; i < m; i++) {
            if (m_len > strs[i].size()) {
                m_len = strs[i].size();
                indexm = i;        //�˴��ǻ�ȡ����ַ����ĳ����Լ����ַ�����vector�е�λ��
                                   //��һ����֤��������ʱ�������������������
            }
        }
        for (int j = 0; j < m_len; j++) {
            char temp = strs[0][j];
            for (int i = 0; i < m; i++) {
                if (strs[i][j] != temp) return strs[indexm].substr(0, j);  
            }   //�����ǰ׺һ�����ᳬ������ַ������������ǰ׺������ַ������Ӵ�
        }
        return strs[indexm];
    }
};