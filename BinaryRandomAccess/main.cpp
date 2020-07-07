/* 
 * File:   main.cpp
 * Author: DJKC
 *
 * Created on January 18, 2020, 10:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Data{
    short age;
    char name[2];
    char sex;
};

ostream& operator << (ostream &out, const Data &outputData){
    out << "\n*****\n" 
        << "Name: " << outputData.name << "\n"
        << "Age: "  << outputData.age << "\n"
        << "Sex: "  << outputData.sex << "\n"
        << "*****\n";
    
    return out;
}

unsigned long& findFileSize(fstream &file, unsigned long &fileSize){
    file.seekp(0L, ios::end);
    fileSize = file.tellp();
    file.seekp(0L, ios::beg);
    
    return fileSize;
}

void detect_file_state(fstream &file){
    std::string error_status = "Your file is";
    
    if(file.bad() || file.eof() || file.fail() || (!file.is_open())){
        error_status += (file.bad() == true ? " bad," : "" );
        error_status += (file.eof() == true ? " EOF reached," : "" );
        error_status += (file.fail() == true ? " failed," : "" );
        error_status += (file.is_open() == false ? " not open," : "" );
        
        std::size_t found = error_status.find_last_of(",");
        //std::cout << "\n[" << error_status.at(found) << "]\n";
        error_status.replace(found, 1, ".");
    }else{
        std::cout << (error_status += " okay!");
    }

    std::cout << "\n"  << error_status << "\n";
    
    return;
}

bool createIfNotExist(fstream &file, const char* fileName, char inputOrOutput = 'b'){
    if(!file){
        file.close();
        file.open(fileName, ios::out | ios::trunc);
        file.close();
        
        if(inputOrOutput == 'i'){
            file.open(fileName, ios::in | ios::binary);
        }else if(inputOrOutput == 'o'){
            file.open(fileName, ios::out | ios::binary | ios::ate);
        }else{
            file.open(fileName, ios::in | ios::out | ios::binary);
        }
    }

    return (!file.fail());
}

int main(int argc, char** argv){
    char fileName[]{"fileI.txt"}, letter;
    fstream file(fileName, ios::out | ios::in | ios::binary);
    unsigned long fileSize = findFileSize(file, fileSize);
    
    if(createIfNotExist(file, fileName, 'b') ==  false){
        std::cout << "\nFile could not be created, now exiting\n";
        file.close();
        
        return 0;
    }
   
    Data moreData{99, "a", 'm'}, extraData{40, "k", 'm'};

    file.write(reinterpret_cast<char*>(&moreData), sizeof(Data));
    file.write(reinterpret_cast<char*>(&extraData), sizeof(Data));
    file.seekg(0L, ios::beg);
    
    while(file.read(reinterpret_cast<char*>(&moreData), sizeof(Data))){
        std::cout << moreData;
    }
        
    file.close();

    return 0;
}
