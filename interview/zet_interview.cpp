#include<bits/stdc++.h>
using namespace std;

/*
Longest Substring with At Least K Repeating Characters


Input: s = "aaabb", k = 3
Output: 3


Input: s = "ababbc", k = 2
Output: 5

"ababacb"
K = 3
Output = 0


g++ zet_interview.cpp
a.exe

clang++ zet_interview.cpp
./a.out
*/

int LongestSubstringwithAtLeastKRepeatingCharacters(string s, int k){
    int charCount[26] = {0};
    int n = s.size();
    for(int i=0; i<n; i++){
        charCount[s[i] - 'a']++;
    }
    
    set<char> eligibles;
    for(int i=0; i<26; i++){
        char c = (char) (i + 'a');
        
        if(charCount[i] >= k) {
            // cout<<c<<endl;
            eligibles.insert(c);
        }
    }

    int start = 0;
    int end = 0;
    int ans = 0;
    while(end < n){
        if(eligibles.find(s[end]) != eligibles.end()){
            end++;
        } else{
            map<char, int> tempCount;
            bool elig_str = true;
            for(int i=start; i<end; i++){
                tempCount[s[i]]++;
            }
            map<char, int> :: iterator it;
            for(it=tempCount.begin(); it!=tempCount.end(); it++){
                // cout<<it->second<<endl;
                if(it->second < k){
                    elig_str = false;
                }
            }
            if(elig_str){
                ans = max(ans, end - start);
            }

            end++;
            start = end;  
        }
    }

    map<char, int> tempCount;
    bool elig_str = true;
    for(int i=start; i<end; i++){
        tempCount[s[i]]++;
    }
    map<char, int> :: iterator it;
    for(it=tempCount.begin(); it!=tempCount.end(); it++){
        if(it->second < k){
            elig_str = false;
        }
    }
    if(elig_str){
        ans = max(ans, end - start);
    }

    return ans;


}

int main(){
    string s = "ababacb";
    int k = 3;
    cout<<LongestSubstringwithAtLeastKRepeatingCharacters(s, k);
}