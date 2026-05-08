#include <iostream>
#include <vector>
#include <string>
using namespace std;

void stringBasicOperation(){
    string s1 = "hello";
    string s2("world");
    string s = s1 + ' ' + s2;
    string sub = s1.substr(1, 3);
    cout << sub << endl;
    size_t pos = s.find('w');
    if(pos == string::npos){
        cout << "no" << endl;
    }
    else{
        cout << "pos : " << pos << endl;
    }
}

int violentMatch(string s, string p){
    int n = s.size();
    int m = p.size();
    for(int i = 0; i <= n - m; ++i){
        int j = 0;
        while(j < m && s[i + j] == p[j]){
            j++;
        }
        if(j == m){
            return i;
        }
    }
    return -1;
}

vector<int> getNext(string p){
    int n = p.size();
    vector<int> next(n, 0);
    int j = 0;
    for(int i = 1; i < n; ++i){
        if(j > 0 && p[i] != p[j]){
            j = next[j - 1];
        }
        if(p[i] == p[j]){
            j++;
        }
        next[i] = j;
    }
    return next;
}

// i 指向主串最后一个匹配成功位置
// j 指向已匹配成功字符个数
int kmpSearch(string s, string p, vector<int> next){
    int n = s.size();
    int m = p.size();
    int j = 0;
    for(int i = 1; i < n; ++i){
        while(j > 0 && s[i] != p[j]){
            j = next[j];
        }
        if(s[i] == p[j]){
            j++;
        }
        if(j == m){
            return i - m + 1;
        }
    }
    return -1;
}

vector<int> getNextVal(string p, vector<int> next){
    int n = p.size();
    vector<int> nextVal(n, 0);
    for(int i = 1; i < n; ++i){
        if(p[i] == p[next[i]]){
            nextVal[i] = nextVal[next[i]];
        }
        else{
            nextVal[i] = next[i];
        }
    }
    return nextVal;
}

int kmpSearchVal(string s, string p, vector<int> nextVal){
    int n = s.size();
    int m = p.size();
    int j = 0;
    for(int i = 1; i < n; ++i){
        while(j > 0 && s[i] != p[j]){
            j = nextVal[j - 1];
        }
        if(s[i] == p[j]){
            j++;
        }
        if(j == m){
            return i - m + 1;
        }
    }
    return -1;
}


int main(){
    stringBasicOperation();
    string s = "abcabcabcd";
    string p = "cabc";

    int pos = violentMatch(s, p);
    cout << pos << endl;

    vector<int> next = getNext(p);
    pos = kmpSearch(s, p, next);
    cout << pos << endl;

    vector<int> nextVal = getNextVal(p, next);
    pos = kmpSearchVal(s, p, nextVal);
    cout << pos << endl;

    return 0;
}