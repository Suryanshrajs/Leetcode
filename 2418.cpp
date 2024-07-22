class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        int n = heights.size();


        for(int i=0; i<n ;i++){
            int maxx = i;
            for(int j=i+1; j<n; j++){
                if(heights[j]>heights[maxx]){
                    maxx = j;
                }
            }
            swap(heights[i], heights[maxx]);
            swap(names[i], names[maxx]);
        }


        return names;
    }
};
