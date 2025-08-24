class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> target_index;

        unordered_map<int, int> hash_table;
        for(int i = 0; i < nums.size(); i++){
            int second_num = target - nums.at(i);

            if (hash_table.find(second_num) != hash_table.end()){
                target_index.push_back(i);
                target_index.push_back(hash_table.find(second_num)->second);
                break;
            }
            else {
                hash_table[nums.at(i)] = i;
            }
        }
        return target_index;
    }
};