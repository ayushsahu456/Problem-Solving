#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie* children[2];

    Trie() {
        children[0] = NULL;
        children[1] = NULL;
    }
};

class Solution {
public:
    void insert(int num, Trie* root) {
        Trie* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->children[bit] == NULL)
                node->children[bit] = new Trie();
            node = node->children[bit];
        }
    }

    int findMax(int num, Trie* root) {
        Trie* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->children[1 - bit] != NULL) {
                maxNum = maxNum | (1 << i);
                node = node->children[1 - bit];
            } else {
                node = node->children[bit];
            }
        }

        return maxNum;
    }

    int findMaximumXOR(vector<int>& nums) {
        Trie* root = new Trie();

        if (nums.size() == 1)
            return 0;

        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i], root);
        }

        int maxi = 0;
        int num = 0;
        for (int i = 0; i < nums.size(); i++) {
            num = findMax(nums[i], root);
            maxi = max(num, maxi);
        }

        return maxi;
    }
};