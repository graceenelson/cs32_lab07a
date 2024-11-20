// WordCount.cpp

#include <unordered_set>
#include <sstream>
#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int total = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		for (const auto& pair : table[i]) {
            total+= pair.second;
        }	
	}
	return total;
}

int WordCount::getNumUniqueWords() const {
    std::unordered_set<std::string> uniqueWordsSet;

    for (size_t i = 0; i < CAPACITY; i++) {
        for (const auto& pair : table[i]) {
            uniqueWordsSet.insert(pair.first);
        }
    }
    
    return uniqueWordsSet.size(); 
}

int WordCount::getWordCount(std::string word) const {
    word = makeValidWord(word);
    
	if (word.empty()){
		return 0;
	}
	
	else {
		size_t index = hash(word);

    	for (const auto& pair : table[index]) {
        	if (pair.first == word) {
            	return pair.second;
        	}
    	}
	}
    return 0;
}
	
int WordCount::incrWordCount(std::string word) {
    word = makeValidWord(word);
    if (word.empty()) return 0;

    size_t idx = hash(word);

    for (auto& pair : table[idx]) {
        if (pair.first == word) {
            pair.second++;
            return pair.second;
        }
    }

    table[idx].emplace_back(word, 1);
    return 1;
}

int WordCount::decrWordCount(std::string word) {
    word = makeValidWord(word);
    if (word.empty()){
        return -1;
    }

    size_t index = hash(word);

    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == word) {
            if (it->second > 1) {
                return --(it->second);
            } else {
                table[index].erase(it);
                return 0;
            }
        }
    }

    return -1; 
}

bool WordCount::isWordChar(char c) {
	return std::isalpha(c);
}

std::string WordCount::makeValidWord(std::string word) {
    std::string validWord;

    for (size_t i = 0; i < word.size(); i++) {
        char c = word[i];
        if (isWordChar(c) || ((c == '-' || c == '\'')&&(i > 0 && i < word.size() - 1) && (isWordChar(word[i - 1]) && isWordChar(word[i + 1])))) {
            if(c == '-'){
                validWord += '-';
            } else if (c == '\''){
                validWord += '\'';
            } else {
                validWord += std::tolower(c);
            }
        }
    }

    return validWord;
}

void WordCount::dumpWordsSortedByWord(std::ostream& out) const {
    std::vector<std::pair<std::string, int>> sorted;
    for (size_t i = 0; i < CAPACITY; i++) {
        for (const auto& pair : table[i]) {
            sorted.emplace_back(pair.first, pair.second);
        }
    }

    for (size_t i = 0; i < sorted.size(); ++i) {
        for (size_t j = 0; j < sorted.size() - 1 - i; ++j) {
            if (sorted[j].first > sorted[j + 1].first) {
                std::swap(sorted[j], sorted[j + 1]);
            }
        }
    }

    for (const auto& wordCount : sorted) {
        out << wordCount.first << "," << wordCount.second << "\n";
    }
}

void WordCount::dumpWordsSortedByOccurence(std::ostream& out) const {
    std::vector<std::pair<std::string, int>> sorted;

    for (size_t i = 0; i < CAPACITY; i++) {
        for (const auto& pair : table[i]) {
            sorted.emplace_back(pair.first, pair.second);
        }
    }

    for (size_t i = 0; i < sorted.size(); ++i) {
        for (size_t j = 0; j < sorted.size() - 1 - i; ++j) {
            const auto& a = sorted[j];
            const auto& b = sorted[j + 1];
            if (a.second > b.second || (a.second == b.second && a.first > b.first)) {
                std::swap(sorted[j], sorted[j + 1]);
            }
        }
    }

    for (const auto& wordCount : sorted) {
        out << wordCount.first << "," << wordCount.second << "\n";
    }
}

void WordCount::addAllWords(std::string text) {
    std::istringstream stream(text);
    std::string word;

    while (stream >> word) {
        incrWordCount(word);
    }
}