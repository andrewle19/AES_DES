#include<iostream>
#include <string>
#include "CipherInterface.h"
#include <fstream>
#include <vector>

#include "DES.h"
#include "AES.h"

using namespace std;





int main(int argc, char** argv)
{

	/* Create an instance of the DES cipher */
	// check arguments if too little or too much
	if(argc != 6){
			cout << "Too little or too many arguments used" << endl;
			cout << "./cipher <CIPHER NAME> <KEY> <ENC/DEC> <INPUTFILE> <OUTPUT FILE>\n";
			return 1;
	}

	/* Create an instance of the DES cipher */
	CipherInterface* cipher = NULL;
	ifstream infile;
	ofstream outfile;

	// get key from arguments
	unsigned char * key = (unsigned char*)argv[2];
	printf("KEY: %s\n", key);

	unsigned char * cipherText;
	unsigned char * output;

	// open up input file and grab input conver it init unsigned char
	infile.open(argv[4]);
	string line;
	string fileContents;
	// cout << fileContents.length();



	// Retrieve all the contents of the file and store it in string
	while(getline(infile,line)){
		fileContents += line;
		if(string(argv[3]) == "ENC"){
			fileContents.push_back('\n');
		}
	}
	infile.close();

	vector <string> blocks;
	cout << "before pad" << fileContents.length() << endl;

	if(string(argv[1]) == "AES"){

		while(fileContents.length() % 16 != 0){
			fileContents += "x";
		}
	}else {
		while(fileContents.length() % 8 != 0){
			fileContents += "x";
		}
	}
	cout << fileContents.length() << endl;


	int bindex = 0;
	for(int i = 0; i < fileContents.length(); i++){
		line += fileContents[i];
		if(string(argv[1]) == "AES"){
			if((i+1)%16 == 0){
				blocks.push_back(line);
				line = "";
				bindex++;
			}
		}
		else {
			if((i+1)%8 == 0){
				blocks.push_back(line);
				line = "";
				bindex++;
		}

	}
}





	if(string(argv[1]) == "DES"){
		// set cipher to be DES
		cipher = new DES();
		outfile.open(argv[5]);
		outfile << "";
		outfile.close();
		outfile.open(argv[5],ios_base::app);



		// output string
		unsigned char * output;
		unsigned char *inputText;
		// for(int i = 0; i < bindex; i++){
		// 	cipher->encrypt();
		// }

		// check if the set key was valid
		if(!cipher->setKey(key)){
			return 1;
		}

		// arguments decide to encrypt/decrypt
		if(string(argv[3]) == "ENC"){
			for(int i = 0; i < bindex; i++){
				inputText = (unsigned char*)blocks.at(i).c_str();
				output = cipher->encrypt(inputText);
				// output to file with arguments
				outfile << output;

			}

		}else if(string(argv[3]) == "DEC"){
			for(int i = 0; i < bindex; i++){
				inputText = (unsigned char*)blocks.at(i).c_str();
				outfile.open(argv[5],ios_base::app);
				output = cipher->decrypt(inputText);
				// output to file with arguments
				outfile << output;
				outfile.close();
			}
		}


		// close files
		outfile.close();
	}
	else if(string(argv[1]) == "AES"){
		// set cipher to be DES
		cipher = new AES();

		// open up input file and grab input conver it init unsigned char
		infile.open(argv[4]);
		string input;
		outfile.open(argv[5],ios_base::app);
		unsigned char *inputText;

		// output string
		unsigned char *output;

		// check if the set key was valid
		if(!cipher->setKey(key)){
			return 1;
		}

		// arguments decide to encrypt/decrypt
		if(string(argv[3]) == "ENC"){
			for(int i = 0; i < bindex; i++){
				inputText = (unsigned char*)blocks.at(i).c_str();
				output = cipher->encrypt(inputText);
				// output to file with arguments
				outfile << output;

			}
		}else if(string(argv[3]) == "DEC"){
			for(int i = 0; i < bindex; i++){
				inputText = (unsigned char*)blocks.at(i).c_str();
				output = cipher->decrypt(inputText);
				// output to file with arguments
				outfile << output;

			}
		}



		// close files
		outfile.close();

	}else {
			cout << "Invalid Cipher name: " << endl;
			cout << "AES: Advanced Encryption Standard" << endl;
			cout << "DES: Data Encryption Standard" << endl;
			return 1;

	}


	return 0;
}
