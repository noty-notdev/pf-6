#pragma once

#include <cstdint>

namespace huffman {
	struct Node {
		/// Valor del caracter del nodo.
		std::uint8_t symbol;
		/// Frecuencia de aparición.
		std::uint32_t frequency;

		/// "Hermanos" del nodo.
		Node *left, *right;

		Node(std::uint8_t _symbol, std::uint32_t _frequency) :
			 symbol(_symbol), frequency(_frequency), left(nullptr), right(nullptr) {}

		Node(Node* _left, Node* _right) :
			symbol(0), frequency(_left->frequency + _right->frequency), left(_left), right(_right) {}

		~Node() {
			delete left;
			delete right;
		}

		bool isLeaf() const noexcept {
			return !left && !right;
		}
	};
}

