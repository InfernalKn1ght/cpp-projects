#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string str1 ="",str2 = "";
        int ans = 0;
        for (int j = 0; j < s.size(); j++) {
            str1.push_back(s[j]);
            string buf = {s[j]};
            str2 = buf + str2;
            int size = str1.size();
            if (str1 == str2) ans = max(ans, size);
        }
        v.push_back(ans);
    }
    for (int i =0; i < v.size(); i++) cout << v[i] <<endl;
    return 0;
}