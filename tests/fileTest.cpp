#include <notPacker/notPacker.hpp>
#include <cassert>
#include <fstream>
#include <sstream>
#include <string>
#include <print>

int main() {
	huffman::notPacker packer;

	// Relativo al archivo.
	const std::string filePath = "temp.txt";

	const std::string contenido =
		"Archivo de prueba para Huffman.\n"
        "Incluye multiples lineas, espacios   y simbolos: @#$%&*!\n"
        "1234567890 - Fin del archivo.";

	// Llenar/Crear archivo con el contenido;
	{
		std::ofstream outFile(filePath, std::ios::binary);
		assert(outFile.is_open());
		outFile << contenido;
	}

	// Realizar test.
	std::println("====================================");
	std::println("    < TEST 2: FILES  -> STRING >    ");
	std::println("====================================");

	std::ifstream inFile(filePath, std::ios::binary);
	assert(inFile.is_open());

	std::string encoded = packer.encode(inFile);
	inFile.close();

	std::istringstream strInStream(encoded);
	std::string decoded = packer.decode(strInStream);

	assert(contenido == decoded);

	std::println("[OK] Lectura y compresion desde archivo.");
    std::println("     Bytes originales: {}", contenido.size());
    std::println("     Bytes generados:   {}", (encoded.size() + 7) / 8);

	// Eliminar archivo temporal.
	std::remove(filePath.c_str());
	
	return 0;
}

