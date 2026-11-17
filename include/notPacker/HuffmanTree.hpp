#pragma once

#include "Node.hpp"

#include <unordered_map>
#include <cstdint>
#include <string>

namespace huffman {
	class HuffmanTree {
	private:
		/// Raíz del árbol.
		Node* root;
		/// Códigos de los carácteres en el texto.
		std::unordered_map<std::uint8_t, std::string> symbolCodes;

		struct NodeComparator {
			bool operator()(Node* a, Node* b) {
				return a->frequency > b->frequency;
			}
		};

		/// Genera los códigos de los carácteres.
		void generateCodes(Node* current, std::string code);
		
		/// Limpiar y volver al árbol por defecto.
		void cleanTree();

	public:
		HuffmanTree() : root(nullptr) {}

		~HuffmanTree() {
			cleanTree();
		}

		/// Construye el árbol a partir de un texto.
		void buildTree(std::unordered_map<std::uint8_t, std::uint32_t>& frequencies);

		/// Getter de la raíz.
		Node* getRoot() const noexcept {
			return root;
		}

		/// Devuelve el código del símbolo c.
		std::string getCode(std::uint8_t s) const {
			return symbolCodes.at(s);
		}
	};
}

