//Space Complexity : O(n2)
//Time Complexity : O(n2)




class Solution {
public:
    int WIDTH;
    int t [1001][1001];

    int solve(vector<vector<int>>& books, int i, int rW, int maxHt){
        if(i>=books.size()){
            return maxHt;
        }
        if(t[i][rW] != -1){
            return t[i][rW];
        }

        int curr_h = books[i][1];
        int curr_w = books[i][0];
        int keep = INT_MAX;
        int skip  = INT_MAX;
        int max_h = INT_MIN;


        if(curr_w<=rW){
            //either we can keep or we can skip

            //keep 
        
            keep = solve(books,i+1, rW-curr_w, max(maxHt, curr_h));
           


            //skip
            skip = maxHt+solve(books, i+1, WIDTH-curr_w, curr_h);
        }
        else{
            //we have to skip
            skip = maxHt+solve(books, i+1, WIDTH-curr_w, curr_h);
        }

        return t[i][rW] = min(keep, skip);

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset (t, -1, sizeof(t));
        int i = 0;
        WIDTH = shelfWidth;
        int ans = solve(books, 0, WIDTH, 0);

        return ans;
        
    }
};
