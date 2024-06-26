#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstdio>

char *help() {
    std::string helpText;
    helpText += "\nUsage: ca -p {chars_separated_with_underscores}\n";
    helpText += "       ca sf filePath [here sf = show file]\n";
    helpText += "       ca sf-l [to show file with number lines]\n";
    helpText += "       ca cp SourceFile DistFile\n";
    helpText += "       ca finfo FileName [to get info about a specific file]\n";
    helpText += "       ca lines FileName\n";
    helpText += "       ca c FILENAME [to create a blank file]\n";
    helpText += "\nSystem: ca -p 'text'\n";
    helpText += "        ca -sysinfo\n";
    helpText += "        ca -sysS [to show storage capacity]\n";
    helpText += "        ca -time\n";
    helpText += "        ca -del FileName\n";

    return strdup(helpText.c_str());
}

// Function to create a blank file
void c(const std::string& filename) {
    std::ofstream file(filename);
    file.close();
}

void printFileWithNumberLine(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    int lineNumber = 1;
    while (std::getline(file, line)) {
        std::cout << lineNumber << " " << line << std::endl;
        lineNumber++;
    }

    file.close();
}

int linesNumber(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << fileName << std::endl;
        return -1;
    }

    std::string line;
    int lineNumber = 0;
    while (std::getline(file, line)) {
        lineNumber++;
    }
    file.close();

    return lineNumber;
}

void cp(const std::string& sourceFileName, const std::string& destFileName) {
    std::ifstream sourceFile(sourceFileName);
    if (!sourceFile) {
       std::cerr << "Unable to open source file: " << sourceFileName << std::endl;
       return;
    }

    std::ofstream destFile(destFileName);
    if (!destFile) {
        std::cerr << "Unable to open destination file: " << destFileName << std::endl;
        return;
    }

    char c;
    while (sourceFile.get(c)) {
        destFile << c;
    }

    sourceFile.close();
    destFile.close();

    std::cout << "Success: Contents copied successfully!" << std::endl;
}

void sysInfo(){
    system("neofetch");
}

void _time(){
    system("date");
}

void sysS(){
    system("df -H");
}

void finfo(const std::string& fileName){
    std::string filetype = "file "+fileName;
    std::string fileStat = "stat "+fileName;
    system(filetype.c_str());
    std::cout<<"\n"<<std::endl;
    system(fileStat.c_str()); 
}

void _delFile(const std::string& filename) {
    // Try deleting the file
    if (remove(filename.c_str())!=0) {
        std::cerr<<"Error: Unable to delete the file: "<<filename<<std::endl;
    } else{
        std::cout<<"Success: "<<filename<<" Deleted successfully."<<std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "\n use 'ca -h' or 'ca help' to get the help menu\n" << std::endl;
        return 0;
    }

    if (strcmp(argv[1], "-p") == 0) {
        if (argc >= 3 && strlen(argv[2]) > 0) {
            std::cout << argv[2] << std::endl;
        } else {
            std::cout << "Error found at argv[2]" << std::endl;
            std::cout << "Correct syntax: ca -p {chars_separated_with_underscores}" << std::endl;
            return 1; // Return a non-zero value to indicate error
        }
    }
    else if (strcmp(argv[1], "sf") == 0) {
        if (argc >= 3 && strlen(argv[2]) > 0) {
            std::ifstream inputFile(argv[2]);
   
            if (inputFile.is_open()) {
                std::string line;
                // Reading and printing entire file
                while (std::getline(inputFile, line)) {
                    std::cout << line << std::endl;
                }
                inputFile.close();
                
                return 0; // Exit the program after displaying file contents
            } else {
                std::cout << "Unable to open file: " << argv[2] << std::endl;
                return 1; // Return a non-zero value to indicate error
            }
        } else {
            std::cout << "Error found at argv[2]" << std::endl;
            std::cout << "Correct syntax: ca --read-file filename" << std::endl;
            return 1; // Return a non-zero value to indicate error
        }
    }
    else if(strcmp(argv[1], "-sysinfo")==0){
        sysInfo();
        return 0;
    }
    else if(strcmp(argv[1], "sf-l")==0){
        if(argc >=3 && strlen(argv[2])>0){
            printFileWithNumberLine(argv[2]);
        }
        else{
            std::cout<<"Argument and filePath needed. Type ca -h or ca help for details";
        }
    }
    else if(strcmp(argv[1],"-sysS")==0){
        sysS();
    }
    else if (strcmp(argv[1], "c")==0 && strlen(argv[2])>0) {
        c(argv[2]);
    }
    else if(strcmp(argv[1],"cp")==0){
        if(argc >=4 && strlen(argv[2])>0 && strlen(argv[3])>0){
            cp(argv[2],argv[3]);
        }
    }
    else if(strcmp(argv[1],"finfo")==0){
        if(argc >=3 && strlen(argv[2])>0){
            finfo(argv[2]);
        }
    }
    else if(strcmp(argv[1],"-time")==0){
        _time();
    }
    else if(strcmp(argv[1],"lines")==0){
        if(argc>=3 && strlen(argv[2])>0){
            int lines = linesNumber(argv[2]);
            std::cout<<"Lines: "<<lines<<std::endl;
        }
    }
    else if (strcmp(argv[1],"-del")==0 && strlen(argv[2])>0){
        _delFile(argv[2]);
        return 0;
    }
    else if(strcmp(argv[1],"-h")==0 || strcmp(argv[1],"help") == 0){
        std::cout<<help()<<std::endl;
    }
    else {
        std::cout<<"\nInvalid Input"<<std::endl;
        std::cout<<help()<<std::endl;
        return 1; // Return a non-zero value to indicate error
    }

    return 0;
}
