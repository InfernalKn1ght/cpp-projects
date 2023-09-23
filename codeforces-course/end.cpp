#include <iostream>
using namespace std;
void f(string str) {
    for (int i = 0; i < str.size(); i++) {
        
    }
}
int main() {
    string str, bad_str;
    cin >> str >> bad_str;
    int sum = ((1 + str.size()) * str.size()) / 2, c = 0,c1 = 0;
    cout << sum << endl;
    for (int i = 0; i < str.size(); i++) {
        string buf;
        for (int j = i; j < str.size(); j++) {
            buf.push_back(str[j]);
            if (buf == bad_str) {
                sum -= (i + 1 - c) * (str.size() - j);
                sum += c1 * (str.size() - j);
                cout << "n: " << str.size() - j << " " << (i + 1 - c) * (str.size() - j) << " "  << c1 << endl;
                c++;
                if (i > 0) c1++;
                break;
            }
        }
    }
    cout << sum;
}