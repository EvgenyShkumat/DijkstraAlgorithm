#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void combination(string str, int& alternation_count, int& total_count);

string output() {
	setlocale(LC_ALL, "Russian");

	ifstream fin("input.txt");
	string buf = "";
	string result = "";

	if (!fin.fail()) {
		while (!fin.eof()) {
			getline(fin, buf);
			result += buf;
		}
		fin.close();
	}
	
	int alternation_count = 0, total_count = 0    ;
	
	combination(result, alternation_count)

	return 0;
}

bool is_vowel(char symbol){
    bool vowel = false;
    if(symbol == 'у' || symbol == 'е' || symbol == 'ы' || symbol == 'а' || symbol == 'о' ||
       symbol == 'э' || symbol == 'я' || symbol == 'и'){
            vowel = true;
       }
       
    return vowel;
}

bool is_consonant(char symbol){
    bool consonant = false;
    if(!is_vowel(symbol) && symbol >= 192 && symbol <=  255) {
        consonant = true;
    }
    
    return consonant;
}

bool is_letter(char symbol){
    if(symbol >= 192 && symbol <=  255){
        return true;
    }
    return false;
}

void combination(string str, int& alternation_count, int& total_count){
    for(int i = 0; i < str.length() - 1; i++){
        if(is_vowel(s[i]) == is_vowel(s[i + 1])){
            alternation_count++;
        }
        if(is_letter(s[i]) && is_letter(s[i])){
            total_count++;
        }
    }
}
