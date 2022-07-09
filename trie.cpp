#include <iostream>
using namespace std;

struct Node
{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char c)
    {
        return links[c - 'a'] != NULL;
    }

    void put(char c, Node *node)
    {
        links[c - 'a'] = node;
    }

    Node *get(char c)
    {
        return links[c - 'a'];
    }

    void increaseEnd()
    {
        cntEndWith++;
    }

    void increasePrefix()
    {
        cntPrefix++;
    }

    void reduceEnd()
    {
        cntEndWith--;
    }

    void reducePrefix()
    {
        cntPrefix--;
    }

    int getEnd()
    {
        return cntEndWith;
    }

    int getPrefix()
    {
        return cntPrefix;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &s)
    {
        Node *node = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (!node->containsKey(s[i]))
            {
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &s)
    {
        Node *node = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (!node->containsKey(s[i]))
            {
                return 0;
            }
            node = node->get(s[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &s)
    {
        Node *node = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (!node->containsKey(s[i]))
            {
                return 0;
            }
            node = node->get(s[i]);
        }
        return node->getPrefix();
    }

    void erase(string &s)       // considering the word exists
    {
        Node *node = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (!node->containsKey(s[i]))
            {
                return;
            }
            node = node->get(s[i]);
            node->reducePrefix();
        }
        node->reduceEnd();
    }
};

int main()
{

    return 0;
}
