#pragma once

template <typename V>
struct CircularList {
private:
	template <typename V>
	struct Element {
		V value;
		Element* next;

		Element(V value) {
			this->value = value;
			next = nullptr;
		}
	};

	Element<V> *first;

public:
	size_t size;

	CircularList() {
		first = nullptr;
		size = 0;
	}

	bool insert(V value, size_t index) {
		if (index < 0 or index > size) return false;
		if (index == 0) {
			auto toInsert = new Element<V>(value);
			toInsert->next = first;
			first = toInsert;
			size++;
			if (not first->next)
				first->next = first;
			else
				getElement(size - 1)->next = first;
			return true;
		}
		auto current = first;
		for (size_t i = 0; i < index - 1; i++)
			current = current->next;
		auto toInsert = new Element<V>(value);
		toInsert->next = current->next;
		current->next = toInsert;
		if (not toInsert->next)
			toInsert->next = first;
		size++;
		return true;
	}

	bool remove(size_t index) {
		if (not first or index < 0 or index >= size) return false;
		if (index == 0) {
			auto toDelete = first;
			first = toDelete->next;
			delete toDelete;
			size--;
			if (size > 0) {
				if (not first->next)
					first->next = first;
				else
					getElement(size - 1)->next = first;
			} else first = nullptr;
			return true;
		}
		auto current = first;
		for (size_t i = 0; i < index - 1; i++)
			current = current->next;
		auto toRemove = current->next;
		current->next = toRemove->next;
		if (not current->next)
			current->next = first;
		size--;
		delete toRemove;
		return true;
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

	void print(size_t r) {
		auto current = first;
		for (auto i = 0; i < size * r; i++) {
			printData(current->value);
			current = current->next;
		}
	}

private:
	Element<V>* getElement(size_t index) {
		if (not first or index < 0 or index >= size) return nullptr;
		auto current = first;
		for (size_t i = 0; i < index; i++)
			current = current->next;
		return current;
	}
};
