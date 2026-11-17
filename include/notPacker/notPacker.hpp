#pragma once

#include "HuffmanTree.hpp"

#include <unordered_map>
#include <iostream>
#include <cstdint>
#include <string>

namespace huffman {
	class notPacker {
	private:
		/// Árbol Huffman para las operaciones.
		HuffmanTree tree;

		std::unordered_map<std::uint8_t, std::uint32_t> getFrecuencies(std::istream& input);
	
	public:
		/* Compresión y descopresión para flujos de datos. */
		void encode(std::istream& input, std::ostream& output);
		void decode(std::istream& input, std::ostream& output);

		/* Compresión y descompresión para cadenas. */
		std::string encode(std::string& data);
		std::string decode(std::string& data);
	};
}

