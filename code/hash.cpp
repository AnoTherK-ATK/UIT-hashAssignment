#include <bits/stdc++.h>
using namespace std;

const int M = 1e7 + 7; //size of the hash table
const int MOD = INT_MAX;

struct Discretization{
    __int128_t table[M];
    int counter = 0;
    Discretization(){
        for(int i = 0; i < M; ++i)
            table[i] = 0;
    }

    __int128_t convert(const string& s){
        __int128_t number = 0;
        for(int i = (int)s.size() - 1; i >= 0; --i){
            if(s[i] == '1'){
                number ^= ((__int128_t)1 << (s.size() - i - 1));
            }
        }
        return number;
    }

    int discretizing(const string& s){
        __int128_t number = convert(s);
        table[++counter] = number; 
        return counter;
    }

};

Discretization dis;

struct Hash{
    string hashTable[M]; //hash table size M

    Hash(){
        for(int i = 0; i < M; ++i)
            hashTable[i] = "";
    }

    void insert(const string& key, const string& value){
        int intKey = dis.discretizing(key);
        hashTable[intKey] = value;
    }

    string getValue(const string& key){
        int intKey = dis.discretizing(key);
        return hashTable[intKey];
    }
} hashT;

int n, collision;
string binaryKey;
string value;

signed main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    freopen("../test\\input.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> binaryKey >> value;
        if(hashT.getValue(binaryKey) != "")
            ++collision;
        hashT.insert(binaryKey, value);
    }
    cout << collision;
}