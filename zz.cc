#include <iostream>
#include <string>

// Placeholder compress function (implement your Huffman compress logic here)
void compress(const std::string& inputFile, const std::string& outputFile) {
    std::cout << "Compressing file: " << inputFile << " -> " << outputFile << "\n";
    // TODO: Your Huffman compression code here
    std::cout << "Compression complete!\n";
}

// Placeholder decompress function (implement your Huffman decompress logic here)
void decompress(const std::string& inputFile, const std::string& outputFile) {
    std::cout << "Decompressing file: " << inputFile << " -> " << outputFile << "\n";
    // TODO: Your Huffman decompression code here
    std::cout << "Decompression complete!\n";
}

int main() {
    int choice;
    do {
        std::cout << "\n=== Huffman Compression CLI ===\n";
        std::cout << "1. Compress a file\n2. Decompress a file\n3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1 || choice == 2) {
            std::string inputFile, outputFile;
            std::cout << "Enter input filename: ";
            std::cin >> inputFile;
            std::cout << "Enter output filename: ";
            std::cin >> outputFile;

            if (choice == 1) {
                compress(inputFile, outputFile);
            } else {
                decompress(inputFile, outputFile);
            }
        } else if (choice == 3) {
            std::cout << "Exiting program.\n";
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
