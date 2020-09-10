#pragma once

template <typename V>
struct LinkedList {
private:
	template <typename V>
	class Element {
	public:
		V value;
		Element* next;

		Element(V value) {
			this->value = value;
			this->next = nullptr;
		}
	};

	Element<V>* first;

public:
	LinkedList() {
		first = nullptr;
	}

	// Insere na lista na posição indicada.
	bool insert(V value, size_t index) {
		if (index < 0 or index > size()) return false;
		if (index == 0) {
			auto toInsert = new Element<V>(value);
			toInsert->next = first;
			first = toInsert;
			return true;
		}
		auto current = first;
		size_t i = 0;
		while (current and i < index - 1) {
			current = current->next;
			i++;
		}
		if (current) {
			// current representa a pos anterior na lista e next a posição a ser inserida
			// cria-se o novo elemento a ser inserido
			// o next é colocado na prox pos do novo elemento
			// a pos next agora recebe o novo elemento
			auto toInsert = new Element<V>(value);
			toInsert->next = current->next;
			current->next = toInsert;
			return true;
		}
		return false;
	}

	// Remove na lista na posição indicada.
	bool remove(size_t index) {
		if (not first) return false;
		if (index < 0 or index >= size()) return false;
		if (index == 0) {
			auto toRemove = first; // o apagar recebe o inicio
			first = toRemove->next; // o incio recebe o prox do apagar
			delete toRemove; // então o apagar é deletado
			return true;
		}
		auto current = first;
		size_t i = 0;
		while (current and i < index - 1) {
			current = current->next;
			i++;
		}
		if (current) {
			auto toRemove = current->next; // o apagar recebe o cur.next
			current->next = toRemove->next; // o cur.next agora recebe o prox da lista
			delete toRemove;
			return true;
		}
		return false;
	}

	// Retorna o dado da lista na posiçãao indicada.
	V get(size_t index) {
		if (first) {
			if (index == 0)
				return first->value;
			auto current = first;
			size_t i = 0;
			while (current and i < index - 1) {
				current = current->next;
				i++;
			}
			if (current and current->next)
				return current->next->value;
		}
		return nullptr;
	}

	// Retorna a quantidade de elementos na lista.
	size_t size() {
		auto current = first;
		int size = 0;
		while (current) {
			size++;
			current = current->next;
		}
		return size;
	}

	// Imprime a lista completa.
	void print() {
		auto current = first;
		while (current) {
			printData(current->value);
			current = current->next;
		}
	}
};
