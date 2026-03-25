#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Resultado{
    string pattern;
    int freqNormal;
    int freqInv;
};





int CountPattern(string text,string pattern){ // Conta quantas vezes um padrão de nucleotídeos se repete em uma string de uma fita de DNA
    int count = 0;

    for (int i = 0; i <= text.length() - pattern.length();i++){
        if (text.substr(i, pattern.length()) == pattern){
            count++;
        }

    }

    return count;
}


string ReversePattern(const string& pattern){ // Obtém o complemento do padrão
    string pattern_bar = "";
    for (int i = pattern.length() - 1;i >=0; i--){
        if (pattern[i] == 'a') pattern_bar += 't';
        else if (pattern[i] == 't') pattern_bar += 'a';
        else if (pattern[i] == 'g') pattern_bar += 'c';
        else if (pattern[i] == 'c') pattern_bar += 'g';
    }

    return pattern_bar;
}

vector<Resultado> FindPattern(const string& text,int k ){ // Encontra os padrões mais frequentes que se repetem dentro de uma fita de DNA, (mais frequentes ao menos frequente)
    vector<string> patterns;
    vector<int> count_pattern(text.length() - k + 1, 0); 

    
    for (int i = 0; i <= text.length() - k; i++){
        string pattern = text.substr(i, k);
        string reverse_pattern = ReversePattern(pattern);
        count_pattern[i] = CountPattern(text, pattern) + CountPattern(text, reverse_pattern);
        

    }

    int MaxCount = *max_element(count_pattern.begin(), count_pattern.end());

    vector<Resultado> resultado;
    vector<string> padroes_adc;
    
    for (int i = 0; i <= text.length() - k; i++){
        if (count_pattern[i] == MaxCount){
            string pattern = text.substr(i,k);

            bool achou_original = find(padroes_adc.begin(), padroes_adc.end(), pattern) != padroes_adc.end();
            
    
            bool achou_reverso = find(padroes_adc.begin(), padroes_adc.end(), ReversePattern(pattern)) != padroes_adc.end();

            if (!achou_original && !achou_reverso){

                padroes_adc.push_back(pattern);
                

                    Resultado temp;
                    temp.pattern = pattern;
                    temp.freqNormal = CountPattern(text, pattern);
                    temp.freqInv = CountPattern(text,ReversePattern(pattern));

                    resultado.push_back(temp);
                
            }
        }
    }


    return resultado;


}


void showresults(vector<Resultado> resultado){
    for (int i = 0; i < resultado.size(); i++){
        cout << "Padrão: "<<resultado[i].pattern << endl;
        cout << "Frequência normal: "<< resultado[i].freqNormal << endl;
        cout << "Frequência do complemento: "<<resultado[i].freqInv << endl;
        cout << " " << endl;
    }
}



int main(){
    string test1 = "atcaatgatcaacgtaagcttctaagcatgatcaaggtgctcacacagtttatccacaacctgagtggatgacatcaagataggtcgttgtatctccttcctctcgtactctcatgaccacggaaagatgatcaagagaggatgatttcttggccatatcgcaatgaatacttgtgacttgtgcttccaattgacatcttcagcgccatattgcgctggccaaggtgacggagcgggattacgaaagcatgatcatggctgttgttctgtttatcttgttttgactgagacttgttaggatagacggtttttcatcactgactagccaaagccttactctgcctgacatcgaccgtaaattgataatgaatttacatgcttccgcgacgatttacctcttgatcatcgatccgattgaagatcttcaattgttaattctcttgcctcgactcatagccatgatgagctcttgatcatgtttccttaaccctctattttttacggaagaatgatcaagctgctgctcttgatcatcgtttc";
    int k1 = 9;

    vector<Resultado> result1 = FindPattern(test1, k1);
 
    showresults(result1);

    cout << "Teste 2: " << endl;

    string test2 = "aactctatacctcctttttgtcgaatttgtgtgatttatagagaaaatcttattaactgaaactaaaatggtaggtttggtggtaggttttgtgtacattttgtagtatctgatttttaattacataccgtatattgtattaaattgacgaacaattgcatggaattgaatatatgcaaaacaaacctaccaccaaactctgtattgaccattttaggacaacttcagggtggtaggtttctgaagctctcatcaatagactattttagtctttacaaacaatattaccgttcagattcaagattctacaacgctgttttaatgggcgttgcagaaaacttaccacctaaaatccagtatccaagccgatttcagagaaacctaccacttacctaccacttacctaccacccgggtggtaagttgcagacattattaaaaacctcatcagaagcttgttcaaaaatttcaatactcgaaacctaccacctgcgtcccctattatttactactactaataatagcagtataattgatctga";

    vector<Resultado> result2 = FindPattern(test2, k1);

    showresults(result2);




}