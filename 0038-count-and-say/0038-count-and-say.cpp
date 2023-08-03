class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
            string temp = countAndSay(n-1);
         
        int cnt = 1;
            string ans;
            int i = 1;
            for( ; i < temp.size() ; i++){
                    if(temp[i-1] != temp[i]){
                            ans += (to_string(cnt) + temp[i-1]);
                            cnt = 1;
                    }else {
                            cnt++;
                    }
            }
            ans += (to_string(cnt) + temp[i-1]);
            
            return ans;
    }
};