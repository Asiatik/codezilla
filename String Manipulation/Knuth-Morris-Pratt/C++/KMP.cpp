#include <iostream>
#include <vector>

using namespace std;

// Computes the prefix-suffix array.
vector<int> ComputePrefixFunction(string pattern){
    int m = pattern.length();
    vector<int> prefixArr(m);
    prefixArr[0] = 0;
    int k = 0;

    for(int i=1; i<m; ++i){
        while(k > 0 && pattern[k] != pattern[i]){
            k = prefixArr[k];
        }
        if(pattern[k] == pattern[i]){
            k++;
        }
        prefixArr[i] = k;
    }
    
    return prefixArr;
}

// Returns a vector of indicies where there is a pattern match.
vector<int> KMP(string text, string pattern){
    int n = text.length();
    int m = pattern.length();
    vector<int> prefixArr = ComputePrefixFunction(pattern);
    int q = 0;

    vector<int> results;

    for (int i = 0; i < n; ++i){
        while(q > 0 && pattern[q] != text[i]){
            q = prefixArr[q];
        }
        if(pattern[q] == text[i]){
            q++;
        }
        if(q == m){
            results.push_back(i-m);
            q = prefixArr[q];
        }
    }
    
    return results;
}

int main(){
    string example1 = "bacbababaabacabababaabaca";
    string pattern1 = "abaabaca";

    vector<int> result = KMP(example1, pattern1);
    vector<int>::iterator itt;
    cout << "Matches at the following indicies..." << endl;
    for(itt = result.begin(); itt != result.end(); ++itt){
        cout << *itt << endl;
    }
    return 0;
}