class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> target_index;   // stores the final answer (two indices)

        unordered_map<int, int> hash_table; // key = element from nums, value = its index

        // loop through each element in nums
        for (int i = 0; i < nums.size(); i++) {
            int second_num = target - nums.at(i); // the "complement" we need

            // IF: check if complement is already in hash_table
            if (hash_table.find(second_num) != hash_table.end()) {
                // Found the complement → solution exists
                // push the index of the complement (value stored in hash map)
                target_index.push_back(hash_table.find(second_num)->second);
                // push the current index
                target_index.push_back(i);
                break; // stop, because we only need one valid pair
            }
            else {
                // ELSE: complement not found → store current number for future
                // key = number, value = index
                hash_table[nums.at(i)] = i;
            }
        }

        return target_index; // return the two indices that add up to target
    }
};