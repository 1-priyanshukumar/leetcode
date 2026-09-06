class Solution {
public:
    bool isPalindrome(int x) {
        int b=x;
        long long n=0;
        while(x>0){
            int l=x%10;
            x=x/10;
            n=(n*10)+l;
        }
        
        
        if(n==b){
            return true;
        }
        else{
            return false;
        }
    }
};