#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int CountPattern(string text,string pattern){
    int count = 0;

    for (int i = 0; i < text.length() - pattern.length();i++){
        if (text.substr(i, pattern.length() + 1) == pattern){
            count++;
        }

    }

    return count;
}

vector<string> FindPattern(const string& text,int k ){
    vector<string> patterns;
    vector<int> count_pattern(text.length() - k + 1, 0); 
    for (int i = 0; i < text.length() - k; i++){
        string pattern = text.substr(i, k);
       count_pattern[i] = CountPattern(text, pattern);   
    }

    auto MaxCount = *max_element(count_pattern.begin(), count_pattern.end());

    for (int i = 0; i < text.length() - k; i++){
        if (count_pattern[i] == MaxCount){
            string pattern = text.substr(i,k);
            if (find(patterns.begin(), patterns.end(), pattern) == patterns.end()) {
                patterns.push_back(pattern);
            }
        }
    }
    return patterns;
}



int main(){
    string test1 = "ACGTTGCATGTCGCATGATGCATGAGAGCT";
    int k1 = 4;

    vector<string> result1 = FindPattern(test1, k1);
    for(const string& s : result1) cout << s << " "; 
    cout << "\n" << endl;





}