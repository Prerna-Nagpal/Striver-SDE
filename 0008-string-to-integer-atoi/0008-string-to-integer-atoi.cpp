class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size();
        long ans=0;
        int sign = 1;
        while(i<n && s[i]==' ') i++;
        if(i==n) return 0;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+') i++;
        while(i<n && isdigit(s[i])){
            ans=ans*10+(s[i]-'0');
            if(sign==1 && ans>INT_MAX) return INT_MAX;
            if(sign==-1 && -ans<INT_MIN) return INT_MIN;
            i++;

        }
        return (int)sign*ans;
        
    }
};