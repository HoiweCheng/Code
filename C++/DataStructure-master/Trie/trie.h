#include<stdio.h>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class TrieNode
{
    public:
        int val;
        unordered_map<char,TrieNode*>children;
        TrieNode *parent;
        int wordCnt;
        int prefixCnt;

    public:
        TrieNode()
        {
            val = (int)' ';
            wordCnt = 0;
            prefixCnt = 0;
            parent = NULL;
            children.clear();
        }
        TrieNode(char ch, TrieNode *pa)
        {
            TrieNode();
            val = ch;
            parent = pa;
        }
        bool isWord()
        {
            return wordCnt > 0;
        }
};

class Trie
{
    TrieNode *rt;
    public:
        void addWord(string word);
        void addWord(TrieNode *node, string word);
        void removeWord(string word);
        vector<string> getWords();
        void getWords(TrieNode *node, string buff, vector<string>&res);
        vector<string> getWords(string prefix);
        bool hasWord(string word);
        int countWords(string word);
        int countPrefixes();
};

