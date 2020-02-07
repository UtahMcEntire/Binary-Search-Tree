// Utah McEntire
// CSCI 3110-001
// Project #6
// Due: 11/07/19 
// The program will open and read an input file (named input.txt), and
// build a binary search tree of the words and their counts

#include<iostream>
#include<string>
#include<fstream>
#include<cassert>
#include "wordtree.h"
using std::cout;
using std::endl;
using std::string;

int main(){
	int occurrences=0;
	string request, wordSearch, wordInput;
	
	std::ifstream myIn;
	std::ifstream myQ;
	myQ.open("queries.txt");
	myIn.open("input.txt");
	assert(myIn);
	assert(myQ);

	WordTree mytree;				//instantiate tree
	while(myIn){					//insert tree values
		myIn>>wordInput;
		mytree.addWord(wordInput);
	}
	cout<<"Word tree built and loaded\n\n";
	
	while(myQ>>request){
		if(request=="C"){ 			//if request is get words with minimum counts
			myQ>>occurrences;
			cout<<"Finding all words with "<<occurrences<<" or more occurrences:\n";
			mytree.getCounts(occurrences);
		}
		else if(request=="F"){		//else if request is count specific word
			myQ>>wordSearch;
			cout<<"Searching for occurrences of the word '"<<wordSearch<<"'\n";
			mytree.findWord(wordSearch);
		}
	}

	myIn.close();
	myQ.close();
	return 0;
}