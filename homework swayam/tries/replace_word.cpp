#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode *child[26];
    bool isEnd;
    
    TrieNode(){
        this->isEnd = false;
        for(int i=0; i<26; i++) this->child[i]= NULL;
    }
};

class Solution {
public:
    TrieNode *newNode;
    string check(string word){
        TrieNode *t = newNode;
        string s = "";
        
        for(auto i : word){
            if(!t->child[i-'a']) break;
            s += i;
            t = t->child[i-'a'];
            if(t->isEnd) return s;
        }
        return word;
    }
    void insert(string word){
        TrieNode *temp = newNode;
        
        for(auto l : word){
            if(!temp->child[l-'a']) temp->child[l-'a'] = new TrieNode();
            temp = temp->child[l-'a'];
        }
        
        temp->isEnd = true;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        newNode = new TrieNode();
        for(auto s : dictionary){
            insert(s);
        } 
        stringstream ss(sentence);
        string word = "", ans="";
        
        while(ss>>word){
            ans += check(word);
            ans += ' ';
        }
        ans.pop_back();
        
        return ans;
    }
};