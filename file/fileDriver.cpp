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
    this->file->close();
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

Sheet* FileDriver::buildSheetFromFile() {
    this->file->clear();
    this->file->seekg(0, ios::beg);

    string line1,line2;
    int rowNumber,columnNumber;
    fstream tempFile(this->fileName, ios::in);
    (*this->file) >> line1;
    (*this->file) >> line2;
    rowNumber=stoi(line1);
    columnNumber=stoi(line2);

    Sheet* sheet = new Sheet(rowNumber,columnNumber);

    string temp;

    for(int x =0;x<rowNumber;x++){
        for(int y=0;y<columnNumber;y++){
            (*this->file) >> temp;

            sheet->setCell(this->detectCellType(temp),x,y);
        }
    }
    return sheet;
}

CellInterface* FileDriver::detectCellType(string serializedCell) {
    int brakePos = serializedCell.find(',');

    string type=serializedCell.substr(0,brakePos);
    string value = serializedCell.substr(brakePos+1,serializedCell.length());
    if(type=="int"){
        return  new IntCell(stoi(value));
    }
    else if(type=="float"){
        return new FloatCell(stof(value));
    }
    else if(type=="string"){
        return new StringCell(value.c_str(),value.length());
    }

}

void FileDriver::saveSheetInFile(Sheet *sheet) {
    this->file->close();
    fstream file(this->fileName,ios::out);

    string serializedCell;
    int rowsNumber=sheet->getRowsNumber();
    int colsNumber=sheet->getColumnsNumber();

    file<<rowsNumber<<"\n";
    file<<colsNumber<<"\n";

    for (int i = 0; i <rowsNumber; i++) {
        for(int z =0;z< colsNumber;z++){
            serializedCell = sheet->getCell(i,z)->serialize();
            file<<serializedCell<<" ";
        }
        file<<"\n";
    }
    file.close();
}



