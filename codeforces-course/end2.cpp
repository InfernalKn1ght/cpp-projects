#include <iostream>
using namespace std;
bool f(string str, string bad_str) {
    for (int i = 0; i < str.size(); i++) {
        string buf;
        for (int j = i; j < str.size(); j++) {
            buf.push_back(str[j]);
            if (buf == bad_str) return 0;
            if (buf.size() > 1) {
                if (f(buf, bad_str) == 1) return 1;
                else return 0;
            }
            else return 1;
        }
    }
}
int main() {
    string str, bad_str;
    cin >> str >> bad_str;
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        string buf;
        for (int j = i; j < str.size(); j++) {
            buf.push_back(str[j]);
            if ((buf != bad_str) && (f(buf, bad_str) == 1)) sum++;  
        }
    }
    cout << sum;
}