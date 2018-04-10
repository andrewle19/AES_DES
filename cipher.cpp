#include<iostream>
#include <string>
#include "CipherInterface.h"
#include <fstream>
#include "DES.h"
#include "AES.h"

using namespace std;

int main(int argc, char** argv)
{

	ifstream infile;
	ofstream outfile;
	string plainText;
	infile.open("text.txt");

	infile >> plainText;

	/* Create an instance of the DES cipher */
	CipherInterface* cipher = NULL;
	AES aestest;

	unsigned char * cipherText;
	unsigned char * output;

	aestest.setKey((unsigned char*)"00123456789abcdef");

	cipherText = aestest.encrypt((unsigned char*)plainText.c_str());
	printf("%s\n",cipherText );
	aestest.setKey((unsigned char*)"10123456789abcdef");
	output = aestest.decrypt(cipherText);
	outfile.open("yes.txt");
	outfile << output;


	/* Error checks */
	// if(!cipher)
	// {
	// 	fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
	// 	__FILE__, __FUNCTION__, __LINE__);
	// 	exit(-1);
	// }

	/* Set the encryption key
	 * A valid key comprises 16 hexidecimal
	 * characters. Below is one example.
	 * Your program should take input from
	 * command line.
	 */
	//cipher->setKey((unsigned char*)"0123456789abcdef");

	/* Perform encryption */
	//string cipherText = cipher->encrypt("hello world");

	/* Perform decryption */
	//cipher->decrypt(cipherText);

	return 0;
}
