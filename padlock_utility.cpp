#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>

int check(std::string line, std::string code){
	if (line.substr(0,code.size()) == code){
		std::cout<<line.substr((code.size()+1),line.size())<<"\n";
		return 1;
	}
	return -1;
}


int main(int argc, char *argv[]){
	if (argc != 2) {
	  std::cout<<"Invalid Entry!\n";
	  return 0;
  	}
  	
  	
  	std::string line; //line buffer for file
        std::ifstream dataFile("data");
	int flag = 0; //keep it from printing not found all the time
	std::string s = argv[1];
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);
	while (getline(dataFile, line)){

		while (check(line,s)==1){
			getline(dataFile,line); //keep on rollin'

			flag = 1;
		}


	}
	if (flag == 0){
		std::cout<<"Not Found!";	
	}
	
	return 0;

}

