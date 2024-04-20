/*
Huffman Code是一種很有效的編碼壓縮法，它根據一篇明文中的各個字母出現的機率將字母轉換成二進制的編碼，編碼方式如下：
假設一個明文為「mississippis」
m出現的頻率1/12
p出現的頻率為2/12
i出現的頻率4/12
s出現的頻率5/12
我們將頻率由小到大排列為{1/12,2/12,4/12,5/12}
我們每次都選出其中最小的來建成tree，所以我們會先選1/12，再來是2/12，並將其頻率相加變成3/12並放回數列中，接下來我們選出3/12與4/12相加變成7/12，並放回數列中，接下來我們選出5/12與7/12相加得到1，完成Huffman Tree的建構，注意我們每次都會將頻率較小的那一個放在左子樹，頻率較大的放在右子樹。
最後我們根據建好的樹，左樹給0右樹給1規則，為每個字母編碼


    編碼不能存在歧義，避免編碼的多義性，即不能有某個字元的編碼是另一個字元編碼的字首
    編碼應該儘可能的短，這要求採用不等長的編碼方案，並將出現頻率搞得字元賦予更短的編碼
    編碼演算法產生的編碼方案應該唯一，避免編碼與解碼的不對應
    編碼演算法效率應儘可能的高


Input
●	一串明文例如mississippis
●	當中不會有兩個字母出現相同次數的狀況
●	明文中的字母總數≦100
●	字母種類≦10

Output
將每個出現過的字母依編碼後的二進制數值大小，由小到到大輸出

Sample input
mississippis

Sample output
s:0
i:11
m:100
p:101
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Node
{
public:
    char c;    //結點字元，非字元結點預設為'z' + 1 = '{'
    int value; //結點出現頻率
    int idx;   //結點出現最早時間
    Node *left;
    Node *right;

    bool operator<(const Node &node)
    {
        if (value == node.value)
            return idx < node.idx;
        return value < node.value;
    }
};

Node *character[26];
Node *heap[2000];
int tot = 0;

void down(int k)
{
    int son = k << 1;
    while (son <= tot)
    {
        if (son + 1 <= tot && *heap[son + 1] < *heap[son])
            son++;
        if (*heap[k] < *heap[son])
            break;
        Node *temp = heap[k];
        heap[k] = heap[son];
        heap[son] = temp;
        k = son;
        son <<= 1;
    }
}

void up(int k)
{
    int fa = k >> 1;
    while (fa != 0)
    {
        if (*heap[fa] < *heap[k])
            break;
        Node *temp = heap[k];
        heap[k] = heap[fa];
        heap[fa] = temp;
        k = fa;
        fa >>= 1;
    }
}

void add(Node *node)
{
    heap[++tot] = node;
    up(tot);
}
Node *peak()
{
    return heap[1];
}
void pop()
{
    heap[1] = heap[tot--];
    down(1);
}

char *code[26];

void encode(char *s, int dep, Node *node)
{

    //當前編碼，深度，當前結點
    if (node->left == NULL && node->right == NULL)
    {
        //如果該結點為葉子結點，則獲取編碼
        int c = node->c - 'a';
        s[dep] = '\0';
        code[c] = strdup(s); //根據當前編碼克隆一個字串並儲存
        return;
    }
    s[dep] = '0';
    encode(s, dep + 1, node->left); //遍歷左子樹，編碼追加0
    s[dep] = '1';
    encode(s, dep + 1, node->right); //遍歷右子樹，編碼追加1
}

char str[10000];
int main()
{
    cin >> str;
    int len = strlen(str);
    for (int i = 0, c; i < len; i++)
    {
        c = str[i] - 'a';
        if (character[c] == NULL)
        {
            //如果該字母第一次出現，則建立結點並且記錄第一次出現位置
            character[c] = new Node();
            character[c]->c = str[i];
            character[c]->idx = i;
            character[c]->value = 1;
            character[c]->left = NULL;
            character[c]->right = NULL;
            add(character[c]);
        }
        else
            character[c]->value++;
    }
    int cnt = tot; //總結點數量
    Node *first;
    Node *second;
    Node *node;
    while (tot > 1)
    {
        //總結點數量每次減一，總共迴圈cnt-1次
        first = peak();
        pop();
        second = peak();
        pop();
        //建立新的結點
        node = new Node();
        node->c = 'z' + 1;
        node->value = first->value + second->value;
        node->left = first;
        node->right = second;
        node->idx = len++;
        add(node);
    }

    Node *root = peak(); //哈夫曼樹根節點
    char s[20];
    encode(s, 0, root);

    for (int i = 0; i < 26; i++)
        if (code[i] != NULL)
            cout << (char)(i + 'a') << ":" << code[i] << endl;
/*    cout<<"\n-----------\n";

    char *reCodePtr[26];
    char reCodeChar[26];
    int j = 0;
    for (int i = 0; i < 26; i++)
        if (code[i] != NULL)
        {
            reCodeChar[j] = (char)(i + 'a');
            reCodePtr[j] = code[i];
            j++;
        }
    for (int i = 0; i < j; i++)
        cout << reCodeChar[i] << ":" << reCodePtr[i] << endl;

    vector<int> reV1;

    for (int i = 0; i < j; i++)
        cout << reCodeChar[i] << ":" << reCodePtr[i] << endl;*/
}