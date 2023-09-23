#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> v;
    for (int q = 0; q < n; q++) {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            string str = "";
            for (int k = i; k < s.size(); k++) {
                str.push_back(s[k]);
                int f = 0;
                for (int j = 0; j < str.size(); j++) {
                    if (s[j] != str[j]) {
                        f++;
                        break;
                    }
                }
                for (int j = 0; j < str.size(); j++) {
                    if (s[s.size() - str.size() + j] != str[j]) {
                        f++;
                        break;
                    }
                }
                if (f == 1) ans++;
            }
        }
        v.push_back(ans);
    }
    for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
    return 0;
}