#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// major class
class FileSystem {
	private:
		bool checkFileExist(const string name);

	public:
		FileSystem() { cout << "Object created!\n"; }
		void CreateFile(const string path);
		void ReadFile(const string path);
		void WriteFile(const string path);
		void AppendFile(const string path);
		void MoveFile(const string path);
		void DeleteFile(const string path);
		void PrintAllFiles(const string path);
		void CreateDirectory(const string path);
};


// driver code
int main() {
	FileSystem fs1;
	string path = "c:\\Users\\HP\\Desktop\\scrap\\file";
	// fs1.CreateFile(path);
	// fs1.WriteFile(path);
	// fs1.ReadFile(path);
	// fs1.MoveFile(path);
	// fs1.CreateDirectory(path);
	// fs1.DeleteFile(path);
	// fs1.PrintAllFiles(path);
	fs1.AppendFile(path);
	return 0;
}

// function to check if a file exist or not 
bool FileSystem::checkFileExist(const string name) {
    bool flag = false;
    try {
    	if(FILE *file = fopen(name.c_str(), "r")) {
	        fclose(file);
	        flag = true;
	    }
    } catch(...) {
    	cout << "Something went wrong!\n";
    }
    return flag;
}

// function to create new file 
void FileSystem::CreateFile(const string path) {
	string fileName;
	cout << "Enter file name(Create): ";
	cin >> fileName;
	string fileToBeCreated = path + "\\" + fileName;

	if(checkFileExist(fileToBeCreated) == true) {
		cout << "A file with this name already exist!\n";
		return;
	}

	try {
		ofstream fptr(fileToBeCreated);
		fptr.close();
	} catch(...) {
		cout << "Something went wrong!\n";
	}
}

// function to write into a file
void FileSystem::WriteFile(const string path) {
	string fileName;
	cout << "Enter file name(Write): ";
	cin >> fileName;
	string fileToBeWritten = path + "\\" + fileName;
	string data = "I love coding, reading books and playing cricket.";

	try {
		ofstream MyWriteFile(fileToBeWritten, ios::out);
		for(int i = 0; i < data.length(); i++) {
			MyWriteFile << data[i];
		}
		MyWriteFile.close();
	} catch(...) {
		cout << "Something went wrong!\n";
	}
}

// function to read a file 
void FileSystem::ReadFile(const string path) {
	string fileName;
	cout << "Enter file name(Read): ";
	cin >> fileName;
	string fileToBeRead = path + "\\" + fileName;

	if(checkFileExist(fileToBeRead) == false) {
		cout << "File with this name doesn't exist!\n";
		return;
	}

	try {
		string data;
		ifstream MyReadFile(fileToBeRead, ios::out);
		while(getline(MyReadFile, data)) {
			cout << data;
		}
		MyReadFile.close();
	} catch(...) {
		cout << "Something went wrong!\n";
	}
}

// function to append a file 
void FileSystem::AppendFile(const string path) {
	string fileName;
	cout << "Enter file name(Read): ";
	cin >> fileName;
	string fileToBeAppend = path + "\\" + fileName;
	string data = "Dipanshu is a good boy!";

	if(checkFileExist(fileToBeAppend) == false) {
		cout << "File with this name doesn't exist!\n";
		return;
	}

	try {
		ofstream fout;
      	fout.open(fileToBeAppend, ios::app);
      	fout << data;
      	fout.close();
	} catch(...) {
		cout << "Something went wrong!\n";
	}
}

// function to move a file
void FileSystem::MoveFile(const string path) {
	string fileName;
	cout << "Enter file name(Move): ";
	cin >> fileName;
	string fileToBeMoved = path + "\\" + fileName;
	string destination = path+"\\newDir";

	if(checkFileExist(fileToBeMoved) == false) {
		cout << "File with this name doesn't exist!\n";
		return;
	}

	try {
		char cmd[500], src[500] = "c:\\Users\\HP\\Desktop\\scrap\\file\\hello.txt", dest[500] = "c:\\Users\\HP\\Desktop\\scrap\\file\\newDir";
		strcpy(cmd,"mv ");
		strcat(cmd, src);
		strcat(cmd," ");
		strcat(cmd, dest);
		system(cmd);
	} catch(...) {
		cout << "Something went wrong!\n";
	}
}

// function to move a file
void FileSystem::DeleteFile(const string path) {
	string fileName;
	cout << "Enter file name(Delete): ";
	cin >> fileName;
	string fileToBeDeleted = path + "\\" + fileName;

	if(checkFileExist(fileToBeDeleted) == false) {
		cout << "File with this name doesn't exist!\n";
		return;
	}

	try {
		if (remove(fileToBeDeleted.c_str( )) !=0)
           cout << "Remove operation failed" << endl;
     	else
           cout << fileToBeDeleted << " has been removed." << endl;
	} catch(...) {
		cout << "Something went wrong!\n";
	}
}

void FileSystem::CreateDirectory(const string path) {
	char name[50];
	cout << "Enter file name(Directory): ";
	scanf("%s", name);

	// if(checkFileExist(fileToBeMoved) == false) {
	// 	cout << "File with this name doesn't exist!\n";
	// 	return;
	// }

	try {
		char cmd[100];
		strcpy(cmd,"mkdir ");
		strcat(cmd, name);
		system(cmd);
	} catch(...) {
		cout << "Something went wrong!\n";
	}
}

void FileSystem::PrintAllFiles(const string path) {
	try {
		char cmd[10];
		strcpy(cmd, "ls -1");
		system(cmd);
	} catch(...) {
		cout << "Something went wrong!\n";
	}
}

// #include <fstream>
// #include <iostream>
// using namespace std;
// int main (int argc, char** argv) {
//    fstream File("d.txt", ios::in | ios::out );
//    File << "TutorialsPoint";
//    File.seekg(9, ios::beg);
//    char F[9];
//    File.read(F, 5);
//    F[5] = 0;
//    cout <<F<< endl;
//    File.close();
// }