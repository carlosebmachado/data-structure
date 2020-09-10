#include <iostream>

#include "data.h"

using namespace std;

void staticListTest();
void linkedListTest();
void doubleLinkedListTest();
void circularListTest();
void queueTest();
void stackTest();
void hashtableTest();
void binarySearchTreeTest();

int main() {
	//staticListTest();
	//linkedListTest();
	//doubleLinkedListTest();
	//circularListTest();
	//queueTest();
	//stackTest();
	//hashtableTest();
	binarySearchTreeTest();

	return EXIT_SUCCESS;
}

void staticListTest() {
	StaticList<Vector2*, 10> list = StaticList<Vector2*, 10>();

	if (list.get(0) != nullptr)
		cout << "i = 0: x:" << list.get(0)->x << " y:" << list.get(0)->y << endl;
	if (list.get(3) != nullptr)
		cout << "i = 3: x:" << list.get(3)->x << " y:" << list.get(3)->y << endl;

	list.insert(new Vector2(1, 5), 0);
	list.insert(new Vector2(2, 5), 0);
	//list.insert(new Vector2(3, 5, 0
	//list.insert(new Vector2(4, 5), 0);
	//list.insert(new Vector2(5, 5), 0);
	//list.insert(new Vector2(5, 5), 1);

	//list.insert(new Vector2(6, 5), 10);
	//list.insert(new Vector2(7, 5), -1);
	//list.insert(new Vector2(9, 5), 6);
	//list.insert(new Vector2(8, 5), 5);

	list.remove(0);
	//list.remove(1);
	//list.remove(3);
	//list.remove(4);
	//list.remove(5);

	//cout << list.existis(new Vector2(1, 5)) << endl;
	//cout << list.existis(new Vector2(10, 5)) << endl;

	if (list.get(0) != nullptr)
		cout << "i = 0: x:" << list.get(0)->x << " y:" << list.get(0)->y << endl;
	if (list.get(3) != nullptr)
		cout << "i = 3: x:" << list.get(3)->x << " y:" << list.get(3)->y << endl;


	cout << "size: " << list.size << endl;

	list.print();
}

void linkedListTest() {
	LinkedList<Vector2*> list = LinkedList<Vector2*>();

	if (list.get(0) != nullptr)
		cout << "i = 0: x:" << list.get(0)->x << " y:" << list.get(0)->y << endl;
	if (list.get(3) != nullptr)
		cout << "i = 3: x:" << list.get(3)->x << " y:" << list.get(3)->y << endl;

	list.insert(new Vector2(1, 5), 0);
	list.insert(new Vector2(2, 5), 0);
	//list.insert(new Vector2(3, 5), 0);
	//list.insert(new Vector2(4, 5), 0);
	//list.insert(new Vector2(5, 5), 0);
	//list.insert(new Vector2(5, 5), 1);

	//list.insert(new Vector2(6, 5), 10);
	//list.insert(new Vector2(7, 5), -1);
	//list.insert(new Vector2(9, 5), 6);
	//list.insert(new Vector2(8, 5), 5);

	//list.remove(0);
	list.remove(1);
	//list.remove(3);
	//list.remove(4);
	//list.remove(5);

	if (list.get(3) != nullptr)
		cout << "i = 3: x:" << list.get(3)->x << " y:" << list.get(3)->y << endl;
	cout << "size: " << list.size();

	cout << endl;

	list.print();
}

void doubleLinkedListTest() {
	DoubleLinkedList<Vector2*> list = DoubleLinkedList<Vector2*>();

	if (list.get(0) != nullptr)
		cout << "i = 0: x:" << list.get(0)->x << " y:" << list.get(0)->y << endl;
	if (list.get(3) != nullptr)
		cout << "i = 3: x:" << list.get(3)->x << " y:" << list.get(3)->y << endl;

	list.insert(new Vector2(1, 5), 0);
	list.insert(new Vector2(2, 5), 0);
	list.insert(new Vector2(3, 5), 0);
	//list.insert(new Vector2(4, 5), 0);
	//list.insert(new Vector2(5, 5), 0);
	//list.insert(new Vector2(5, 5), 1);

	//list.insert(new Vector2(6, 5), 10);
	//list.insert(new Vector2(7, 5), -1);
	//list.insert(new Vector2(9, 5), 6);
	//list.insert(new Vector2(8, 5), 5);

	list.remove(0);
	//list.remove(1);
	//list.remove(3);
	//list.remove(4);
	//list.remove(5);

	if (list.get(3) != nullptr)
		cout << "i = 3: x:" << list.get(3)->x << " y:" << list.get(3)->y << endl;

	cout << "size: " << list.size();

	cout << "\n\ndefault:" << endl;
	list.print(false);
	cout << "\n\ninverted:" << endl;
	list.print(true);
}

