#include "BitCoinExchange.hpp"

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

// int main(int argc, char **argv) {
//     BitCoinExchange exchange;
//     std::map<std::string, float> csv;

//     if (argc != 2) {
//         std::cout << "Wrong use of this program. Check subject" << std::endl;
//         return 1;
//     }
//     if (!exchange.canOpen(argv[1])) {
//         std::cout << "Could not open " << argv[1] << std::endl;
//         return 1;
//     }
//     if (!exchange.parseMap(argv[1], csv))
//         return 1;

//     exchange.calculate(argv[1]);
//     return 0;
// }


int main(int ac, char **av)
{
    (void)av;
    if (ac != 2)
    {
        std::cout << "Usage: ./bitcoin [filename]" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    exchange.LoadData();
    exchange.InputHandler(av[1]);
    return 0;
}