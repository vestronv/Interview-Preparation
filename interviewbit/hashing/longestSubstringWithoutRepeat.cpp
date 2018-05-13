int Solution::lengthOfLongestSubstring(string str) {
    int len = str.length();
    if(len == 0)return 0;
    if(len==1)return 1;
    int ans = 1;
    int start = 0;
    int end = 1;
    map<char, int>mp;
    mp[str[0]]=1;
    while(end < len){
        mp[str[end]]++;
        while(start < end && mp[str[end]] > 1){
            mp[str[start]]--;
            start++;
        }
        if(end == len-1){
            ans = max(ans, end-start+ 1);
        }
        if(start ==end){
            end++;
        }
        else{
            ans = max(ans, end-start+ 1);
            end++;
        }
        
    }
    return ans;
}

