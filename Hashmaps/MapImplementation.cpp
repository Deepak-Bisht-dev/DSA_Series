#include<iostream>
#include<map> // in map it prints the data in order of insertion of data
#include<unordered_map> // it prints in a random way
using namespace std;

int main(){

    map<string,int> m;

    // Insertion
    // 1
    pair<string, int> p = make_pair("sher", 3);
    m.insert(p);

    // 2
    pair<string, int> pair2("deep", 2);
    m.insert(pair2);

    // 3
    m["mera"] = 1;

    // search
    cout << m["mera"] << endl;
    cout << m.at("sher") << endl;

    cout << m["unknownKey"] << endl;

    // size
    cout << m.size() << endl;

    // to check count
    cout << m.count("sher") << endl;

    // erase
    // m.erase("deep");
    // cout << m.size() << endl;

    // traversing the map
    for(auto i : m){
        cout << i.first << " " << i.second << endl;
    }

    // iterator
    map<string, int> :: iterator it = m.begin();
    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}