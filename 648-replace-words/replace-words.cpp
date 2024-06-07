#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    std::string word;
    TrieNode() : word("") {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->word = word;
    }

    std::string searchShortestRoot(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                break;
            }
            node = node->children[ch];
            if (!node->word.empty()) {
                return node->word;
            }
        }
        return word;
    }
};

class Solution {
public:
    std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence) {
        Trie trie;
        for (const std::string& root : dictionary) {
            trie.insert(root);
        }

        std::istringstream iss(sentence);
        std::string word;
        std::string result;
        
        while (iss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += trie.searchShortestRoot(word);
        }
        
        return result;
    }
};
