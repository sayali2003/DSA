#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string keyword;
    string meaning;
    Node* left;
    Node* right;

    Node(string key, string val) {
        keyword = key;
        meaning = val;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* addNode(Node* node, string key, string val) {
        if (node == NULL) {
            node = new Node(key, val);
            return node;
        }
        if (key < node->keyword) {
            node->left = addNode(node->left, key, val);
        }
        else if (key > node->keyword) {
            node->right = addNode(node->right, key, val);
        }
        else {
            node->meaning = val;
        }
        return node;
    }

    Node* deleteNode(Node* node, string key) {
        if (node == NULL) {
            return node;
        }
        if (key < node->keyword) {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->keyword) {
            node->right = deleteNode(node->right, key);
        }
        else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->keyword = temp->keyword;
            node->meaning = temp->meaning;
            node->right = deleteNode(node->right, temp->keyword);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    void displayAsc(Node* node) {
        if (node != NULL) {
            displayAsc(node->left);
            cout << "Keyword: " << node->keyword << ", Meaning: " << node->meaning << endl;
            displayAsc(node->right);
        }
    }

    void displayDesc(Node* node) {
        if (node != NULL) {
            displayDesc(node->right);
            cout << "Keyword: " << node->keyword << ", Meaning: " << node->meaning << endl;
            displayDesc(node->left);
        }
    }

public:
    BST() {
        root = NULL;
    }

    void add(string key, string val) {
        root = addNode(root, key, val);
    }

    void deleteNode(string key) {
        root = deleteNode(root, key);
    }

    void update(string key, string val) {
        root = deleteNode(root, key);
        root = addNode(root, key, val);
    }

    void displayAsc() {
        displayAsc(root);
    }

    void displayDesc() {
        displayDesc(root);
    }
};


int main() {
    BST dict;

    dict.add("apple", "a fruit with red or green skin and a round shape");
    dict.add("banana", "a long curved fruit which is yellow when ripe");
    dict.add("carrot", "a long, thin, orange vegetable");
    dict.add("date", "the sweet fruit of the date palm");

    cout << "Ascending order:" << endl;
    dict.displayAsc();

    cout << "\nDescending order:" << endl;
    dict.displayDesc();

    dict.deleteNode("banana");
    cout << "\nAfter deleting banana:" << endl;
    dict.displayAsc();

    dict.update("apple", "a fruit with red or green skin and a round or oval shape");
    cout << "\nAfter updating apple:" << endl;
    dict.displayAsc();

    return 0;
}


