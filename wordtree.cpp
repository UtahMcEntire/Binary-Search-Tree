// Utah McEntire
// CSCI 3110-001
// Project #6
// Due: 11/07/19 
// The program will open and read an input file (named input.txt), and
// build a binary search tree of the words and their counts

#include<iostream>
#include<string>
#include<algorithm>
#include "wordtree.h"
using std::cout;
using std::endl;
using std::string;

WordTree::WordTree(){
	root=NULL;
}

// PUBLIC FUNCTIONS
void WordTree::addWord(string wordInput){
	std::transform(wordInput.begin(), wordInput.end(), wordInput.begin(), ::tolower);
	addWord(root, wordInput);	//convert word to lowercase then send to addWord
}

void WordTree::findWord(string wordSearch){
	int wordCount=0;
	bool wordFound=false;
	TreeNode *node=root;
	
	while(node!=NULL && !wordFound){
		if (node->value > wordSearch) 			//word searching for is less than current node
			node=node->left;					//iterative go left
		else if (node->value < wordSearch)		//word searching for is greater than current node
			node=node->right;					//iterative go right
		else if (node->value == wordSearch){ 	//word has been found
			wordFound=true;
			cout<<"The word '"<<wordSearch<<"' occurs "<<node->count<<" time(s) in the text.\n\n";
		}
	}
	if(!wordFound)
		cout<<"The word '"<<wordSearch<<"' was not found in the text.\n\n";
}

void WordTree::getCounts(int occurrences){
	int count=0;
	getCounts(root, occurrences, count);
	cout<<count<<" nodes had words with "<<occurrences<<" or more occurrence(s).\n\n";
}

// PRIVATE RECURSIVE FUNCTIONS
void WordTree::addWord(TreeNode *& node, string wordInput){
	if(!node){								//if node is null
		node=new TreeNode;					//create node and insert values
		node->value=wordInput;
		node->count=1;
		node->left=NULL;
		node->right=NULL;
	}
	else if (node->value > wordInput){		//if word to be added is less than
		addWord(node->left, wordInput); 	//recursive go left
	}
	else if (node->value < wordInput){		//if word to be added is greater than
		addWord(node->right, wordInput); 	//recurseive go right
	}
	else if (wordInput == node->value){		//clone value found, add 1 to its count
		node->count++;
	}
}

void WordTree::deleteSubTree(TreeNode *node){
	if(node){
		deleteSubTree(node->left);
		deleteSubTree(node->right);
		delete node;
	}
}

void WordTree::getCounts(TreeNode *node, int occurrences, int& count) const{
	if(node){	
		getCounts(node->left, occurrences, count);
		if(node->count>=occurrences){
			cout<<node->value<<"("<<node->count<<")\n";
			count++;
		}
		getCounts(node->right, occurrences, count);
	}
}

WordTree::~WordTree(){
	deleteSubTree(root);
}