
//Time Complexity : O(n)
//Space Complexity : O(n);

class Solution {
public:
    int findTheWinner(int n, int k) {

        if(n==1){
            return 1;
        }

        vector<int> arr;

        // Initialize arr with values 1 to n
        for (int i = 1; i <= n; ++i) {
            arr.push_back(i);
        }

        int index = 0;
        k--; // Convert k to zero-indexed

        while (arr.size() > 1) {
            index = (index + k) % arr.size(); // Calculate the index to remove
            arr.erase(arr.begin() + index); // Erase the element at calculated index
        }

        return arr[0]; // Return the last remaining element
    }
};
