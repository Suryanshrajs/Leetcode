//Time Complexity : O(n)
//Space Complexity : O(1)

// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {


//         int n = nums.size();
// //fatne wale testcase ko solve karne k liye nyi arr banayege





        
//         //int n = nums.size();
//         //cout<<n<<" "; 
//         if(nums.size()<=3){
//             return 0;
//         }

//         int oneCount = 0;
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i] == 1){
//                  oneCount++;
//             }
           
//         }
//         cout<<oneCount<<endl;

        
// for(int i=0; i<n ; i++){
//     nums.push_back(nums[i]);
// }


//         //ab hume ek window banayege jisme number of zero count karege 
//         int zeroCount = 0;
//         int minn = INT_MAX;

//         for(int j=0; j<oneCount; j++){
//             if(nums[j] == 0){
//                 zeroCount++;
//             }
//         }

//         cout<<zeroCount<<endl;

//         minn = min(minn, zeroCount);
//         cout<<minn<<endl;

//         //ab next me travrse kare  
//         int left = 0;
//         int right = oneCount;

//         while(right<nums.size()){
//             if(nums[left] == 1 && nums[right] == 0){
//                 zeroCount++;
//             }
//             else if(nums[left] == 0 && nums[right] == 1){
//                 zeroCount--;
//             }

//             left++;
//             right++;
//          minn = min(minn, zeroCount);
//          cout<<minn<<endl;

//         }
//     return minn;
        
//     }
// };






//Time Complexity : O(n)
//Space Complexity : O(1)

// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {


//         int n = nums.size();
        
//         //total one;
//         // int countOne = 0;
//         // for(int i=0; i<n; i++){
//         //     if(nums[i]==1){
//         //         countOne++;
//         //     }
//         // }

//         //we can count 1 also using given method
//         int oneCount = accumulate(begin(nums), end(nums), 0);   //wondow size

       
//         for(int i=0; i<n; i++ ){
//             nums.push_back(nums[i]);
//         }



//         int i =0;
//         int j =0;

//         int currOnes = 0;
//         int maxOnes = 0;

//         while(j<nums.size()){
//            if(nums[j]==1) {
//             currOnes++;
//            }


//            if(j-i+1 > oneCount){
//                 currOnes-=nums[i];
//                 i++;
//            }

//            maxOnes = max(maxOnes, currOnes);
//            j++;
//         }

//     return oneCount - maxOnes;
        
//     }
// };





//Time Complexity : O(n)
//Space Complexity : O(1)

class Solution {
public:
    int minSwaps(vector<int>& nums) {


        int n = nums.size();
        
        //total one;
        // int countOne = 0;
        // for(int i=0; i<n; i++){
        //     if(nums[i]==1){
        //         countOne++;
        //     }
        // }

        //we can count 1 also using given method
        int oneCount = accumulate(begin(nums), end(nums), 0);   //wondow size

       
        // for(int i=0; i<n; i++ ){
        //     nums.push_back(nums[i]);
        // }



        int i =0;
        int j =0;

        int currOnes = 0;
        int maxOnes = 0;

        while(j<2*n){
           if(nums[j%n]==1) {
            currOnes++;
           }


           if(j-i+1 > oneCount){
                currOnes-=nums[i%n];
                i++;
           }

           maxOnes = max(maxOnes, currOnes);
           j++;
        }

    return oneCount - maxOnes;
        
    }
};
