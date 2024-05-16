#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::cout, std::cin, std::endl, std::vector, std::string, std::ifstream, std::ofstream;

template<class T>
int count(T &array) {
    int cnt = 0;
    for(auto it = array.begin(); it != array.end(); it++) cnt++;
    return cnt;
}

template<>
int count(ifstream &in) {
    int cnt = 0;
    string tmp;
    while(getline(in, tmp)) {
        cnt += tmp.size();
    }
    return cnt;
}

int main() {
    vector<int> myVec{0, 0, 0, 0};
    string myStr("hello");
    ifstream in("words.txt");
    cout << count(myVec) << endl;
    cout << count<string>(myStr) << endl;
    cout << count(in) << endl;
    return 0;
}
