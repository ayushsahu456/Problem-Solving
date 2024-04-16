#include <bits/stdc++.h>
using namespace std;

class trie {
public:
    int bestIdx = 0;
    trie *children[26];
};
class Solution {
    void insert(trie *root, int i, vector<string>& wordsContainer) {
        trie* curr = root;
        if(wordsContainer[i].length() < wordsContainer[curr -> bestIdx].length()) curr -> bestIdx = i;
        for(int j = wordsContainer[i].length() - 1; j >= 0; j--) {
            int ch = wordsContainer[i][j] - 'a';
            if(curr -> children[ch] == nullptr) {
                curr -> children[ch] = new trie(i);
            } 
            curr = curr -> children[ch];
            if(wordsContainer[i].length() < wordsContainer[curr -> bestIdx].length()) curr -> bestIdx = i;
        }
    }
    int search(trie *root, string &word) {
        trie* curr = root;
        for(int i = word.size() - 1; i >= 0; i--) {
            int ch = word[i] - 'a';
            if(curr -> children[ch] == nullptr) {
                return curr -> bestIdx;
            } 
            curr = curr -> children[ch];
        }
        return curr -> bestIdx;
    }
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie *root = new trie(0);
        for(int i = 0; i < wordsContainer.size(); i++) {
            insert(root, i, wordsContainer);
        }
        vector<int> ans;
        for(int i = 0; i < wordsQuery.size(); i++) {
            ans.push_back(search(root, wordsQuery[i]));
        }
        return ans;
    }
};