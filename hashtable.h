#pragma once

template <typename K, typename V, int MAX_SIZE>
class Hashtable {
public:
	template <typename K, typename V>
	class Element {
	public:
		K key;
		V value;

		Element(K key, V value) {
			this->key = key;
			this->value = value;
		}
	};

	Element<K, V>* data[MAX_SIZE];
	int size;

	Hashtable() {
		size = 0;
		for (size_t i = 0; i < MAX_SIZE; i++)
			data[i] = nullptr;
	}

	bool put(K key, V value) {
		if (size >= MAX_SIZE) return false;
		auto toInsert = new Element<K, V>(key, value);
		int h = hash(key);
		while (data[h]) {
			if (data[h]->key == key) {
				data[h]->value = value;
				return true;
			}
			h = probing(h);
		}
		data[h] = toInsert;
		size++;
		return true;
	}

	bool remove(K key) {
		if (size == 0) return false;
		int h = hash(key);
		size_t count = 0;
		while (not data[h] or data[h] and data[h]->key != key) {
			h = probing(h);
			if (count++ > MAX_SIZE) return false;
		}
		auto toDelete = data[h];
		data[h] = nullptr;
		delete toDelete;
		return true;
	}

	V* get(K key) {
		if (size == 0) return nullptr;
		int h = hash(key);
		size_t count = 0;
		while (not data[h] or data[h] and data[h]->key != key) {
			h = probing(h);
			if (count++ > MAX_SIZE) return nullptr;
		}
		if (data[h]) return &data[h]->value;
		return nullptr;
	}

	// metodo linear
	int probing(int oh) {
		return ((oh + 1) & 0x7FFFFFFF) % MAX_SIZE;
	}

private:
	// metodo multiplicação
	// cria os hashs de todos os tipos numéricos:
	// int, short, long, float, double, bool, char etc
	int hash(double key) {
		const double A = 0.6180339666;
		double h = key * A;
		h = h - (int)h;
		return (int)(MAX_SIZE * h);
	}

	// cria a hash das strings:
	// std::string e const char*
	int hash(std::string key) {
		int h = 7;
		for (size_t i = 0; i < key.size(); i++) {
			h = h * 31 + key.at(i);
		}
		return (h & 0x7FFFFFFF) % MAX_SIZE;
	}
};
