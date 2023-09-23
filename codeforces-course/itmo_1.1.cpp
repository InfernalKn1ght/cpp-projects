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
        string str1 = "", str2 = "";
        int c = 0, j1 = 0, j2 = s.size() - 1;
        while (j1 < j2) {
            str1.push_back(s[j1]);
            str2.push_back(s[j2]);
            if (str1 == str2) {
                j1++;
            }
            else {
                str1 = "";
                str2 = "";
                j1 = 0;
            }
            j2--;
        }
        c = str1.size() + str2.size();
        if (j1 - j2 == 0) c++;
        v.push_back(c);
    }
    for (int i =0; i < v.size(); i++) cout << v[i] <<endl;
    return 0;
}