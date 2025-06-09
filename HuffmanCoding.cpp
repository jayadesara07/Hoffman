#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

Node *getNode(char ch, int freq, Node *left, Node *right) {
    Node *node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

struct comp {
    bool operator()(Node *l, Node *r) {
        return l->freq > r->freq;
    }
};

void encode(Node *root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void decode(Node *root, int &index, string str, ofstream &outputFile) {
    if (root == nullptr) return;

    if (!root->left && !root->right) {
        outputFile << root->ch;
        return;
    }

    index++;
    if (str[index] == '0')
        decode(root->left, index, str, outputFile);
    else
        decode(root->right, index, str, outputFile);
}

void buildHuffmanTree(const string &text) {
    unordered_map<char, int> freq;
    for (char ch : text)
        freq[ch]++;

    priority_queue<Node *, vector<Node *>, comp> pq;
    for (auto pair : freq)
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    Node *root = pq.top();

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    string encodedStr = "";
    for (char ch : text)
        encodedStr += huffmanCode[ch];

    // Write encoded string to binary file
    ofstream encodedFile("encoded.bin");
    if (encodedFile.is_open()) {
        encodedFile << encodedStr;
        encodedFile.close();
    }

    // Decode and write to decoded.txt
    int index = -1;
    ofstream decodedFile("decoded.txt");
    while (index < (int)encodedStr.size() - 2) {
        decode(root, index, encodedStr, decodedFile);
    }
    decodedFile.close();
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "No Input File" << endl;
        return 1;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf();
    string text = buffer.str();
    inputFile.close();

    buildHuffmanTree(text);
    return 0;
}
