#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    int prefix;
    TrieNode *child[26];
    TrieNode(): prefix(0) {
        for (int i=0; i<26; ++i)
            child[i] = NULL;
    }
};

TrieNode *root;
char s[10000][21];

void insert(string s)
{
    TrieNode *curr = root;
    for (int i=0; s[i]; ++i) {
        int ch = s[i]-'a';
        if (curr->child[ch] == NULL)
            curr->child[ch] = new TrieNode;
        ++curr->child[ch]->prefix;
        curr = curr->child[ch];
    }
}

int search(string s)
{
    TrieNode *curr = root;
    for (int i=0; s[i]; ++i) {
        int ch = s[i]-'a';
        if (curr->child[ch]->prefix == 1)
            return i+1;
        curr = curr->child[ch];
    }
    return s.size();
}

int main()
{
    int n=0;

    root = new TrieNode;
    while (scanf(" %s", s[n]) != EOF) {
        insert(s[n]);
        ++n;
    }

    for (int i=0; i<=n; ++i) {
        printf("%s ", s[i]);
        int l = search(s[i]);
        for (int j=0; j<l; ++j)
            printf("%c", s[i][j]);
        puts("");
    }

    return 0;
}
