class Solution {


    int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using Radix Sort
void radixSort(vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int maxVal = getMax(arr);

    // Do counting sort for every digit. Note that instead of passing digit number,
    // exp is passed. exp is 10^i where i is the current digit number
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(arr, exp);
}

public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;

        for(int i=0; i<n; i++){
           long long int sum = 0;
            for(int j=i; j<n; j++){
                sum+=nums[j];
                ans.push_back(sum);

            }
        }


        //yha tak meri second array create ho gyi hai

       long long int finalAns = 0;
       radixSort(ans);
        // sort(ans.begin(), ans.end());

        

        for(int i=left-1; i<right ; i++){
            finalAns += ans[i];
        }

        return finalAns%1000000007;
        
    }
};
