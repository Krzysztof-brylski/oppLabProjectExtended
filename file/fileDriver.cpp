#include "fileDriver.h"


int FileDriver::calculateFileSize(){
    fstream* tempFile = new fstream(this->fileName, ios::in);
    tempFile->seekg(0, ios::end);
    int file_size = tempFile->tellg();
    tempFile->close();
    delete tempFile;
    return file_size;
}


FileDriver::FileDriver(string filename, ios_base::openmode mode) {

    this->file= new fstream(filename, mode);
    this->fileName=filename;
    this->fileSize=this->calculateFileSize();
}

FileDriver::~FileDriver() {
    delete this->file;
}

bool FileDriver::fileEmpty() {
    if(!this->fileExists()){
        return true;
    }
    this->fileSize=this->calculateFileSize();
    return (this->fileSize==0);
}

bool FileDriver::fileExists() {
    this->fileSize=this->calculateFileSize();
    return (this->fileSize >= 0);
}

bool FileDriver::regexMatch(string str, string regex){
    std::regex pattern (regex);
    return regex_match(str,pattern);
}

bool FileDriver::validateFile() {
    string line1,line2;
    int rowNumber,columnNumber;
    fstream tempFile(this->fileName, ios::in);
    (*this->file) >> line1;
    (*this->file) >> line2;


    if(!FileDriver::regexMatch(line1,"^(0|-*[1-9]+[0-9]*)$")){
        throw FileDimensionsEncodingException();
    }
    if(!FileDriver::regexMatch(line2,"^(0|-*[1-9]+[0-9]*)$")){
        throw FileDimensionsEncodingException();
    }

    rowNumber=stoi(line1);
    columnNumber=stoi(line2);
    string temp;

    for(int x =0;x<rowNumber;x++){
        for(int y=0;y<columnNumber;y++){
            (*this->file) >> temp;
            if(!FileDriver::regexMatch(temp,"^[0-9a-z]+(,[0-9a-z]+)*$")){
                throw FileCellDataEncodingException();
            }
        }
    }

}

bool FileDriver::validateSerializedCell(string){
//todo each cel have to have validationRule string, then we perform validation on each cell using his rule

    return false;
}