void circularListTest() {
	CircularList<Vector2*> list = CircularList<Vector2*>();

	if (list.get(0) != nullptr)
		cout << "i = 0: x:" << list.get(0)->x << " y:" << list.get(0)->y << endl;
	if (list.get(3) != nullptr)
		cout << "i = 3: x:" << list.get(3)->x << " y:" << list.get(3)->y << endl;

	list.insert(new Vector2(1, 5), 0);
	list.insert(new Vector2(2, 5), 0);
	list.insert(new Vector2(3, 5), 0);
	//list.insert(new Vector2(4, 5), 0);

	//list.insert(new Vector2(5, 5), 1);
	//list.insert(new Vector2(6, 5), 10);
	//list.insert(new Vector2(7, 5), -1);
	//list.insert(new Vector2(9, 5), 6);
	//list.insert(new Vector2(8, 5), 5);

	//list.insert(new Vector2(5, 5), 4);
	list.remove(0);
	list.remove(1);
	//list.remove(3);
	//list.remove(4);
	//list.remove(5);

	if (list.get(3) != nullptr)
		cout << "i = 3: x:" << list.get(3)->x << " y:" << list.get(3)->y << endl;

	cout << "size: " << list.size;

	list.print(2);
}

void queueTest() {
	Queue<Vector2*> queue = Queue<Vector2*>();

	if (queue.front() != nullptr)
		cout << "front: x" << queue.front()->x << " y:" << queue.front()->y << endl;
	if (queue.back() != nullptr)
		cout << "back: x" << queue.back()->x << " y:" << queue.back()->y << endl;

	queue.queue(new Vector2(1, 5));
	queue.queue(new Vector2(2, 5));
	queue.queue(new Vector2(3, 5));
	queue.queue(new Vector2(4, 5));
	//queue.queue(new Vector2(5, 5));

	//queue.dequeue();
	//queue.dequeue();
	//queue.dequeue();
	//queue.dequeue();
	//queue.dequeue();

	if (queue.front() != nullptr)
		cout << "front: x" << queue.front()->x << " y:" << queue.front()->y << endl;
	if (queue.back() != nullptr)
		cout << "back: x" << queue.back()->x << " y:" << queue.back()->y << endl;

	cout << "size: " << queue.size();

	queue.print();
}

void stackTest() {
	Stack<Vector2*> stack = Stack<Vector2*>();

	if (stack.top() != nullptr)
		cout << "front: x" << stack.top()->x << " y:" << stack.top()->y << endl;
	if (stack.bottom() != nullptr)
		cout << "back: x" << stack.bottom()->x << " y:" << stack.bottom()->y << endl;

	stack.push(new Vector2(1, 5));
	stack.push(new Vector2(2, 5));
	stack.push(new Vector2(3, 5));
	stack.push(new Vector2(4, 5));
	stack.push(new Vector2(5, 5));

	stack.pop();
	stack.pop();
	//stack.pop();
	//stack.pop();
	//stack.pop();

	if (stack.top() != nullptr)
		cout << "front: x" << stack.top()->x << " y:" << stack.top()->y << endl;
	if (stack.bottom() != nullptr)
		cout << "back: x" << stack.bottom()->x << " y:" << stack.bottom()->y << endl;

	cout << "size: " << stack.size();

	stack.print();
}

