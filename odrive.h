#ifndef ODRIVE_H
#define ODRIVE_H
#include <string>

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
	string read();
	void write(string message);
};

#endif // ODRIVE_H
