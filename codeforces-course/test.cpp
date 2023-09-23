#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector <vector<int>> ans2;
    vector <int> ans1;
    for (int k = 0; k < n; k++) {
        string str, sub_str;
        cin >> str >> sub_str;
        vector <int> v;
        int ans = 0;
        if (str.size() >= sub_str.size()) {
            for (int i = 0; i <= str.size() - sub_str.size(); i++) {
                bool f = 1;
                for (int j = 0; j < sub_str.size(); j++) {
                    if ((str[i+j] != sub_str[j]) && (sub_str[j] != '?')) {
                        f = 0;
                        break;
                    }
                }
                if (f) {
                    ans++;
                    v.push_back(i);
                }
            }
        }
        ans1.push_back(ans);
        ans2.push_back(v);
    }
    for (int i = 0; i < ans1.size(); i++) {
        cout << ans1[i] << endl;
        for (int j = 0; j < ans2[i].size(); j++) {
            cout << ans2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}