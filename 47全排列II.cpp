//����һ���ɰ����ظ����ֵ����� nums ��������˳�� �������в��ظ���ȫ���С�


//˼·��DFS
//Ҫ����ظ����⣬����ֻҪ�趨һ�����򣬱�֤����� idx ������ʱ���ظ�����ֻ�ᱻ����һ�μ��ɡ�
//���ڱ�����У�����ѡ���ԭ�������򣬱�֤��ͬ�����ֶ����ڣ�Ȼ��ÿ���������һ��������������ظ��������С��������ҵ�һ��δ����������֡�
//����ж�������֤�˶����ظ����ļ��ϣ�һ���Ǵ��������������ġ�
//���������� 33 ���ظ�������������ڣ���ô����һ����֤ÿ�ζ����ô������ҵ�һ��δ����������֣�
//�����������״̬��ʵ�Ǳ�֤��[δ���룬δ���룬δ����] ��[���룬δ���룬δ����]���ٵ�[���룬���룬δ����]�����[���룬���룬����] �Ĺ��̵ģ�
//��˿��Դﵽȥ�ص�Ŀ�ꡣ



#include "myhead.h"
class Solution {
public:
    void dfs(vector<int>& path, vector<vector<int>>& res, vector<int>& nums, vector<int> hash_table) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (hash_table[i])  continue; //����������ظ�
            if (i > 0 && (nums[i] == nums[i - 1]) && !hash_table[i - 1]) continue; //�����ظ������ظ�������
            path.push_back(nums[i]);
            hash_table[i] = 1;
            dfs(path, res, nums, hash_table);
            path.pop_back();
            hash_table[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        vector<int> hash_table(nums.size());  //����Ѿ�ʹ�ù���Ԫ�ص��±�
        sort(nums.begin(), nums.end());   //��ԭ��������
        dfs(path, res, nums, hash_table);
        return res;
    }
};