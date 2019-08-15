#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
struct node {
    T value;
    struct node<T>* left = nullptr;
    struct node<T>* right = nullptr;
};

using nodeInt = struct node<int>;

nodeInt* gentree(nodeInt* parent, int value);
nodeInt* search(nodeInt* parent, int value);

enum OrderType {
    preorder = 1,
    inorder,
    postorder,
    gtorder
};

void traversal(nodeInt* parent, OrderType order);
void traversal_lo(nodeInt* node);


int main() {
    std::cout << "Hello, World!" << std::endl;
    int values[] = { 3, 2, 4, 1, 5 };
    nodeInt* root = nullptr;

    for (int i : values) {
        root = gentree(root, i);
    }

    traversal(root, gtorder);
    traversal(root, preorder);
    traversal(root, inorder);
    traversal(root, postorder);
    // level order
    traversal_lo(root);
    return 0;
}

nodeInt* gentree(nodeInt* parent, int value) {
    nodeInt* p;

    if (parent == nullptr) {
        p = new nodeInt;
        p->left = nullptr;
        p->right = nullptr;
        p->value = value;
        return p;
    } else if (value < parent->value) {
        parent->left = gentree(parent->left, value);
    } else {
        parent->right = gentree(parent->right, value);
    }

    return parent;
}

nodeInt* search(nodeInt* parent, int value) {
    if (parent == nullptr || parent->value == value) {
        return parent;
    } else if (value < parent->value) {
        return search(parent->left, value);
    } else {
        return search(parent->right, value);
    }
}

void traversal(nodeInt* parent, OrderType order) {
    if (parent == nullptr) {
        return;
    }

    switch (order) {
        case preorder:
            cout << "value: " << parent->value << "\n";
            traversal(parent->left, order);
            traversal(parent->right, order);
            break;
        case inorder:
            traversal(parent->left, order);
            traversal(parent->right, order);
            cout << "value: " << parent->value << "\n";
            break;
        case postorder:
            traversal(parent->left, order);
            traversal(parent->right, order);
            cout << "value: " << parent->value << "\n";
            break;
        case gtorder:
            traversal(parent->right, order);
            cout << "value: " << parent->value << "\n";
            traversal(parent->left, order);
            break;
    }
}

// q -> 비면 - stack을 비워서 queue에 추가.
void traversal_lo(nodeInt* node) {
    vector<nodeInt*> stack;
    queue<nodeInt*> queue;
    if (!node) {
        cout << "tree is empty.\n";
        return;
    }

    queue.push(node);

    while (true) {
        if (queue.empty()) {
            if (stack.empty()) {
                break;  // queue, stack 모두 empty이면 더이상 traverse할 노드 없음
            }

            // stack -> queue로 복사할때 stack 역순으로 복사해야 함
            for (nodeInt* p : stack) {
                queue.push(p);
            }
            vector<nodeInt*> empty;
            stack.swap(empty);
        }

        nodeInt* cur = queue.front();
        queue.pop();

        cout << cur->value << "\n";

        if (cur->left) {
            stack.push_back(cur->left);
        }
        if (cur->right) {
            stack.push_back(cur->right);
        }
    }
}
