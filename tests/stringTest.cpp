#include <notPacker/notPacker.hpp>
#include <cassert>
#include <cstddef>
#include <string>
#include <vector>
#include <print>

int main() {
	huffman::notPacker packer;

	// TíTulos de cada subTest.
	std::vector<std::string> tests = {
		"Texto normal",
		"Caracter repetido",
		"Un solo caracter",
		"Cadena vacía",
		"Symbolos \"raros\""
	};

	// Entrada de datos.
	std::vector<std::string> input = {
		"La compresión en mejor con C++ que con Python",
		"zzzzzzzzzzzzzzzz",
		"X",
		"",
		"Linea 1\nLinea 2\t@#&!"
	};

	// Verificar, por sí acaso, que haya igual cantidad de test y entradas.
	assert(tests.size() == input.size());

	// Realizar el test.
	std::println("====================================");
	std::println("    < TEST 1: STRING -> STRING >    ");
	std::println("====================================");

	for(std::size_t i = 0; i < input.size(); ++i) {
		std::string encoded = packer.encode(input[i]);
		std::string decoded = packer.decode(encoded);

		assert(input[i] == decoded);

		std::println("[OK] String #{}.", i);
    	std::println("     Bytes originales: {}", input[i].size());
    	std::println("     Bytes generados:   {}", (encoded.size() + 7) / 8);
	}

	return 0;
}

