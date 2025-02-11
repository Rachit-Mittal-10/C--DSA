#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

class TimeMap {
    unordered_map<string,vector<pair<string,int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(value,timestamp));
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }
        auto vectorKey = mp[key];
        int start = 0;
        int end = vectorKey.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(vectorKey[mid].second == timestamp){
                return vectorKey[mid].first;
            }
            else if(vectorKey[mid].second > timestamp){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        if(end>=0){
            return vectorKey[end].first;
        }
        return "";
    }
};
int main(void){
    auto tmp = TimeMap();
    cout << tmp.get("foo",1) << endl;
    tmp.set("foo","bar",1);
    cout << tmp.get("foo",3) << endl;
    tmp.set("foo","bar2",4);
    cout << tmp.get("foo",4) << endl;
    cout << tmp.get("foo",2) << endl;
}