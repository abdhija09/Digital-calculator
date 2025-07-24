#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createnode(int data) {
    Node* newnode = new Node();
    newnode->data = data;
    newnode->left = newnode->right = nullptr;
    return newnode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createnode(data);
    }
    if (data > root->data) {
        root->right = insert(root->right, data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    return root;
}

Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    ofstream out("bst_timing.csv");  // Output file
    out << "InputSize,SearchTime\n";  // CSV header

    // Measure for various input sizes
    for (int n = 100; n <= 5000; n += 200) {
        Node* root = nullptr;
        vector<int> values;

        // Fill vector with values 1 to n
        for (int i = 1; i <= n; i++) {
            values.push_back(i);
        }

        // Shuffle to prevent degenerate tree (linked list)
        random_shuffle(values.begin(), values.end());

        // Insert into BST
        for (int val : values) {
            root = insert(root, val);
        }

        // Pick a random key to search
        int key = rand() % n + 1;

        // Time the search
        auto start = high_resolution_clock::now();
        Node* result = search(root, key);
        auto end = high_resolution_clock::now();

        duration<double, milli> elapsed = end - start;  // milliseconds

        // Write to file
        out << n << "," << elapsed.count() << "\n";

        cout << "n = " << n << ", time = " << elapsed.count() << " ms" << endl;
    }

    out.close();
    cout << "bst_timing.csv generated.\n";
    return 0;
}
