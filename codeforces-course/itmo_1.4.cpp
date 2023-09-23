#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> ans1;
    for (int q = 0; q < n; q++) {
        string str1, str2;
        cin >> str1 >> str2;
        vector <pair<int,int>> v;
        for (int i = 0; i < str1.size(); i++) {
            bool f = 1;
            for (int j = 0; j < str2.size(); j++) {
                if (str1[i + j] != str2[j]) {
                    f = 0;
                    break;
                }
            }
            if (f) v.push_back(make_pair(i, i + str2.size() - 1));
        }
        int i = 0, k = 0, ans = 0;
        while (k < str1.size()) {
            int a = i, b = i + k;
            if (i + str2.size() < str1.size()) {
                for (int j = 0; j < v.size(); j++) {
                    if ((i <= v[j].first) && (i + str2.size() - 1 >= v[i].second)) ans--;
                    else ans++;
                }
            }
            if (b == str1.size() - 1) {
                i = 0;
                k++;
            }
            i++;
        }
        cout << ans;
    }
    
    return 0;
}