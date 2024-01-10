#include <bits/stdc++.h>
using namespace std;

//lps : longest prefix which is also suffix
void computeLPS(string pat, vector<int>&lps){
    int n = pat.size();
    int j = 0;
    int i = 1;
    while(i<n){
        if(pat[i]==pat[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else i++;
        }
    }
    return;
}

vector<int> kmp(string pat, string txt){
         vector<int>v;
            int n = pat.size();
            int m = txt.size();
            vector<int>lps(n,0);
            if(!n || !m)return v;
            computeLPS(pat,lps);
            int i = 0;
            int j = 0;
            while(i<m){
                if(pat[j]==txt[i]){
                    i++;
                    j++;
                    if(j==n){
                        v.push_back(i-j+1);
                        j = lps[j-1];
                    }
                }
                
                else if(i<m && pat[j]!= txt[i]){
                    if(j!=0)    
                        j = lps[j-1];
                    else i++;
                }
            }
            return v;
}

int main(){
    string txt;
    cin>>txt;
    string pat;
    cin>>pat;
    
    vector<int>index = kmp(pat,txt);
    for(int i = 0; i<index.size();i++){
        cout<<"Pattern found at index: "<<index[i]<<" ";
    }
}