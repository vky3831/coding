#include<bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


struct TrieNode{
    TrieNode* alphabets[26];
    bool end = false;

    bool isNull(char c){
        return alphabets[c - 'a'] == NULL;
    }

    void put(char c, TrieNode* node){
        alphabets[c - 'a'] = node;
    }

    TrieNode* get(char c){
        return alphabets[c - 'a'];
    }

    bool isEnd(){
        return end;
    }

    void setEndTrue(){
        end = true;
    }

    void setEndFalse(){
        end = false;
    }

};

class Trie {

    TrieNode* root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(char ch : word){
            if(node->isNull(ch)){
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEndTrue();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(char ch :  word){
            if(node->isNull(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return node->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix){
            if(node->isNull(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};

int main(){
    Trie* obj = new Trie();
    string words[] = {"apple", "ball", "cat", "application"};
    for(auto word : words){
        obj->insert(word);
    }
    string search_words[] = {"apple", "ball", "dog"};
    for(auto word : words){
        cout<<"search word: "<<word<<" result: "<<obj->search(word)<<endl;
    }

    string startsWith_prefix[] = {"app", "zeb", "do"};
    for(auto prefix : startsWith_prefix){
        cout<<"prefix : "<<prefix<<" result: "<<obj->startsWith(prefix)<<endl;
    }
}