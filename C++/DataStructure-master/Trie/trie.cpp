#include "trie.h"
#include<iostream>
using namespace std;

void Trie::addWord(string word)
{
    addWord(rt,word);
}
void Trie::addWord(TrieNode *vertex, string word)
{
    cout << "word: " << word << endl;
    if(word.length()==0) rt->wordCnt ++;
    else
    {
        cout << "here" << endl;
        cout << "here 1.2" << endl;
        char ch = word[0];
        TrieNode *child = NULL; 
        if(rt->children.find(ch) == rt->children.end())
        {
            cout << "here 1.5" << endl;
            child = new TrieNode(ch, rt);
            rt->children[ch] = child;
        }
        else child = rt->children[ch];
        cout << "here 2" << endl;
        word = word.substr(1);
        cout << "cur word: " << word << endl;
        addWord(child,word);
    }
}

int Trie::countPrefixes()
{
    return rt->prefixCnt;
}

int Trie::countWords(string word)
{
    return rt->wordCnt;
}

void Trie::removeWord(string word)
{
    //to do
}

vector<string> Trie:: getWords()
{
    string buff;
    vector<string>words;
    getWords(rt, buff, words);
    return words;
}

void Trie::getWords(TrieNode *vertex, string buff, vector<string>&words)
{
    if(vertex->isWord())
    {
        words.push_back(buff);
    }
    unordered_map<char, TrieNode*>::iterator it = vertex->children.begin();
    for(; it != vertex->children.end(); it++)
    {
        getWords(it->second, buff+it->first, words);
    }
}

