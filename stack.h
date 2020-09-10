#pragma once

template <typename V>
class Stack {
private:
	template <typename V>
	class Element {
	public:
		V value;
		Element* next;

		Element(V value) {
			this->value = value;
			next = nullptr;
		}
	};

	Element<V>* first;

public:
	Stack() {
		first = nullptr;
	}

	// Insere o dado no topo da pilha.
	void push(V value) {
		auto toInsert = new Element<V>(value);
		if (not first) {
			first = toInsert;
		} else {
			auto current = first;
			while (current->next)
				current = current->next;
			current->next = toInsert;
		}
	}

	// Remove o dado do topo da pilha.
	bool pop() {
		if (first) {
			Element<V>* toDelete;
			if (not first->next) {
				toDelete = first;
				first = nullptr;
				delete toDelete;
				return true;
			}
			auto current = first;
			while (current->next->next)
				current = current->next;
			toDelete = current->next;
			current->next = nullptr;
			delete toDelete;
			return true;
		}
		return false;
	}

	// Retorna o dado do topo da pilha.
	V top() {
		auto e = lastElement();
		return e ? e->value : nullptr;
	}

	// Retorna o dado de baixo da pilha (pode ser q a pilha desmorone).
	V bottom() {
		return first ? first->value : nullptr;
	}

	// Retorna o tamanho da pilha.
	size_t size() {
		size_t counter = 0;
		auto current = first;
		while (true) {
			if (not current) return counter;
			current = current->next;
			counter++;
		}
	}

	bool exists(V value) {
		auto current = first;
		while (current) {
			if (current->value == value) return true;
			current = current->next;
		}
		return false;
	}

	// Imprime a pilha.
	void print() {
		auto current = first;
		while (current) {
			printData(current->value);
			current = current->next;
		}
	}

private:
	Element<V>* lastElement() {
		if (not first) return nullptr;
		auto current = first;
		while (current->next)
			current = current->next;
		return current;
	}
};
