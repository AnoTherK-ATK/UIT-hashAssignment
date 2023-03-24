#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

set<__int128_t> se;

string genKey(__int128_t n){
    string s = "";
    for(int i = 0; i < 50; ++i){
        if((1ll << (i)) & n){
            s = '1' + s;
        }else
            s = '0' + s;
    }
    n >>= 50;
    for(int i = 0; i < 50; ++i){
        if((1ll << (i)) & n){
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
        __int128_t seed = 0;
        do{
            seed =(__int128_t)(rnd.next(0ll, (1ll << 50) - 1));
            seed <<= 50;
            seed |= (__int128_t)(rnd.next(0ll, (1ll << 50) - 1));
        }while(se.find(seed) != se.end());
        se.insert(seed);
        cout << genKey(seed) << ' ' << genValue() << '\n';
    }
}