void hashtableTest() {
	// testa todos os tipos numéricos: int, short, long, float, double, bool etc
	const int t = 5;
	Hashtable<int, string, t> ht = Hashtable<int, string, t>();
	ht.put(5, "5");
	ht.put(50, "50");
	ht.put(0, "0");
	ht.put(8, "8");
	ht.put(999999, "999999");
	ht.put(50, "50novo");
	cout << ht.remove(10) << endl;
	cout << ht.remove(50) << endl;
	for (int i = 0; i < t; i++) {
		if (ht.data[i]) {
			cout << "p["<<i<<"]:"<< ht.data[i]->value << endl;
		}
	}
	string* d5 = ht.get(5);
	if (d5) cout << *d5 <<endl;
	string* d6 = ht.get(55);
	if (d6) cout << *d6 << endl;
	string* d7 = ht.get(65465);
	if (d7) cout << *d7 << endl;
	string* d8 = ht.get(1);
	if (d8) cout << *d8 << endl;

	// testa string e const char*
	//const int t = 5;
	//Hashtable<const char*, string, t> ht = Hashtable<const char*, string, t>();
	//ht.put("numero 5", "5");
	//ht.put("numero 50", "50");
	//ht.put("numero 0", "0");
	//ht.put("numero 8", "8");
	//ht.put("numero 999999", "999999");
	//ht.put("numero 50", "50novo");
	//cout << ht.remove("numero 10") << endl;
	//cout << ht.remove("numero 50") << endl;
	//for (int i = 0; i < t; i++) {
	//	if (ht.data[i]) {
	//		cout << "p[" << i << "]:" << ht.data[i]->value << endl;
	//	}
	//}
	//string* d5 = ht.get("numero 5");
	//if (d5) cout << *d5 <<endl;
	//string* d6 = ht.get("numero 55");
	//if (d6) cout << *d6 << endl;
	//string* d7 = ht.get("numero 65465");
	//if (d7) cout << *d7 << endl;
	//string* d8 = ht.get("numero 1");
	//if (d8) cout << *d8 << endl;

	// testa char
	//const int t = 5;
	//Hashtable<char, string, t> ht = Hashtable<char, string, t>();
	//ht.put('a', "5");
	//ht.put('b', "50");
	//ht.put('/', "0");
	//ht.put('\\', "8");
	//ht.put('\0', "999999");
	//ht.put('b', "50novo");
	//cout << ht.remove('\\') << endl;
	//cout << ht.remove('2') << endl;
	//for (int i = 0; i < t; i++) {
	//	if (ht.data[i]) {
	//		cout << "p[" << i << "]:" << ht.data[i]->value << endl;
	//	}
	//}
	//string* d5 = ht.get('a');
	//if (d5) cout << *d5 << endl;
	//string* d6 = ht.get('*');
	//if (d6) cout << *d6 << endl;
	//string* d7 = ht.get('@');
	//if (d7) cout << *d7 << endl;
	//string* d8 = ht.get(' ');
	//if (d8) cout << *d8 << endl;
}

void binarySearchTreeTest() {
	BinarySearchTree<string> bst = BinarySearchTree<string>();
	bst.insert(new Node<string>(500, "0"));
	bst.insert(new Node<string>(900, "1"));
	bst.insert(new Node<string>(490, "2"));
	bst.insert(new Node<string>(750, "3"));
	bst.insert(new Node<string>(400, "4"));
	bst.insert(new Node<string>(450, "5"));
	bst.insert(new Node<string>(600, "6"));
	bst.insert(new Node<string>(  1, "7"));
	bst.insert(new Node<string>(999, "8"));
	bst.insert(new Node<string>(495, "9"));
	bst.insert(new Node<string>(800, "10"));
	bst.print();

	cout << endl;
	if (bst.search(1))
		cout << bst.search(1)->value << " - {" << bst.search(1)->key << "}" << endl;


	cout << bst.nodeHeight(1) << "h -> 7 - {1}" << endl;
	cout << bst.nodeHeight(500) << "h -> 0 - {500}" << endl;
	cout << bst.nodeHeight(999) << "h -> 8 - {999}" << endl;
	cout << bst.nodeHeight(750) << "h -> 3 - {750}" << endl;
	cout << bst.nodeHeight(450) << "h -> 5 - {450}" << endl;

}
