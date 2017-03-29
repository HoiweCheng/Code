#include "trie.h"
#include <iostream>
using namespace std;

int main()
{
    Trie *trie = new Trie();
    cout << "constructed an empty trie" << endl;
    trie->addWord("test");
    cout << "added one word" << endl;
    trie->addWord("this");
    cout << "added second word" << endl;

    auto allWords = trie->getWords();
    for(int i = 0; i < allWords.size(); i++)
        cout << allWords[i] << endl;

//    auto prefixWords = trie.getWords("te");

 //   auto wordCnt = trie.countWord("test");
  //  auto hasword = trie.hasWord("test");

   // trie.removeWord("test");

    //if(trie.hasWord("test"))
     //   printf("has test\n");
    //else 
     //   printf("does not have test\n");

    //auto longestWord = trie.getLongestWord();
    
}

