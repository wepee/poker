#ifndef ODRIVE_H
#define ODRIVE_H
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "sys/stat.h"
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

class ODrive
{
    string odAgentPath_;
    string odDrivePath_;
    string redirString_;
	string baseDir;
	string roomDir;
	string commFile;
    bool debugMode_;
public:
    ODrive(string _baseDir, string _roomDir, string odAgentDir=".odrive-agent", string odDriveDir="odrive", bool debugMode=false);
    string getFullName(string file) {return odDrivePath_+'/'+file;}
    void sync(string dir);
    void refresh(string dir);
    void emptytrash();
    void mkDir(string dir);
    void delFile(string file);
	void deleteCommFile() { delFile(commFile); };
    bool isDir(string dir);
    void waitForChange(string file);
	//Lis en direct si live = true
	string read(bool live = false);
	//Ecrire dans le commFile
	void write(string message);
};

#endif // ODRIVE_H
