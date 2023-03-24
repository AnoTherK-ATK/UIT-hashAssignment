#include <bits/stdc++.h>
using namespace std;

const int M = 1e7 + 7; //size of the hash table
const int MOD = INT_MAX;

struct Hash{
    string hashTable[M]; //hash table size M

    Hash(){
        for(int i = 0; i < M; ++i)
            hashTable[i] = "";
    }

    inline int getPow2(int pos, int N){
        return N - pos + 1;
    }

    long long hashFunc(const string& binaryString){
        int numKey[4] = {};
        long long cnt = 0;
        long long len = (long long)binaryString.size(); //lenght of key
        for(int i = len - 1; i >= 0; --i){
            if(binaryString[i] == '1'){//if the bit in position i is on
                numKey[(getPow2(i, len) / 25)] ^= (1 << (getPow2(i, len) % 25));
            }
        }
        long long hashNum = numKey[0];
        for(int i = 1; i < 4; ++i){
            hashNum = ((1ll * hashNum * 1ll * numKey[i])) % MOD;
        }
        return hashNum % M;
    }

    void insert(const string& key, const string& value){
        long long index = hashFunc(key);
        hashTable[index] = value;
    }

    string getValue(const string& key){
        long long index = hashFunc(key);
        return hashTable[index];
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