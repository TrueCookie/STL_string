//var 5
#include <iostream>
#include <string>
#include <conio.h>

int main() {
	std::string address = "http://cppstudio.com/post/698/";
	

	_getch();
	return 0;
}

enum Protocol {
	HTTP = 80, 
	HTTPS = 443, 
	FTP = 21
};

bool ParseURL(std::string const& url, Protocol & protocol, int & port, std::string & host, std::string & document) {
	std::string prot = url.substr(0, url.find_first_of(':'));
	
	if (1) {
		return true;
	}else {
		return false;
	}
}

