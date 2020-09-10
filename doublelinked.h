#pragma once

template <typename V>
class DoubleLinkedList {
private:
	template <typename V>
	class Element {
	public:
		V value;
		Element* next;
		Element* prev;

		Element(V value) {
			this->value = value;
			next = nullptr;
			prev = nullptr;
		}
	};

	Element<V>* first;
	Element<V>* last;

public:
	DoubleLinkedList() {
		first = nullptr;
		last = nullptr;
	}

	// Insere na lista na posição indicada.
	bool insert(V value, size_t index) {
		if (index < 0 or index > size()) return false;
		if (index == 0) {
			auto toInsert = new Element<V>(value);
			toInsert->next = first;
			first = toInsert;
			if (first->next)
				first->next->prev = first;
			if (not last)
				last = first;
			return true;
		}
		auto current = first;
		size_t i = 0;
		while (current and i < index - 1) {
			current = current->next;
			i++;
		}
		if (current) {
			auto toInsert = new Element<V>(value);
			toInsert->next = current->next;
			current->next = toInsert;
			toInsert->prev = current; // aponta o prev para o anterior
			if (toInsert->next) // verifica se tem prox
				toInsert->next->prev = toInsert;
			else // senão define como last
				last = toInsert;
			return true;
		}
		return false;
	}

	// Remove da lista na posição indicada.
	bool remove(size_t index) {
		if (not first) return false;
		if (index < 0 or index >= size()) return false;
		if (index == 0) {
			auto toRemove = first;
			first = toRemove->next;
			if (not first)
				last = nullptr;
			else
				first->prev = nullptr;
			delete toRemove;
			return true;
		}
		auto current = first;
		size_t i = 0;
		while (current and i < index - 1) {
			current = current->next;
			i++;
		}
		if (current) {
			auto toRemove = current->next;
			current->next = toRemove->next;
			if (current->next)
				current->next->prev = current;
			else
				last = current;
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
			int i = 0;
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
		size_t amount = 0;
		while (current) {
			current = current->next;
			amount++;
		}
		return amount;
	}

	// Imprime a lista.
	void print(bool rev) {
		Element<V>* current;
		if (rev) current = last;
		else current = first;
		while (current) {
			printData(current->value);
			if (rev) current = current->prev;
			else current = current->next;
		}
	}
};
