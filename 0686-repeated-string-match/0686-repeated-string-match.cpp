class Solution {
private:
int base = 1000000;
public:
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        int cnt=1;
        string source=a;
        while(source.size()<b.size()){
            cnt++;
            source+=a;
        }
        if(source==b) return cnt;
        if(rabin_karp(source,b)!=-1) return cnt;
        if(rabin_karp(source+a,b)!=-1) return cnt+1;
        return -1;
    }
    int rabin_karp(string source,string target){
        if(source==""||target=="") return -1;
        int m = target.size();
        int power=1;
        for(int i=0;i<m;i++)
        power=(power*31)%base;
        int targetcode=0;
        for(int i=0;i<m;i++)
        targetcode=(targetcode*31+target[i])%base;
        int hashcode=0;
        for(int i=0;i<source.size();i++){
        hashcode=(hashcode*31+source[i])%base;
        if(i<m-1) continue;
        if(i>=m) hashcode=(hashcode-source[i-m]*power)%base;
        if(hashcode<0) hashcode+=base;
        if(hashcode==targetcode){
            if(source.substr(i-m+1,m)==target) return i-m+1;
        }
        }
return -1;
            }
};