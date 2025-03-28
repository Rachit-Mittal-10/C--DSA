#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

class TimeMap {
/*
todo: Create a time based key value store
- set is always strictly increasing timestamp ==> this is the sign of binary search
*/
    unordered_map<string,vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }
        auto& vectorKey = mp[key];
        int start = 0;
        int end = vectorKey.size()-1;
        int mid = -1;
        string result = "";
        while(start <= end){
            mid = (end-start)/2 + start;
            if(vectorKey[mid].first > timestamp){
                end = mid - 1;
            }
            else{
                start = mid + 1;
                result = vectorKey[mid].second;
            }
        }
        return result;
    }
};

int main(void){
    auto tmp = TimeMap();
    tmp.set("foo","bar",1);
    cout << tmp.get("foo",1) << endl;
    cout << tmp.get("foo",3) << endl;
    tmp.set("foo","bar2",4);
    /*
    : "foo": [<1,"bar">,<4,"bar2">]
    */
    cout << tmp.get("foo",4) << endl;
    cout << tmp.get("foo",5) << endl;
}