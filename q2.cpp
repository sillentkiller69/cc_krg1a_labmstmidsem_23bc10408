#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0);
#define ll long long

 
bool checkCommon(bitset<26>& a, bitset<26>& b) {
	for(int i = 0; i < 26; i++) if (a[i] && b[i]) return true;
	return false;
}

int maxProduct(vector<string>& words) {
	int n = size(words), ans = 0;
	vector<bitset<26> > chars(n);
	for(int i = 0; i < n; i++) {
		for(auto& ch : words[i])   
			chars[i][ch - 'a'] = 1;
		 	
		for(int j = 0; j < i; j++)
			if(!checkCommon(chars[i], chars[j])) 
				ans = max(ans, int(size(words[i]) * size(words[j])));
	}   
	return ans;
}
 


     

int main() {
    FAST_IO
    
        vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
        cout << maxProduct(words) << endl;

    return 0;
}