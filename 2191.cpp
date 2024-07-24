// class Solution {
// public:
//     vector<int> sortByMapping(vector<int>& nums, vector<int>& mapping) {
//         int n = nums.size();
        
//         // Step 1: Convert nums to string representation
//         vector<string> temp(n);
//         for (int i = 0; i < n; i++) {
//             temp[i] = to_string(nums[i]);
//         }

//         // Step 2: Apply mapping to each digit in temp
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < temp[i].size(); j++) {
//                 int digit = temp[i][j] - '0'; // Convert char to int
//                 temp[i][j] = '0' + mapping[digit]; // Apply mapping
//             }
//         }

//         // Step 3: Create a vector of pairs (transformed_value, original_value)
//         vector<pair<string, int>> pr;
//         for (int i = 0; i < n; i++) {
//             pr.push_back({temp[i], nums[i]});
//         }

//         // Step 4: Sort pairs based on the transformed_value
//         sort(pr.begin(), pr.end());

//         // Step 5: Extract the sorted original values
//         vector<int> ans;
//         for (auto& it : pr) {
//             ans.push_back(it.second);
//         }

//         return ans; // Return the sorted nums
//     }
// };





class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto translate_integer = [&](int num) -> int {
            if (num == 0) {
                return mapping[0];
            }
            int res = 0;
            int cur_mult = 1;
            while (num > 0) {
                int digit = num % 10;
                num /= 10;
                res += mapping[digit] * cur_mult;
                cur_mult *= 10;
            }
            return res;
        };

        unordered_map<int, int> number_mapping;
        for (int num : nums) {
            if (number_mapping.find(num) == number_mapping.end()) {
                number_mapping[num] = translate_integer(num);
            }
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return number_mapping[a] < number_mapping[b];
        });

        return nums;
    }
};
