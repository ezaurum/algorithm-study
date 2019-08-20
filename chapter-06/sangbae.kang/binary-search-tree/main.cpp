#include <iostream>

using namespace std;

#define nil -1

struct TreeNode {
    int left;
    string name;
    int right;
};

const int max_size = 100;
TreeNode tree[max_size] = {
        { 1, "Matilda", 2 },
        { 3, "Candy", 4 },
        { 5, "Rolla", nil },
        { nil, "Ann", nil },
        { 6, "Emy", 7 },
        { nil, "Nancy", nil },
        { nil, "Eluza", nil },
        { nil, "Lisa", nil }
};

// insert용으로 저장 tree
TreeNode treeNew[max_size];
int sp = 0; // tree append 위치

int search(const string& key);
int insert(const string& key);

int main() {
    search("Emy");
    search("Emmy");

    insert("Matilda");
    insert("Candy");
    insert("Rolla");
    insert("Ann");
    for (int i = 0; i < sp; i++) {
        cout << "left: " << treeNew[i].left << ", name: " << treeNew[i].name
            << ", right: " << treeNew[i].right << "\n";
    }
    return 0;
}

int search(const string& key) {
    int ptr = 0;
    while (ptr != nil) {
        if (key == tree[ptr].name) {
            cout << key << " found.\n";
            return ptr;
        } else if (key.compare(tree[ptr].name) < 0) {
            ptr = tree[ptr].left;
        } else {
            ptr = tree[ptr].right;
        }
    }
    cout << key << " not found.\n";
    return -1;
}

int insert(const string& key) {
    treeNew[sp].left = nil;
    treeNew[sp].right = nil;
    treeNew[sp].name = key;

    if (sp == 0) {
        return sp++;
    }

    int ptr = 0;

    while (ptr != nil) {
        int comp = key.compare(treeNew[ptr].name);
        if (comp == 0) {
            cout << "duplicate key.\n";
            return nil;
        }
        if (comp < 0){
            if (treeNew[ptr].left == nil) {
                treeNew[ptr].left = sp;
                break;
            }
            ptr = treeNew[ptr].left;
        } else {
            if (treeNew[ptr].right == nil) {
                treeNew[ptr].right = sp;
                break;
            }
            ptr = treeNew[ptr].right;
        }
    }

    return sp++;
}
