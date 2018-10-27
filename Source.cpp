//var 5
#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>

template <typename T>
std::string toString(T val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

enum Protocol {
	HTTP = 80,
	HTTPS = 443,
	FTP = 21
};

bool ParseURL(std::string const& url, Protocol & protocol, int & port, std::string & host, std::string & document);

int main() {
	std::string address = "http://cppstudio.com:666/post/698/"; /*  */
	Protocol protocol;
	int port = 0;
	std::string host;
	std::string document;
	
	if (!ParseURL(address, protocol, port, host, document)) {
		std::cout << "ERROR";
	}
	

	_getch();
	return 0;
}

bool ParseURL(std::string const& url, Protocol & protocol, int & port, std::string & host, std::string & document) {
	std::string::const_iterator it_b = url.begin();
	std::string::const_iterator it = url.begin();
	std::string prot = "NULL";

	if (url.find("://") == std::string::npos) 
		return 0;

	prot = url.substr(0, url.find(':'));
	it = it + prot.length() + strlen("://");

	if(url.find(':', std::distance(it_b, it)) != std::string::npos) {
		host = url.substr(std::distance(it_b, it), url.find(':', std::distance(it_b, it))-std::distance(it_b, it));
		it = it + host.length();
		if (url.find('/', std::distance(it_b, it)) != std::string::npos) {

			//std::cout << url.substr(std::distance(it_b, it)+1, url.find('/', std::distance(it_b, it)) - std::distance(it_b, it)-1);
			port = atoi(url.substr(std::distance(it_b, it)+1, url.find('/', std::distance(it_b, it))- std::distance(it_b, it)-1).c_str());
			it = it + toString(port).length()+1;
			document = url.substr(std::distance(it_b, it), url.find('/0', std::distance(it_b, it)));
		}
	}else if(url.find('/', std::distance(it_b, it)) != std::string::npos){
		host = url.substr(std::distance(it_b, it), url.find_first_of('/', std::distance(it_b, it))-std::distance(it_b, it)); //find_first_of return not first of it

		it = it + host.length();
		document = url.substr(std::distance(it_b, it), url.find('/0', std::distance(it_b, it)));

	}else {
		host = url.substr(std::distance(it_b, it), url.find('/0', std::distance(it_b, it)));
	}

	std::cout << "HOST: " << host << std::endl;

	std::cout << "PORT: ";
	if (port == 0) {
		if (prot == "http") {
			std::cout << HTTP;
		}
		else if (prot == "https") {
			std::cout << HTTPS;
		}
		else if (prot == "ftp") {
			std::cout << FTP;
		}
	}else {
		std::cout << port;
	}std::cout << std::endl;

	std::cout << "DOC: " << document << std::endl;
	return 1;
}

//std::string fnd_frst_of(int begin, std::string str, std::string substr) {
//	int i = 0;
//	while (i < str.length()) {
//		
//		int j = 0;
//		while (j < substr.length()) {
//
//			if (str[i] != substr[j]) {
//				break;
//			}else{
//				i++;
//				j++;
//			}
//		}
//		
//		i++;
//	}
//}



