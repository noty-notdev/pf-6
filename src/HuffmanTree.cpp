
#include <notPacker/HuffmanTree.hpp>
#include <vector>
#include <queue>

using namespace huffman;

void HuffmanTree::generateCodes(Node* current, std::string code) {
	if(!current) return;

	if(current->isLeaf())
		symbolCodes[current->symbol] = code.empty() ? "0" : code;

	generateCodes(current->left, code + "0");
	generateCodes(current->right, code + "1");
}

void HuffmanTree::cleanTree() {
	delete root;
	root = nullptr;
	symbolCodes.clear();
}


void HuffmanTree::buildTree(std::unordered_map<std::uint8_t, std::uint32_t>& frequencies) {
	cleanTree();
	if(frequencies.empty()) return;

	std::priority_queue<Node*, std::vector<Node*>, NodeComparator> minHeap;
	for(auto& par : frequencies)
		minHeap.push(new Node(par.first, par.second));

	while(minHeap.size() > 1) {
		Node* left  = minHeap.top(); minHeap.pop();
		Node* right = minHeap.top(); minHeap.pop();
	
		minHeap.push(new Node(left, right));
	}

	root = minHeap.top();
	generateCodes(root, "");
}


