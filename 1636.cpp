
class Solution {
public:
    vector<int> frequencySort(std::vector<int>& nums) {
        std::unordered_map<int, int> hmap;

        for (int num : nums) {
            hmap[num]++;
        }

        // Sort the nums vector with a custom comparator
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (hmap[a] == hmap[b]) {
                return a > b; // If frequencies are equal, sort by value in descending order
            }
            return hmap[a] < hmap[b]; // Otherwise, sort by frequency in ascending order
        });

        return nums;
    }
};
