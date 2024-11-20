#include "tddFuncs.h"
#include "WordCount.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    cout << "   Testing for lab07 Original Functions:" << endl;
    WordCount testing;
    
    cout << "   Testing for Initial Case:" << endl;
    //Testing for getTotalWords() & getNumUniqueWords()
    //Initial case: when there are no words added, both values should be 0
    ASSERT_EQUALS(0, testing.getTotalWords());
    ASSERT_EQUALS(0, testing.getNumUniqueWords());

    cout << "   Testing for Adding One Element:" << endl;
    //Test Adding one element 
    //getTotalWords() & getNumUniqueWords() & incrWordCount()
    testing.incrWordCount("dogs");
    ASSERT_EQUALS(1, testing.getTotalWords());
    ASSERT_EQUALS(1, testing.getNumUniqueWords());

    cout << "   Testing for Adding Duplicate Element:" << endl;
    //Testing adding a duplicate element
    //getTotalWords() & getNumUniqueWords() & incrWordCount()
    //The total words should be two, but there should only be one unique word
    testing.incrWordCount("dogs");
    ASSERT_EQUALS(2, testing.getTotalWords());
    ASSERT_EQUALS(1, testing.getNumUniqueWords());

    cout << "   Testing for Adding a Non-Duplicate Word:" << endl;
    //Testing adding more non-duplicate words
    testing.incrWordCount("cats");
    ASSERT_EQUALS(3, testing.getTotalWords());
    ASSERT_EQUALS(2, testing.getNumUniqueWords());
    testing.incrWordCount("fish");
    ASSERT_EQUALS(4, testing.getTotalWords());
    ASSERT_EQUALS(3, testing.getNumUniqueWords());
    testing.incrWordCount("rabbit");
    ASSERT_EQUALS(5, testing.getTotalWords());
    ASSERT_EQUALS(4, testing.getNumUniqueWords());

    cout << "   Testing for Decreasing an Element:" << endl;
    //Testing for removing one element
    //getTotalWords() & getNumUniqueWords() & decrWordCount()
    testing.decrWordCount("fish");
    ASSERT_EQUALS(4, testing.getTotalWords());
    ASSERT_EQUALS(3, testing.getNumUniqueWords());

    cout << "   Testing for Decreasing a Duplicate Element:" << endl;
    //Testing for removing a duplicate element
    //getTotalWords() & getNumUniqueWords() & decrWordCount()
    testing.decrWordCount("dogs");
    ASSERT_EQUALS(3, testing.getTotalWords());
    ASSERT_EQUALS(3, testing.getNumUniqueWords());

    cout << "   Testing for Decreasing back to 0:" << endl;
    //Testing for removing back to no elements
    //getTotalWords() & getNumUniqueWords() & decrWordCount()
    testing.decrWordCount("rabbit");
    testing.decrWordCount("dogs");
    testing.decrWordCount("cats");
    ASSERT_EQUALS(0, testing.getTotalWords());
    ASSERT_EQUALS(0, testing.getNumUniqueWords());

    cout << "   Testing More Increasing Cases with Symbols:" << endl;
    //Testing for making a valid word... with "weird" cases and symbols and capitalizations
    //getTotalWords() & getNumUniqueWords() & incrWordCount()
    testing.incrWordCount("12mOnkEYs-$");
    testing.incrWordCount("Pa55ive");
    testing.incrWordCount("gr3@a?ce-ne!ls0on");
    testing.incrWordCount("ZOO-ANIMALS");
    testing.incrWordCount("hIPpOs-aNd-FLamIngoS");
    testing.incrWordCount("can't");
    testing.incrWordCount("32i-dOn't-LI#$@%^&ke-caTS");
    ASSERT_EQUALS(1, testing.getWordCount("monkeys-"));
    ASSERT_EQUALS(1, testing.getWordCount("paive"));
    ASSERT_EQUALS(1, testing.getWordCount("grace-nelson"));
    ASSERT_EQUALS(1, testing.getWordCount("zoo-animals"));
    ASSERT_EQUALS(1, testing.getWordCount("hippos-and-flamingos"));
    ASSERT_EQUALS(1, testing.getWordCount("can't"));
    ASSERT_EQUALS(1, testing.getWordCount("i-don't-like-cats"));
    ASSERT_EQUALS(7, testing.getTotalWords());
    ASSERT_EQUALS(7, testing.getNumUniqueWords());

    cout << "   Testing More Decreasing Cases with Symbols:" << endl;
    //Testing decreasing all elements that had odd symbols and capitalizations
    testing.decrWordCount("i-don't-like-cats");
    ASSERT_EQUALS(6, testing.getTotalWords());
    ASSERT_EQUALS(6, testing.getNumUniqueWords());     
    testing.decrWordCount("can't");
    ASSERT_EQUALS(5, testing.getTotalWords());
    ASSERT_EQUALS(5, testing.getNumUniqueWords());   
    testing.decrWordCount("monkeys-");
    ASSERT_EQUALS(4, testing.getTotalWords());
    ASSERT_EQUALS(4, testing.getNumUniqueWords());
    testing.decrWordCount("paive");
    ASSERT_EQUALS(3, testing.getTotalWords());
    ASSERT_EQUALS(3, testing.getNumUniqueWords());
    testing.decrWordCount("zoo-animals");
    ASSERT_EQUALS(2, testing.getTotalWords());
    ASSERT_EQUALS(2, testing.getNumUniqueWords());
    testing.decrWordCount("hippos-and-flamingos");
    ASSERT_EQUALS(1, testing.getTotalWords());
    ASSERT_EQUALS(1, testing.getNumUniqueWords());
    testing.decrWordCount("grace-nelson");
    ASSERT_EQUALS(0, testing.getTotalWords());
    ASSERT_EQUALS(0, testing.getNumUniqueWords());
}