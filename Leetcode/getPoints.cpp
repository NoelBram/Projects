#include "brambila.h"

int main() {
    fstream newFile; 
    newFile.open("a.txt", ios::in);
    
    ofstream file;
    string state = "alaska";
    string capLng = "";
    string capLat = "";
    file.open("state.tsx");
    if(newFile.is_open()){
        string line; 
        file << "//" << state << endl << "export let " << state << "Diameter = [[ " << endl;
        while(getline(newFile, line)){
            for(int i = 0; i < line.size(); i++){
                string lng = "";
                string lat = ""; 
                if(isblank(line[i])){
                    i++;
                }
                if((line[i] == '-') || (isdigit(line[i]))){
                    do{
                        lng += line[i];
                        i++;
                    }while(line[i] != ',');
                    i++;            // get rid of "," & go to lat value
                    do{
                        lat += line[i];
                        i++;
                    }while((!isblank(line[i])) && (line[i] != 'o') && (line[i] != 'e'));
                }

                if((lng != "") && (lat != "")){
                    if(line[i] == 'o'){
                        file << "{lng: " << lng << ",lat: " << lat << "}"<< endl << "],[" << endl ;
                    }else if(line[i] == 'e'){
                        file << "{lng: " << lng << ",lat: " << lat << "}" << endl << "]];" << endl;
                        file << "export let " << state << "Capital = {lng:"<< capLng << ", lat:" << capLat << "};" << endl; 
                    }
                    else{
                        file << "{lng: " << lng << ",lat: " << lat << "},"<< endl;
                    }   
                }
            }
        }
    }
    newFile.close();
    return 0; 
}