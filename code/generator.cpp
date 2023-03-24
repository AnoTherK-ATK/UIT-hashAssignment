#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

set<__int128_t> se;

string genKey(__int128_t n){
    string s;
    for(int i = 0; i < 100; ++i){
        if((1 << i) & n){
            s = '1' + s;
        }else
            s = '0' + s;
    }
    return s;
}

string genValue(){
    string ans = "";
    for(int i = 0; i < 50; ++i){
        ans += (char)(rnd.next(65, 122));
    }
    return ans;
}


int main(int argc, char *argv[]){
    registerGen(argc, argv, 1);
    ios::sync_with_stdio(0); cin.tie(nullptr);
    freopen("../test\\input.txt", "w", stdout);
    int n = atoi(argv[1]);
    cout << n << '\n';
    while(n--){
        __int128_t seed;
        do{
            seed = rnd.next(0ll, LLONG_MAX - 1) * rnd.next(0ll, LLONG_MAX - 1);
        }while(se.find(seed) != se.end());
        cout << genKey(seed) << ' ' << genValue() << '\n';
    }
}