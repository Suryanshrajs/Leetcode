//Time Complexity : O(n)
//Space Comlexity : O(1)




class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) {
        double totalTime = 0;
        double waitingTime = 0;
        int n= nums.size();


        for(int i=0; i<nums.size(); i++){

            if(nums[i][0]>totalTime){
                totalTime = nums[i][0]+nums[i][1];
                waitingTime += totalTime-nums[i][0]; 
            }
            else{
                 totalTime += nums[i][1];
                waitingTime += totalTime-nums[i][0]; 
            }
               
            
        }

        return waitingTime/n;

    }
};