#include <bits/stdc++.h> 
using namespace std;

struct TrieNode {
  TrieNode* alphabets[26];
  int prefix = 0;
  int end = 0;  

  bool isNull(char ch){
      return alphabets[ch - 'a'] == NULL;
  }

  TrieNode* get(char ch){
      return alphabets[ch - 'a'];
  }

  void put(char ch, TrieNode* node){
      alphabets[ch - 'a'] = node;
  }

  void prefixPlusOne(){
      prefix++;
  }

  void endPlusOne(){
      end++;
  }

  void prefixMinusOne(){
      prefix--;
  }

  void endMinusOne(){
      end--;
  }

  int getPrefix(){
      return prefix;
  }

  int getEnd(){
      return end;
  }
};


class Trie{

    TrieNode* root;

    public:

    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
        TrieNode* node = root;
        for(char ch : word){
          if (node->isNull(ch)) {
            node->put(ch, new TrieNode);
          }
          node = node->get(ch);
          node->prefixPlusOne();
        }
        node->endPlusOne();
    }

    int countWordsEqualTo(string &word){
        TrieNode* node = root;
        for(char ch : word){
            if(node->isNull(ch)){
                return 0;
            }
            node = node->get(ch);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        TrieNode* node = root;
        for(char ch : word){
            if(node->isNull(ch)){
                return 0;
            }
            node = node->get(ch);
        }
        return node->getPrefix();
    }

    void erase(string word){
        int cnt = countWordsEqualTo(word);
        if(cnt <= 0) {
            cout<<word<<" doesn't exist"<<endl;
            return;
        }
        TrieNode* node = root;
        for(char ch : word){
            node = node->get(ch);
            node->prefixMinusOne();
        }
        node->endMinusOne();
    }
};
int main(){
    Trie* obj = new Trie();
    string words[] = {"apple","apple", "ball", "cat", "application"};
    for(auto word : words){
        obj->insert(word);
    }
    string search_words[] = {"apple", "ball", "dog"};
    for(auto word : search_words){
        cout<<"search word: "<<word<<" result: "<<obj->countWordsEqualTo(word)<<endl;
    }

    string startsWith_prefix[] = {"app", "zeb", "do"};
    for(auto prefix : startsWith_prefix){
        cout<<"prefix : "<<prefix<<" result: "<<obj->countWordsStartingWith(prefix)<<endl;
    }

    obj->erase("apple");
    obj->erase("dog");
    obj->erase("elephant");

    for(auto word : search_words){
        cout<<"search word: "<<word<<" result: "<<obj->countWordsEqualTo(word)<<endl;
    }

    for(auto prefix : startsWith_prefix){
        cout<<"prefix : "<<prefix<<" result: "<<obj->countWordsStartingWith(prefix)<<endl;
    }

}