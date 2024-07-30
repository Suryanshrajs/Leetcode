// // //Approach 1
// // //Time Complexity : O(n2)
// // //Space Complexity : O(1)
// // //Time Limit Exceed

// // class Solution {
// // public:
// //     int minimumDeletions(string s) {
// //         int del = INT_MAX;
// //         int n = s.size();

// //         // is question se hume ye pata lgta hai ki b k right k m a nhi ana chahiye , isi tarh a left m b nhi ana chahiye
// //         //now hume har char m jayege  aur uske left k sare b delete kar dege aur right ke sare a delete kar dege

       

// //         for(int i=0; i<n; i++){
// //             int a_count = 0;
// //             int b_count = 0;
// //             for(int j=0; j<i; j++){
// //                 if(s[j]=='b'){
// //                     b_count++;
// //                 }
// //             }
// //             for(int j=i+1; j<n; j++){
// //                 if(s[j]=='a'){
// //                     a_count++;
// //                 }
// //             }
// //             del = min(del,(a_count+b_count));

// //         }

// //         return del;
        
// //     }
// // };




// // //Approach 2
// // //Upar ki approach se hume TLE mil rha tha ab hum new approach s solve krte hai

// // class Solution {
// // public:
// //     int minimumDeletions(string s) {
        
// //         int n = s.size();

// //         // is question se hume ye pata lgta hai ki b k right k m a nhi ana chahiye , isi tarh a left m b nhi ana chahiye
// //         //now hume har char m jayege  aur uske left k sare b delete kar dege aur right ke sare a delete kar dege
// //         //hum ek vector m har index k left k b aur right k a ko store kar lege


// //         // yha hum 2 vector create krke ek vectorm har indec k left k b store karge aur ek vector m har index k right ka a store karege
// //         vector<int> a(n,0);
// //         vector<int> b(n,0);

// //     //starting m dono ka count 0 set kar dege
// //         int count_a = 0;
// //         int count_b = 0;

// // //yha vector me appropriate value fill kar dege m appropriate 
// //         for(int i=0; i<n; i++){
// //             if(i>0 && s[i]=='b'){
// //                 count_b++;
// //             }
// //             b[i] = count_b;
// //         }
// //         for(int i=n-1; i>=0; i--){
// //             if(i<n-1 && s[i]=='a'){
// //                 count_a++;
// //             }
// //             a[i] = count_a;
// //         }

// //         // yha hum traverse kake sari value calculate kar lege

// //         int no_of_deletion = INT_MAX;

// //         for(int i=0; i<n; i++){
// //             int ans = a[i]+b[i];

// //             no_of_deletion = min(no_of_deletion, ans);
// //         }
// // return no_of_deletion;
        
// //     }
// // };

// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int n = s.size();
        
//         // Vectors to store the counts of 'a' to the right and 'b' to the left for each index
//         vector<int> a(n, 0);
//         vector<int> b(n, 0);

//         int count_a = 0; // Count of 'a's to the right
//         int count_b = 0; // Count of 'b's to the left

//         // Fill the b vector with counts of 'b's to the left for each index
//         for(int i = 0; i < n; i++){
//             if(s[i] == 'b'){
//                 count_b++;
//             }
//             b[i] = count_b;
//         }

//         // Fill the a vector with counts of 'a's to the right for each index
//         for(int i = n - 1; i >= 0; i--){
//             if(s[i] == 'a'){
//                 count_a++;
//             }
//             a[i] = count_a;
//         }

//         // Calculate the minimum number of deletions needed
//         int no_of_deletion = INT_MAX;
//         for(int i = 0; i < n; i++){
//             int ans = a[i] + b[i];
//             no_of_deletion = min(no_of_deletion, ans);
//         }

//         return no_of_deletion-1;
//     }
// };



class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        int b = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'b') {
                f[i] = f[i - 1];
                ++b;
            } else {
                f[i] = min(f[i - 1] + 1, b);
            }
        }
        return f[n];
    }
};
