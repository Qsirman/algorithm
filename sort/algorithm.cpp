#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <unistd.h>
#include <getopt.h>

#include "sort.h"

#define NONE "\e[0m"
#define L_GREEN "\e[1;32m"
#define L_BLUE "\e[1;34m"

int main(int argc, char **argv){
    std::string inputName = "resources/data.txt";

	bool isShow = false;

    int arg = -1;

    while( -1 != (arg = getopt(argc, argv, "sf:")) ){
        switch(arg){
            case 'f':
                inputName = optarg;
                break;
			case 's':
				isShow = true;
				break;
            default:
                abort();
        }
    }

    std::fstream reader(inputName, std::fstream::in);

    int temp;
	int readMax;
	reader >> readMax;

	std::vector<int> input(readMax);
	std::vector<int>::iterator it = input.begin();

	int _readMax = readMax;

	while(_readMax--){
		reader >> input[_readMax];
	}

    std::cout << L_GREEN << "[done]" << NONE <<"read " << L_BLUE << readMax << NONE << " numbers from "<< L_BLUE << inputName << NONE <<std::endl;

	input = sort(input);

    std::cout << L_GREEN << "[done]" << NONE << "sort done" <<std::endl;

	if(isShow){
		for(auto& p : input){
			std::cout << p << std::endl;
		}
	}

    reader.close();
    return 0;
}
