//
//  URL_Parser.cpp
//  URL_Assignment
//
//  Created by Bhuvan Bolem on 1/30/20.
//  Copyright © 2020 Bhuvan Bolem. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    string inputURL, protocol, domain, port, filePath, parameter, zDomain;
    bool invalidReq = false, isProtocol = false, validProtocol = false, isDomain = false, validDomain = false, isPort = false, validPort = false, isFilePath = false, isParameter = false, isURL_Parsed = false;
    size_t currPos = 0, prevPos = 0;
    static const size_t npos = -1;
    //get the input from user
    cout << "Enter the URL to parse :: ";
    cin >> inputURL;
    cout << endl;
    if (inputURL.find("?") == npos) {
        inputURL += "?";        //appends '?' to the end when there is no '?' because it is the last requirement for a valid URL
    }
    /* Find the Protocol; check for validity and save as string */
    currPos = inputURL.find(":");
    if (currPos == npos) {
        isURL_Parsed = true;
    }
    if (isURL_Parsed != true) {
        protocol = inputURL.substr(prevPos, currPos - prevPos); //set protocol with the first couple strings after ':'
        prevPos = currPos;
        isProtocol = true;  //protocol exits
        //check for valid protocol
        if((protocol != "http") && (protocol != "https") && (protocol != "ftp") && (protocol != "ftps")){
            validProtocol = true;
            invalidReq = true;
        }
    }
    /* Find the Domain; check for validity and save as string*/
    if(isURL_Parsed == false){
        currPos = inputURL.find("//", prevPos + 1);
        if(currPos == npos){
            isURL_Parsed = true;
        }
        else{
            prevPos = currPos + 2;
            currPos = inputURL.find(":", prevPos + 1);
            if(currPos == npos){
                isURL_Parsed = true;
            }
        }
    }
    if(isURL_Parsed == false){
        domain = inputURL.substr(prevPos, currPos - prevPos);
        prevPos = currPos;
        isDomain = true;    //domain exits
        zDomain = domain.substr(domain.length() - 3);
        //check for valid 'z' of domain
        if ((zDomain != "com") && (zDomain != "net") && (zDomain != "edu") && (zDomain != "biz") && (zDomain != "gov")) {
            validDomain = true;
            invalidReq = true;
        }
    }
    /* Find the Port; check for validity and save as string */
    if(isURL_Parsed == false){
        prevPos = currPos + 1;
        currPos = inputURL.find("/", prevPos + 1);
        if(currPos == npos){
            isURL_Parsed = true;
        }
    }
    if(isURL_Parsed == false){
        port = inputURL.substr(prevPos, currPos - prevPos);
        prevPos = currPos;
        isPort = true;
        int portNum = atoi(port.c_str());
        if( (portNum < 1) || (portNum > 65535) ){
            validPort = true;
            invalidReq = true;
        }
    }
    /* Find the File Path; check for validity and save as string */
    if(isURL_Parsed == false){
        prevPos = currPos;
        currPos = inputURL.find("?", prevPos + 1);
        if(currPos == npos){
            isURL_Parsed = true;
        }
    }
    if(isURL_Parsed == false){
        filePath = inputURL.substr(prevPos, currPos - prevPos);
        isFilePath = true;
        prevPos = currPos;
    }
    /* Find the Parameter; save as string*/
    if(isURL_Parsed == false)    {
        prevPos = currPos + 1;
    }
    if(isURL_Parsed == false){
        parameter = inputURL.substr(prevPos);
        isParameter = true;
        prevPos = currPos;
    }
    
    /* Print all the URL information based on if it met the requirements or not */
    //Error message
    if(invalidReq == true){
        cout << "Invalid URL with following erroneous components:" << endl;
    }
    //Protocol message based on the URL requirements
    if(isProtocol == true){
        if(validProtocol == true){
            cout << "Protocol:\t" << protocol << " is not a valid protocol." << endl;
        }
        else if(invalidReq == false){
            cout << "Protocol:\t" << protocol << endl;
        }
    }
    else{
        cout << "User did not enter ::\t\tProtocol" << endl;
    }
    //Domain message based on the URL requirements
    if(isDomain == true){
        if(validDomain == true){
            cout << "Domain:\t\t" << zDomain << " is an invalid domain name." << endl;
        }
        else if(invalidReq == false){
            cout << "Domain:\t\t" << domain << endl;
        }
    }
    else{
        cout << "User did not enter ::\t\tDomain" << endl;
    }
    //Port message based on the URL requirements
    if(isPort == true){
        if(validPort == true){
            cout << "Port:\t\t" << "port number must be between 1 and 65535." << endl;
        }
        else if(invalidReq == false){
            cout << "Port:\t\t" << port << endl;
        }
    }
    else{
        cout << "User did not enter ::\t\tPort" << endl;
    }
    //File Path message based on the URL requirements
    if(isFilePath == true){
        if(invalidReq == false){
            cout << "File path:\t" << filePath << endl;
        }
    }
    else{
        cout << "User did not enter ::\t\tFile Path" << endl;
    }
    //File Path message based on the URL requirements
    if(isParameter == true){
        if(invalidReq == false){
            cout << "Parameters:\t" << parameter << endl;
        }
    }
    else{
        cout << "User did not enter ::\t\tParameters" << endl;
    }
    return 0;
}
