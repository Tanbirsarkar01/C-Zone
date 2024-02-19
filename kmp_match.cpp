#include<bits/stdc++.h>
using namespace std;
void lpsfind(vector<int> &lps,string s){
        int pre=0;
        int suf=1;

        while(suf < s.size()){
            if(s[pre] == s[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre == 0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
    }
    bool KMP_MATCH(string s,string t){
        vector<int> lps(t.size(),0);
        lpsfind(lps,t);

        int i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    j=lps[j-1];
                }
            }
        }
        return j==t.size();
    }