/* 
 * File:   main.cpp
 * Author: DJKC
 *
 * Created on January 18, 2020, 10:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

struct Data{
    int age;
    char name[10];
    char sex;
};

ostream& operator << (ostream &out, const Data &outputData){
    out << "\t\t*****\n" 
        << "Name: " << outputData.name << "\n"
        << "Age: " <<outputData.age << "\n"
        << "Sex: " << outputData.sex << "\n";
    
    return out;
}

void detect_file_state(fstream &file, bool quiet_mode = false){
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
        error_status += " okay!";
    }

    std::cout << "\n"  << error_status << "\n";
    
    return;
}

int main(int argc, char** argv){
    fstream dataFile("Data.pcx", ios::in | ios::out | ios::binary);
    
    detect_file_state(dataFile);
    
    if(!dataFile){
        std::cout << "\nFile opening failed, trying again.\n";
        
        dataFile.open("Data.pcx", ios::out | ios::binary);
        dataFile.close();
        dataFile.open("Data.pcx", ios::in | ios::out | ios::binary);
        
        if(!dataFile){
            std::cout << "\nFile does not exist, now exiting program.\n";
            
            return 0;
        }else{
            std::cout << "\nFile is ready for writing.\n";
        }
    }
    
    Data john1{10, "John 1", 'M'}, john2{11, "John 2", 'M'};
    
    std::cout << "John #1 data:\n" << john1;
    std::cout << "John #2 data:\n" << john2;
    
    dataFile.write(reinterpret_cast<char*>(&john1), sizeof(Data));
    dataFile.write(reinterpret_cast<char*>(&john2), sizeof(Data));
    
    dataFile.seekp(0L, ios::beg);
    dataFile.seekg(0L, ios::beg);
    
    dataFile.read(reinterpret_cast<char*>(&john2), sizeof(Data));
    dataFile.read(reinterpret_cast<char*>(&john1), sizeof(Data));
    
    std::cout << "John #1 data:\n" << john1;
    std::cout << "John #2 data:\n" << john2;
    
    dataFile.seekp(0L, ios::end);
    long position = dataFile.tellp();
    
    std::cout << "Data size: " << sizeof(Data) << ", Size of file: " << position << "\n";
    
    dataFile.close();
    
    remove("Data.pcx");
    
    return 0;
}

