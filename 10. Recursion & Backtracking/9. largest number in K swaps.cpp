// https://www.youtube.com/watch?v=5crucASFoA4

// need to memoize it and fake further optimiztions

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void helper(string str, int k, string& maxString){
        
        if(str > maxString){
            maxString = str;
        }
        
        if(k == 0){
            return;
        }
        
        for(int i = 0; i < str.length() - 1; i++){
            for(int j = i+1; j < str.length(); j++){
                if(str[i] < str[j]){
                    swap(str[i], str[j]);
                    helper(str,k-1,maxString);
                    swap(str[j], str[i]);
                }
            }
        }
        
    }
    
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       string maxString = str;
       helper(str,k,maxString);
       return maxString;
        
    }
};