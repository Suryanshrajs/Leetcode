//Commented solution is wrong

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int i =0;
//         int n = nums.size();
//         int count = 0;
//         while(i<n-1){
//             int maxx = 0;;
//             int maxi = 0;
        
//                 for(int j=i+1; j<=i+nums[i] && j<n; ++j){
//                    if(j+nums[j]>maxx){
//                      maxx = j+nums[j];
//                      maxi = j;
//                    }
//                 }
//                 i=maxi;
//                 count++;
//             }
        
//      return count;   
//     }
// };



//Time Complexity : O(n)
//Space Comlexity : O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int count = 0;
        int i = 0;

        while (i < n - 1) {
            if (i + nums[i] >= n - 1) {
                count++;
                break;
            }

            int max_reach = 0;
            int next_pos = i;
            for (int j = i + 1; j <= i + nums[i] && j < n; ++j) {
                if (j + nums[j] > max_reach) {
                    max_reach = j + nums[j];
                    next_pos = j;
                }
            }

            i = next_pos;
            count++;
        }

        return count;
    }
};
