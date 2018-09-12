#include <fstream>
#include <string>
#include <iostream>
#include <functional>
#include <random>

#include <unistd.h>
#include <getopt.h>

#define NONE "\e[0m"
#define L_GREEN "\e[1;32m"

int main(int argc, char **argv){

    int randomNumber = 10000;
    std::string outputName = "resources/data.txt";

    // parse arguments
    int arg = -1;
    while((arg = getopt(argc, argv, "n:f:")) != -1){
        switch(arg){
            case 'n':
                randomNumber = atoi(optarg);
                break;
            case 'f':
                outputName = optarg;
                break;
            default:
                abort();
        }
    }

    std::cout << "ready to generate " << L_GREEN << randomNumber << NONE <<
        " numbers randomly into " << L_GREEN << outputName << NONE << "" << std::endl;

    try{
        std::ofstream writer(outputName, std::ofstream::out);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution;
        auto dice = std::bind ( distribution, generator );

        writer << randomNumber << std::endl;
        while(randomNumber--)writer << dice() << std::endl;

        writer.close();

    }catch(char **err){
        std::cerr << err << std::endl;
    }
    return 0;
}
