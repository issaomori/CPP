#include "BitCoinExchange.hpp"

#include "BitCoinExchange.hpp" // Inclua o cabeçalho que declara a classe BitCoinExchange

// int main(int argc, char **argv) {
//     if (argc != 2) {
//         std::cerr << "Usage: " << argv[0] << " input.txt" << std::endl;
//         return 1;
//     }

//     BitCoinExchange exchange; // Crie uma instância da classe BitCoinExchange

//     // Carregue os dados do arquivo CSV "data.csv"
//     if (!exchange.parseData()) {
//         std::cerr << "Error: Could not load data from data.csv" << std::endl;
//         return 1;
//     }

//     std::ifstream inputFile(argv[1]);
//     if (!inputFile.is_open()) {
//         std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
//         return 1;
//     }

//     std::string line;
//     int lineCount = 0;

//     while (std::getline(inputFile, line)) {
//         lineCount++;
//         if (lineCount == 1) {
//             continue;
//         }

//         // Chame a função para calcular o valor com base na linha atual
//         exchange.calculate(
//     }

//     inputFile.close();

//     return 0;
// }

int main(int argc, char** argv) {
    std::map<std::string, float> csv;

    BitCoinExchange exchange;
    if (argc != 2) {
        std::cout << "Wrong use of this program. Check subject" << std::endl;
        return (1);
    }
    std::ifstream file;
    if (exchange.openFile(file, argv[1]) != 0) {
        std::cout << "Could not open " << argv[1] << std::endl;
        return (1);
    }
    if (!exchange.readCSVData(csv))
        return (1);
    exchange.calculate(csv, argv[1]);
    return (0);
}
