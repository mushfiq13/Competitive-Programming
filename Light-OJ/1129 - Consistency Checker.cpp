#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct TrieNode {
    bool EndOfWord;
    int prefix;
    TrieNode *child[10];
    TrieNode() {
        EndOfWord = false;
        prefix = 0;
        for (int i=0; i<=9; ++i)
            child[i] = NULL;
    }
};

TrieNode *root;
bool flag;

void Insert (string s)
{
    TrieNode *curr = root;

    for (int i=0; s[i]; ++i) {
        int ch = s[i]-'0';
        if (curr->child[ch] == NULL)
            curr->child[ch] = new TrieNode();
        if (curr->child[ch]->EndOfWord) {
            flag = false;
            return;
        }
        ++curr->child[ch]->prefix;
        curr = curr->child[ch];
    }

    if (curr->EndOfWord || curr->prefix>1)
        flag = false;

    curr->EndOfWord = true;
}

void clearTrie(TrieNode *root)
{
    for (int i=0; i<=9; i++)
        if (root->child[i] != NULL) {
            clearTrie(root->child[i]);
            delete root->child[i];
        }
}

int main ()
{
    int t, n, cs=0;

    cin >> t;

    while (t--) {
        cin >> n;

        flag = true;
        root = new TrieNode;

        while (n--) {
            string s;
            cin >> s;
            if (flag)
                Insert(s);
        }

        if (flag)
            printf("Case %d: YES\n", ++cs);
        else
            printf("Case %d: NO\n", ++cs);

        clearTrie(root);
        delete root;
    }

    return 0;
}
