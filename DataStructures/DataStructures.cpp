#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <stack>
#include <queue>
#include <unordered_map>

// TODO: Huffman tree node
struct Node {
    char data;
    int freq;
    Node* left, * right;
};

// TODO: Comparison struct for priority queue
struct CompareNodes {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};


// TODO: Function to build the Huffman tree
Node* buildHuffmanTree(std::priority_queue<Node*, std::vector<Node*>, CompareNodes> pq) {
    while (pq.size() != 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();


        Node* node = new Node();
        node->data = '$';
        node->freq = left->freq + right->freq;
        node->left = left;
        node->right = right;

        pq.push(node);
    }

    return pq.top();
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        std::cout << root->data << " ";
        for (int i = 0; i < top; i++) {
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
}

// TODO: Function to perform Huffman coding on the input string
// TODO: Function to perform Huffman decoding on the encoded string
void HuffmanCodes(char data[], int freq[], int size) {
    std::priority_queue<Node*, std::vector<Node*>, CompareNodes> pq;

    for (int i = 0; i < size; i++) {
        Node* newNode = new Node();
        newNode->data = data[i];
        newNode->freq = freq[i];

        pq.push(newNode);
    }

    Node* root = buildHuffmanTree(pq);

    int arr[100], top = 0;
    printCodes(root, arr, top);
}


int main() {
    char data[] = {'A','B','C','D'};
    int freq[] = {1,2,3,4};
    int size = sizeof(data) / sizeof(data[0]);

    HuffmanCodes(data, freq, size);
    return 0;
}
