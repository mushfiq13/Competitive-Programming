#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct TrieNode {
    int prefix;
    TrieNode *child[4];
    TrieNode() {
        prefix = 0;
        for (int i=0; i<4; ++i)
            child[i] = NULL;
    }
};

int mx;
string dna = "ACGT";

void insert(TrieNode *root, string s)
{
    for (int i=0, j; s[i]; ++i) {
        for (j=0; j<4; ++j)
            if (s[i] == dna[j])
                break;
        if (root->child[j] == NULL)
            root->child[j] = new TrieNode();
        ++root->child[j]->prefix;
        root = root->child[j];
        if (root->prefix*(i+1) > mx)
            mx = root->prefix*(i+1);
    }
}

void clearTrie(TrieNode *root)
{
    for (int i=0; i<4; ++i)
        if (root->child[i] != NULL) {
            clearTrie(root->child[i]);
            delete root->child[i];
        }
}

int main()
{
    int t, n, cs=0;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        mx = 0;
        TrieNode *root = new TrieNode();
        while (n--) {
            string s;
            cin >> s;
            insert(root,s);
        }
        printf("Case %d: %d\n", ++cs, mx);

        clearTrie(root);
        delete root;
    }

    return 0;
}
