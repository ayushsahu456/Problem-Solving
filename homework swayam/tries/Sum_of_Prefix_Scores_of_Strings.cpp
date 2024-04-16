#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int cp=0;
    int ew=0;
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string &s){
        int n=s.size();
        Node* temp=root;
        for(int i=0; i<n; i++){
            if(temp->links[s[i]-'a']==NULL){
                Node* newnode=new Node();
                temp->links[s[i]-'a']=newnode;
            }
            temp=temp->links[s[i]-'a'];
            temp->cp++;
        }
        temp->ew++;
    }
    int query(string &s){
        int n=s.size(); 
        Node* temp=root;
        int count=0;
        for(int i=0; i<n; i++){
            if(temp->links[s[i]-'a']==NULL){
                return count;
            }
            else{
                temp=temp->links[s[i]-'a'];
                count+=temp->cp;
            }
        }
        return count;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie T;
        for(int i=0; i<words.size(); i++){
            T.insert(words[i]);
        }
        vector<int> ans;
        for(int i=0; i<words.size(); i++){
            int temp=T.query(words[i]);
            ans.push_back(temp);
        }
        return ans;
    }
};