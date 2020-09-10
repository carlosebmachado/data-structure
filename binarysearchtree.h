#pragma once

#include <string>
#include "queue.h"

template <typename K>
int hash(K key) {
	return hash(key);
}

void printData(std::string str) {
	std::cout << str << std::endl;
}

template <typename V>
class Node {
public:
	V value;
	int key;
	Node* left;
	Node* right;

	Node(int key, V value) {
		this->value = value;
		this->key = key;
		left = nullptr;
		right = nullptr;
	}
};

template <typename V>
struct BinarySearchTree {
private:
	Node<V>* root;

public:
	BinarySearchTree() {
		root = nullptr;
	}

	// Insere na lista na posição indicada.
	bool insert(Node<V>* node) {
		if (not root) {
			root = node;
			return true;
		}
		auto prev = root;
		auto current = root;
		bool right = false;
		while (current) {
			if (node->key == current->key) {
				current = node;
				return true;
			}
			if (node->key > current->key) {
				prev = current;
				current = current->right;
				right = true;
			} else if (node->key < current->key) {
				prev = current;
				current = current->left;
				right = false;
			}
		}
		if (right) {
			prev->right = node;
		} else {
			prev->left = node;
		}
		return true;
	}

	// Remove na lista na posição indicada.
	bool remove(int key) {
		
		return false;
	}

	// Retorna o dado da lista na posiçãao indicada.
	Node<V>* search(int key) {
		auto current = root;
		while (current) {
			if (key == current->key) {
				return current;
			}
			if (key > current->key) {
				current = current->right;
			}
			else if (key < current->key) {
				current = current->left;
			}
		}
		return nullptr;
	}

	size_t nodeHeight(int key) {
		int height = 0;
		auto current = root;
		while (current) {
			if (key == current->key) {
				return height;
			}
			if (key > current->key) {
				current = current->right;
				height++;
			}
			else if (key < current->key) {
				current = current->left;
				height++;
			}
		}
		return -1;
	}

	// Imprime a lista completa.
	void print() {
		auto visQueue = Stack<Node<V>*>();
		auto curQueue = Stack<Node<V>*>();
		auto current = root;
		while (current) {
			if (not visQueue.exists(current)) {
				curQueue.push(current);
				visQueue.push(current);
				std::string str = "";
				for (size_t i = 0; i < curQueue.size() - 1; i++) str += "  ";
				str += current->value;
				str += " - {";
				str += std::to_string(current->key);
				str += "}";
				printData(str);
			}
			if (current->left and not visQueue.exists(current->left)) {
				current = current->left;
			} else if (current->right and not visQueue.exists(current->right)) {
				current = current->right;
			} else {
				curQueue.pop();
				current = curQueue.top();
			}
		}
	}
};
