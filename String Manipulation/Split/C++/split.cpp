#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(const string& s){
    vector<string> result;
    
    string currString = "";
    for (char c : s){
        if (c != ' '){
            currString += c;
        }
        else{
            if (currString != ""){
                result.push_back(currString);
                currString = "";
            }
        }
    }
    
    if (currString != ""){
        result.push_back(currString);
    }
    
    return result;
}

int main() {
	assert((split("Hello World") == vector<string>{"Hello", "World"}));
	assert((split("      Hello      World") == vector<string>{"Hello", "World"}));
	return 0;
}