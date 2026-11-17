#include <notPacker/notPacker.hpp>
#include <sstream>
#include <string>

using namespace huffman;

std::unordered_map<std::uint8_t, std::uint32_t> notPacker::getFrecuencies(std::istream &input) {
	std::unordered_map<std::uint8_t, std::uint32_t> frequencies;

	char c;
	while(input.get(c))
		frequencies[static_cast<std::uint8_t>(c)]++;

	return frequencies;
}


void notPacker::encode(std::istream &input, std::ostream &output) {
	// Obtener la frecuencia de los valores.
	auto frequencies = getFrecuencies(input);
	if(frequencies.empty()) return;

	// Construir el árbol de Huffman.
	tree.buildTree(frequencies);

	// Se reinicia el flujo de datos y se apunta al inicio del mismo.
	input.clear();
	input.seekg(0, std::ios::beg);

	// Codificar el flujo.
	char c;
	while(input.get(c))
		output << tree.getCode(static_cast<std::uint8_t>(c));
}

void notPacker::decode(std::istream &input, std::ostream &output) {
	Node* root = tree.getRoot();
	if(!root) return;

	Node* current = root;
	char c;

	// Caso: el nodo es una hoja.
	if(root->isLeaf()) {
		while(input.get(c))
			output.put(static_cast<char>(root->symbol));
		return;
	}

	// Decodificar el flujo.
	while(input.get(c)) {
		if(c == '0')		current = current->left;
		else if(c == '1')	current = current->right;

		if(current && current->isLeaf()) {
			output.put(static_cast<char>(current->symbol));
			current = root;
		}
	}
}


std::string notPacker::encode(std::istream &input) {
	std::ostringstream output;

	// Codificar flujo.
	encode(input, output);

	return output.str();
}

std::string notPacker::decode(std::istream &input) {
	std::ostringstream output;

	// Codificar flujo.
	decode(input, output);

	return output.str();
}


std::string notPacker::encode(std::string &data) {
	// Convertir el texto en un flujo de datos.
	std::istringstream input(data);
	std::ostringstream output;

	// Codificar el texto.
	encode(input, output);
	
	return output.str();
}

std::string notPacker::decode(std::string &data) {
	// Convertir el texto en un flujo de datos.
	std::istringstream input(data);
	std::ostringstream output;

	// Decodificar el texto.
	decode(input, output);
	
	return output.str();
}

