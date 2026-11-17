#include <iostream>
#include <notPacker/notPacker.hpp>
#include <cassert>
#include <sstream>
#include <string>
#include <print>

int main() {
	huffman::notPacker packer;

	std::string texto;

	// Realizar test.
	std::println("====================================");
	std::println("    < TEST 3: INPUT  -> STRING >    ");
	std::println("====================================");

	std::print("\nDigite un texto a comprimir: ");
	std::getline(std::cin, texto);

	std::string encoded = packer.encode(texto);

	std::istringstream strInStream(encoded);
	std::string decoded = packer.decode(strInStream);

	// Resuktados.
	std::println("Cadena compresa: {}", encoded);
	std::println("Resultado obtenido: {}", decoded);

	std::println("\nResultado {}correcto.", (decoded == texto) ? "" : "in");

	std::println("Bits originales:  {}", texto.size() * 8);
	std::println("Bits comprimidos: {}", encoded.size());

	return 0;
}

