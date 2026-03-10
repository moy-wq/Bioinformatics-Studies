#include <iostream>
#include <vector>
#include <string>

// Implementação de um anotador de padrões para uma sequência de uma fita de DNA
// protótipo para uma função de encontrar o oriC da sequência


std::vector<int> findPattern(const std::string& pattern, const std::string& GenomeSequence){
    std::vector<int> Positions;
    if (pattern.empty()) {return Positions;};
    
    for (int i=0; i <= GenomeSequence.length(); i++){
        if (GenomeSequence.substr(i, pattern.length()) == pattern){
            Positions.push_back(i);
        }
    }
    return Positions;
}

int main(){
    std::string Genome = "GATATATGCATATACTT";
    std::string pattern = "ATAT";


    std::vector<int> resultados = findPattern(pattern, Genome);

    std::cout << "Padrao encontrado nos indices: ";
    for (int pos : resultados) {
        std::cout << pos << " ";
    }

    std::cout << std::endl;
    return 0;
}
