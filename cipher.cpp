#include<iostream>
#include <string>
#include "CipherInterface.h"
#include <fstream>
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

	if(string(argv[1]) == "DES"){
		// set cipher to be DES
		cipher = new DES();

		// open up input file and grab input conver it init unsigned char
		infile.open(argv[4]);
		string input;
		infile >> input;
		unsigned char *inputText = (unsigned char*)input.c_str();

		// output string
		unsigned char *output;

		// check if the set key was valid
		if(!cipher->setKey(key)){
			return 1;
		}

		// arguments decide to encrypt/decrypt
		if(string(argv[3]) == "ENC"){
			output = cipher->encrypt(inputText);
		}else if(string(argv[3]) == "DEC"){
			output = cipher->decrypt(inputText);
		}

		// output to file with arguments
		outfile.open(argv[5]);
		outfile << output;

		// close files
		outfile.close();
		infile.close();
	}
	else if(string(argv[1]) == "AES"){
		// set cipher to be DES
		cipher = new AES();

		// open up input file and grab input conver it init unsigned char
		infile.open(argv[4]);
		string input;
		infile >> input;
		unsigned char *inputText = (unsigned char*)input.c_str();

		// output string
		unsigned char *output;

		// check if the set key was valid
		if(!cipher->setKey(key)){
			return 1;
		}

		// arguments decide to encrypt/decrypt
		if(string(argv[3]) == "ENC"){
			output = cipher->encrypt(inputText);
		}else if(string(argv[3]) == "DEC"){
			output = cipher->decrypt(inputText);
		}

		// output to file with arguments
		outfile.open(argv[5]);
		outfile << output;

		// close files
		outfile.close();
		infile.close();
	}else {
			cout << "Invalid Cipher name: " << endl;
			cout << "AES: Advanced Encryption Standard" << endl;
			cout << "DES: Data Encryption Standard" << endl;
			return 1;

	}


	return 0;
}
