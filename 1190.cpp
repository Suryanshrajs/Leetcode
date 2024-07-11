//Time Complexity : O(n)
//Space Complexity : O(n)


class Solution {
public:
    string reverseParentheses(string &s){
        //sabse pahle hum ek stack banayege jo ye store karega ki kis kis sthan pe opening parenthesis hai
        stack<int> st;

        //ab stack me vo sare index fill karne hoge
        for(int i =0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            if(s[i] == ')' && !st.empty()){
                int last = i;
                int first = st.top();
                st.pop();

                // ab hume ye pata chal gaya hai ki hume string ko first and last index ke beeck hi reverse karna hai
                reverse(s.begin() + first, s.begin() +last);

            }
        }

        int j=0;
        while(j<s.size()){
            if(s[j]=='(' || s[j]==')'){
                s.erase(s.begin()+j);
            }
            else{
                j++;
            }
        }

        return s;
    }
};