#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <vector<int>> ans2;
    vector <int> ans1;
    for (int q = 0; q < n; q++) {
        string s1, s2;
        cin >> s1 >> s2;
        vector <int> v;
        int ans = 0;
        char * arr = new char[s2.size()];
        for (int i = 0; i < s1.size(); i++) {
            if (i < s2.size()) arr[i] = s2[i];
            if (i >= s2.size() - 1) {
                
            }
        }
        ans2.push_back(v);
        ans1.push_back(ans);
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