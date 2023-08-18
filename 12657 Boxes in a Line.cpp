#include <iostream>

using namespace std;

int right_idx = 0;
int left_idx = 1;

struct Node {
    int val;

    // Accessed based on `right_idx`, which determines which is the right direction.
    Node* siblings[2];
};

const int MaxN = 100005;

int N;
Node nodes[MaxN];

Node* first_node;
Node* last_node;

void RemoveFromSpot(int val) {
    Node* node = &nodes[val];

    if (N > 1) {
        if (node == first_node) {
            first_node = node->siblings[right_idx];
        }
        if (node == last_node) {
            last_node = node->siblings[left_idx];
        }
    }
    if (node->siblings[0] != nullptr) {
        node->siblings[0]->siblings[1] = node->siblings[1];
    }
    if (node->siblings[1] != nullptr) {
        node->siblings[1]->siblings[0] = node->siblings[0];
    }
}

// Note that this doesn't remove the node from its original position.
void PlaceBetween(int val, Node* left, Node* right) {
    Node* n = &nodes[val];

    n->siblings[left_idx] = left;
    if (left != nullptr) {
        left->siblings[right_idx] = n;
    } else {
        first_node = n;
    }
    n->siblings[right_idx] = right;
    if (right != nullptr) {
        right->siblings[left_idx] = n;
    } else {
        last_node = n;
    }
}

Node* GetSwapSibling(Node* cur, int dir, Node* swapee) {
    Node* res = cur->siblings[dir];
    if (res == swapee) {
        return cur;
    }
    return res;
}

void Swap(int v1, int v2) {
    Node* n1 = &nodes[v1];
    Node* n2 = &nodes[v2];

    // v1 right = v2.
    RemoveFromSpot(v1);
    RemoveFromSpot(v2);

    // v1->right == v2 -> v2->right == v1

    auto n1l = GetSwapSibling(n1, left_idx, n2);
    auto n1r = GetSwapSibling(n1, right_idx, n2);
    auto n2l = GetSwapSibling(n2, left_idx, n1);
    auto n2r = GetSwapSibling(n2, right_idx, n1);

    PlaceBetween(v1, n2l, n2r);
    PlaceBetween(v2, n1l, n1r);
}

int main() {
    for (int i = 0; i < MaxN; ++i) {
        nodes[i].val = i;
    }

    int T = 1;
    int M;
    while (cin >> N >> M) {
        right_idx = 0;
        left_idx = 1;

        for (int i = 1; i <= N; ++i) {
            nodes[i].siblings[0] = &nodes[i + 1];
            nodes[i].siblings[1] = &nodes[i - 1];
        }
        // End nodes.
        nodes[1].siblings[left_idx] = nullptr;
        nodes[N].siblings[right_idx] = nullptr;

        first_node = &nodes[1];
        last_node = &nodes[N];

        while (M--) {
            int command;
            cin >> command;
            if (command == 4) {
                // Swap direction
                right_idx = (right_idx + 1) % 2;
                left_idx = (left_idx + 1) % 2;

                swap(first_node, last_node);

                continue;
            }
            int X, Y;
            cin >> X >> Y;

            if (X == Y) {
                continue;
            }

            if (command == 1) {
                RemoveFromSpot(X);
                PlaceBetween(X, nodes[Y].siblings[left_idx], &nodes[Y]);
            } else if (command == 2) {
                RemoveFromSpot(X);
                PlaceBetween(X, &nodes[Y], nodes[Y].siblings[right_idx]);
            } else {
                Swap(X, Y);
            }
        }

        long long sum = 0;
        bool count = true;

        for (; first_node != nullptr; first_node = first_node->siblings[right_idx]) {
            if (count) {
                sum += first_node->val;
            }
            count = !count;
        }
        cout << "Case " << (T++) << ": " << sum << '\n';
    }
}