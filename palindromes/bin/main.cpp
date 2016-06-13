#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "palindromesFinder.hpp"

using namespace exercise;

int main(int argc, char** argv){
    std::cout<<"-----Starting----."<<std::endl;
    if(argc!=2){
        std::cout<<"A path to a file is needed as argument"<<std::endl;
	return 1;
    }
    
    std::string pathFile=argv[1];

    // put your code here
    // assign this variable to your constructed vector of palindromes;

    std::vector<std::string> palindromes; 

    std::cout<<"The palindromes found in "+ pathFile +" are:"<<std::endl;
    std::for_each(palindromes.begin(),palindromes.end(),[](const std::string& str){std::cout<<str<<std::endl;});
    std::cout<<"-----Ending corretcly-----"<<std::endl;
    return 0;
}


