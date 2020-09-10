#pragma once

template <typename V, int MAX_SIZE>
class StaticList {
private:
	template <typename V>
	class Element {
	public:
		V value;
	};

	Element<V> elements[MAX_SIZE];

public:
	size_t size;

public:
	StaticList() {
		size = 0;
	}
	~StaticList() {}

	// Insere o dado na posição indicada.
	bool insert(V value, size_t index) {
		if (index < 0 or index > size or
			index >= MAX_SIZE or size >= MAX_SIZE)
			return false;
		for (size_t i = size; i > index; i--)
			elements[i] = elements[i - 1];
		elements[index].value = value;
		size++;
		return true;
	}

	// Remove o dado na posição indicada.
	bool remove(size_t index) {
		if (index < 0 or index >= size or
			index >= MAX_SIZE)
			return false;
		for (size_t i = index; i < size; i++)
			elements[i] = elements[i + 1];
		size--;
		return true;
	}

	// Retorna o dado da posição informada.
	V get(size_t index) {
		if (index >= 0 and index < size)
			return elements[index].value;
		return nullptr;
	}

	// Verifica de o dado pertence à lista.
	bool existis(V value) {
		for (size_t i = 0; i < size; i++)
			if (elements[i].value == value)
				return true;
		return false;
	}

	// Retorna o índice do dado.
	size_t indexOf(V value) {
		for (size_t i = 0; i < size; i++)
			if (elements[i].value == value)
				return i;
		return -1;
	}

	// Imprime a lista completa.
	void print() {
		for (size_t i = 0; i < size; i++)
			printData(elements[i].value);
	}
};
