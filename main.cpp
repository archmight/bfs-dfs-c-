#include<iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>


using namespace std;


unsigned int substring_digit_check(string str){
    int i = 0;
    string str1;
    while(isdigit(str[i])){
        str1.push_back(str.at(i));
        ++i;
    }
    return i;
}


void u_bfs(vector<pair<int,int>> edges, int h_1){
    unordered_map<int,bool> nodes;
    for(auto v: edges) {
        nodes.insert(pair<int,bool >(v.first, false));
        nodes.insert(pair<int,bool >(v.second, false));
    }
    list<int> head;
    head.push_back(h_1);
    list<int> layer;
    list<int> answer;
    answer.push_back(head.front());
    bool cycle = true;
    while (cycle) {
        cycle = false;
        for (auto i: head) {
            if (!nodes.at(i)) {

                for (auto v: edges) {
                    if ((v.first == i) && !nodes.at(v.second)) {
                        layer.push_back(v.second);
                        cycle = true;
                    }
                   else if ((v.second == i) && !nodes.at(v.first)) {
                        layer.push_back(v.first);
                        cycle = true;
                    }
                }
            }
        }
        layer.sort();
        for(auto a: head){
            nodes.at(a) = true;
        }

        for(auto v: layer){
            if(!nodes.at(v)) {
                answer.push_back(v);
            }
        }
        head = layer;
        layer.clear();
    }
    for(auto a: answer) {
        cout << a << "\n";
    }
    cout << endl;
}



void d_bfs(vector<pair<int,int>> edges, int h_1){
    unordered_map<int,bool> nodes;
    for(auto v: edges) {
        nodes.insert(pair<int,bool >(v.first, false));
        nodes.insert(pair<int,bool >(v.second, false));
    }
    list<int> head;
    head.push_back(h_1);
    list<int> layer;
    list<int> answer;
    answer.push_back(head.front());
    bool cycle = true;
    while (cycle) {
        cycle = false;

        for (auto i: head) {
            if (!nodes.at(i)) {

                for (auto v: edges) {
                    if ((v.first == i) && !nodes.at(v.second)) {
                        layer.push_back(v.second);
                        cycle = true;
                    }
                }
            }
        }

        layer.sort();
        for(auto a: head){
            nodes.at(a) = true;
        }
        for(auto v: layer){
            if(!nodes.at(v)) {
                answer.push_back(v);
            }
        }
        head = layer;
        layer.clear();
    }

    for(auto a: answer) {
        cout << a << "\n";
    }
    cout << endl;
}




void u_dfs(vector<pair<int, int>> edges, int h_1){

    unordered_map<int, bool> nodes;
    for (auto v: edges) {
        nodes.insert(pair<int, bool>(v.first, false));
        nodes.insert(pair<int, bool>(v.second, false));
    }

    int head = h_1;
    list<int> path;
    list<int> answer;
    list<int> minimum;
    path.push_back(head);
    answer.push_back(head);
    nodes.at(head) = true;

    while (!path.empty()){
        bool cycle = true;
        while (cycle) {
            cycle = false;
            for (auto v: edges) {
                if ((v.first == head) && (!nodes.at(v.second))) {
                    minimum.push_back(v.second);
                    cycle = true;
                }
                if ((v.second == head) && (!nodes.at(v.first))) {
                    minimum.push_back(v.first);
                    cycle = true;
                }
            }


            auto k = min_element(minimum.begin(),minimum.end());
            if(!minimum.empty()) {
                head = *k;
                minimum.clear();
                answer.push_back(head);
                path.push_back(head);
                nodes.at(head) = true;
            }
        }
        path.pop_back();
        head = path.back();
    }


    for(auto a: answer){
        cout << a << "\n";
    }
    cout << endl;
}





void d_dfs(vector<pair<int, int>> edges,  int h_1){
    unordered_map<int, bool> nodes;
    for (auto v: edges) {
        nodes.insert(pair<int, bool>(v.first, false));
        nodes.insert(pair<int, bool>(v.second, false));
    }

    int head = h_1;

    list<int> path;
    list<int> answer;
    list<int> minimum;
    path.push_back(head);
    answer.push_back(head);
    nodes.at(head) = true;

    while (!path.empty()){
        bool cycle = true;
        while (cycle) {
            cycle = false;
            for (auto v: edges) {
                if ((v.first == head) && (!nodes.at(v.second))) {
                    minimum.push_back(v.second);
                    cycle = true;
                }
            }
            auto k = min_element(minimum.begin(),minimum.end());
            if(!minimum.empty()) {
                head = *k;
                minimum.clear();
                answer.push_back(head);
                path.push_back(head);
                nodes.at(head) = true;
            }
        }
        path.pop_back();
        head = path.back();
    }
    for(auto a: answer){
        cout << a << "\n";
    }
    cout << endl;
}





int main() {
    vector<pair<int, int>> edges;


    string string1, string2;
    bool first_string = false;
    string val1, val2;
    

    while(std::getline(std::cin,string2)){

        if(!first_string){
            string1 = string2;
            first_string = true;
        }
        else{
            val1 = string2.substr(0,0+substring_digit_check(string2.substr(0,string2.size())));
            val2 = string2.substr(val1.size()+1,val1.size()+1+substring_digit_check(string2.substr(val1.size()+1,string2.size())));
            edges.emplace_back(stoi(val1),stoi(val2));
        }
    }

    int head = stoi(string1.substr(2,2+substring_digit_check(string1.substr(2,string1.size()))));

    if((string1.substr(0,1)=="d")
       &&(string1[1] == ' ') &&
       ((string1.substr(2+substring_digit_check(string1.substr(2,string1.size())),string1.size()))==" b")){
        d_bfs(edges,head);
    }
    else if((string1.substr(0,1)=="d")
       &&(string1[1] == ' ') &&
       ((string1.substr(2+substring_digit_check(string1.substr(2,string1.size())),string1.size()))==" d")){
        d_dfs(edges,head);
    }
    else if((string1.substr(0,1)=="u")
       &&(string1[1] == ' ') &&
       ((string1.substr(2+substring_digit_check(string1.substr(2,string1.size())),string1.size()))==" b")){
        u_bfs(edges,head);
    }
    else if((string1.substr(0,1)=="u")
       &&(string1[1] == ' ') &&
       ((string1.substr(2+substring_digit_check(string1.substr(2,string1.size())),string1.size()))==" d")){
        u_dfs(edges,head);
    }
}
