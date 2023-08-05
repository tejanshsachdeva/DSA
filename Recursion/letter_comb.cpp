class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
        
        //base case
        if(index >= digit.length()) {   //if we have traversed compplete digit, store the ans
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0';  //string no to int number
        string value = mapping[number];  //find the mapped string for that number
        
        for(int i=0; i<value.length(); i++) {  //itetrate over that string and get a char from that string
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            output.pop_back();  //take-not take
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};