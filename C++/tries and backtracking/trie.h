#include"triesNode.h"
#include<iostream>
using namespace std;
#include<string>
class Trie{
    trieNode *root;
    public :
    Trie()
    {
        root = new trieNode('\0');
    }

    //for user
    void insertWord(trieNode *root,string word)
    {
        if (word.size()==0)
        {
            root->isTerminal = true;
            return;
        }
        // small calculation
        int index = word[0] - 'a';
        trieNode *child;
        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new trieNode(word[0]);
            root->children[index] = child;
        }
        insertWord(child,word.substr(1));
        
    }
    void insertWord(string word)
    {
        insertWord(root,word); 
    }

    bool search(string word) {
        // Write your code here
        return search(root, word);
    }
    bool search(trieNode *root,string word)
    {
        if(word.size()==0)
        {
            if(root->isTerminal==true)
                 return true;
            else
                 return false;
        }
        int index = word[0] - 'a';
        if(root->children[index]==NULL)
        {
            return false;
        }
        else
        {
          return search(root->children[index], word.substr(1));
        }
        
    }

    void removeWord(string word)
    {
        removeWord(root,word);
    }
    void removeWord(trieNode *root,string word)
    {
        if(word.size()==0)
        {
            root->isTerminal = false;
            return;
        }
        trieNode *child;
        int index = word[0] - 'a';
        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }
        removeWord(child,word.substr(1));

        if(child->isTerminal==false)
        {
            for (int i = 0; i < 26; i++)
            {
                if(child->children[i]!=NULL)
                    return;
            }
            delete child;
            root->children[index] = NULL;
            
        }
        
    }
};