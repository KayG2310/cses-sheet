#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s;
    cin >> s;
    map<char, int> mpp;
    for(char ch : s) mpp[ch]++;

    int odd_count = 0;
    char odd_char;
    for(auto it : mpp){
        if(it.second % 2){
            odd_count++;
            odd_char = it.first;
        }
    }

    if(odd_count > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string first_half = "", second_half = "";

    for(auto& it : mpp){
        string part(it.second / 2, it.first);  // half the occurrences
        first_half += part;
        second_half = part + second_half;      // mirror for palindrome
    }

    if(odd_count == 1){
        string mid(1, odd_char);
        cout << first_half + mid + second_half << endl;
    }
    else{
        cout << first_half + second_half << endl;
    }

    return 0;
}
