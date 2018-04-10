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
		cipher = new DES();

		infile.open(argv[4]);
		string input;
		infile >> input;
		unsigned char *inputText = (unsigned char*)input.c_str();
		unsigned char *output;

		if(!cipher->setKey(key)){
			cout << "Key was not valid" << endl;
		}

		if(string(argv[3]) == "ENC"){
			output = cipher->encrypt(inputText);	
		}else if(string(argv[3]) == "DEC"){
			output = cipher->decrypt(inputText);
		}
		outfile.open(argv[5]);
		outfile << output;
		outfile.close();
		infile.close();
	}
	else if(string(argv[1]) == "AES"){
		cout << "AES" << endl;
	}

	// aestest.setKey((unsigned char*)"00123456789abcdef");
	//
	// cipherText = aestest.encrypt((unsigned char*)plainText.c_str());
	// printf("%s\n",cipherText );
	// aestest.setKey((unsigned char*)"10123456789abcdef");
	// output = aestest.decrypt(cipherText);
	// outfile.open("yes.txt");
	// printf("%s\n",output );
	// outfile << output;

	// DES destest;
	// if(destest.setKey((unsigned char*)"0123456789abcdef")){
	// 	cout << "good set" << endl;
	// };
	// cipherText = destest.encrypt((unsigned char*)"BillyBob");
	// printf("CipherText: %s\n", cipherText);
	// output = destest.decrypt(cipherText);
	// printf("PlainText: %s\n", output);


	/* Error checks */
	// if(!cipher)
	// {
	// 	fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
	// 	__FILE__, __FUNCTION__, __LINE__);
	// 	exit(-1);
	// }



	return 0;
}
