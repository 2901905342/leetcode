//Ϊ�˲���������б�¶�ּ�������־������������Ҫ����ĸ����ɵ����������˼��
//����һ�������(ransomNote) �ַ�����һ����־(magazine)�ַ������ж� ransomNote �ܲ����� magazines ������ַ����ɡ�
//������Թ��ɣ����� true �����򷵻� false ��
//magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�
//1 <= ransomNote.length, magazine.length <= 105
//ransomNote �� magazine ��СдӢ����ĸ���


/////���Ե�hash�������ַ���ֻ����Сд��ĸ��������������Ϊhash��

#include "myhead.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size()) return false;
        int hash[26] = { 0 };
        for (int i = 0; i < magazine.size(); i++) {
            hash[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            hash[ransomNote[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] < 0)  return false;
        }
        return true;
    }
};


