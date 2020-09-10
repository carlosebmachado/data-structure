#pragma once

#include "static.h"
#include "linked.h"
#include "doublelinked.h"
#include "circular.h"
#include "queue.h"
#include "stack.h"
#include "hashtable.h"
#include "binarysearchtree.h"

class Vector2 {
public:
	int x;
	int y;

	Vector2() {
		x = 0;
		y = 0;
	}

	Vector2(int x, int y) {
		this->x = x;
		this->y = y;
	}

	~Vector2() {}
};

void printData(Vector2* vector2) {
	std::cout << "\nX: " << vector2->x << "\nY: " << vector2->y << std::endl;
}

//bool operator==(Vector2* left, Vector2* right) {
//	return left->x == right->x and
//		left->y == right->y;
//}
