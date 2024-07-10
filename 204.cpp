// Time Complexity : O(n)
// Space Comlexity : O(1)

// this solution is giving Time LImit Exceed, so now i have to solve this question in less time

// class Solution {
// public:
//     int countPrimes(int n) {

//         if(n==0 || n==1){
//             return 0;
//         }
//         int count  =0;

//         for(int i=2; i<n; i++){
//             bool flag = true;
//             for(int j=2; j<(i/2)+1; j++){
//                 if(i%j == 0){
//                     flag = false;
//                     break;
//                 }
//             }
//             if(flag == true){
//                 cout<<i<<" ";
//                 count++;
//             }
//         }

//         return count ;
//     }
// };

//Time Complexity : O(n2)
//Space Complexity : O(n)



class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        vector<bool> prime(n, true);
        int count = 0;

        // Sieve of Eratosthenes
        for (int p = 2; p * p < n; ++p) {
            if (prime[p]) {
                // Marking all multiples of p as false
                for (int i = p * p; i < n; i += p) {
                    prime[i] = false;
                }
            }
        }

        // Counting prime numbers
        for (int p = 2; p < n; ++p) {
            if (prime[p]) {
                count++;
            }
        }

        return count;
    }
};
