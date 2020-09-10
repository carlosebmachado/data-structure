#pragma once

template <typename V>
class Queue {
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
	Queue() {
		first = nullptr;
	}

	// Insere o dado no final da fila.
	void queue(V value) {
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

	// Remove o dado do início da fila.
	bool dequeue() {
		if (first) {
			auto toDelete = first;
			first = toDelete->next;
			delete toDelete;
			return true;
		}
		return false;
	}

	// Retorna o dado do início da fila.
	V front() {
		return first ? first->value : nullptr;
	}

	// Retorna o dado do fim da fila.
	V back() {
		auto e = lastElement();
		return e ? e->value : nullptr;
	}

	bool exists(V value) {
		auto current = first;
		while (current) {
			if (current->value == value) return true;
			current = current->next;
		}
		return false;
	}

	// Retorna o tamanho da fila.
	size_t size() {
		size_t counter = 0;
		auto current = first;
		while (true) {
			if (not current)
				return counter;
			current = current->next;
			counter++;
		}
	}

	// Imprime a lista.
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
