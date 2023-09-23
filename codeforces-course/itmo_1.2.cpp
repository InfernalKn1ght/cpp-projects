#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    string s;
    cin >> s;
    string str1 = "", str2 = "";
    int ans = 0;
    for (int j = 0; j < s.size(); j++) {
        string buf = {s[s.size()-j-1]};
        str1.push_back(s[j]);
        str2 = buf + str2;
        if (str1 != str2) {
            for (int k = 0; k < s.size() - str1.size(); k++) {
                int mism = 2;
                for (int l = 0; l < str1.size(); l++) {
                    if (str1[l] != s[k + l]) {
                        mism -= 1;
                        break;
                    }
                }
                for (int l = 0; l < str2.size(); l++) {
                    if (str2[l] != s[k + l]) {
                        mism -= 1;
                        break;
                    }
                }
            }
        }
    }
    //for (int j = 1; j < s.size()) 
    cout << ans;
    return 0;
}