#include <bits/stdc++.h>
using namespace std;

const int M = 1e7 + 7; //size of the hash table
const int MOD = INT_MAX;

struct Hash{
    string hashTable[M]; //hash table size M
    __int128_t discretization[M];
    int counter = 0;
    Hash(){
        for(int i = 0; i < M; ++i){
            hashTable[i] = "";
            discretization[i] = 0;
        }
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

    bool isExisted(const string& key){
        __int128_t intKey = convert(key);
        return binary_search(discretization + 1, discretization + 1 + counter, intKey);
    }

    int search(const string& key){
        __int128_t intKey = convert(key);
        int index = lower_bound(discretization + 1, discretization + 1 + counter, intKey) - discretization;
        if(discretization[index] == intKey)
            return index;
        else
            return -1;
    }

    int discretizing(const string& s){
        __int128_t number = convert(s);
        discretization[++counter] = number; 
        return counter;
    }

    void insert(const string& key, const string& value){
        int intKey = discretizing(key);
        hashTable[intKey] = value;
    }

    string getValue(const string& key){
        int index = search(key);
        if(index != -1)
            return hashTable[index];
        else
            return "";
    }
} hashT;

bool cmp(pair<string, string> x, pair<string, string> y){
    return x.first < y.first;
}

int n, collision;
string binaryKey;
string value;
vector<pair<string, string> > v;

signed main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    freopen("../test\\input.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> binaryKey >> value;
        v.push_back(make_pair(binaryKey, value));
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i : v){
        if(hashT.isExisted(i.first))
            ++collision;
        hashT.insert(i.first, i.second);
    }
    cout << collision;
}