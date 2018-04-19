#include <iostream>
#include <string>
#include "CipherInterface.h"
#include <stdio.h>
#include <stdlib.h>

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




	// reading from file
	FILE* infile = fopen(argv[4], "r");
	if(!infile){
		perror("fopen");
		exit(-1);
	}

	// outputing to file
	FILE* outfile = fopen(argv[5], "w");
	if(!outfile){
		perror("fopen");
		exit(-1);
	}


	// store block for encrypt/decryption
	unsigned char* block;
	// get key from arguments
	unsigned char * key = (unsigned char*)argv[2];
	printf("KEY: %s\n", key);


	if(string(argv[1]) == "DES"){
		// allocate size of block to 8 bytes
		block = new unsigned char[8];
		// set cipher to be DES
		cipher = new DES();

		// check if the set key was valid
		if(!cipher->setKey(key)){
			return 1;
		}

		// arguments decide to encrypt/decrypt
		if(string(argv[3]) == "ENC"){

				while(!feof(infile)){
						// clear the memory for room for the block
						memset(block, '\0', 8);
						// linesRead = fread(block, 1, 8, infile);
						// once reading the
						if(fread(block, 1, 8, infile) == 0){
							break;
						}
						// encrypt the block
						block = cipher->encrypt(block);

						// write the block to file
						fwrite(block, sizeof(char), 8, outfile);
				}
			}
		else if(string(argv[3]) == "DEC"){

			while(!feof(infile)){
					// clear the memory for room for the block
					memset(block, '\0', 8);

					/// makes sure we are reading exactly 8 characters
					if(fread(block, 1, 8, infile) == 0){
						break;
					}
					// encrypt the block
					block = cipher->decrypt(block);

					// write the block to file
					fwrite(block, sizeof(char), 8, outfile);
			}

		}
	}
	else if(string(argv[1]) == "AES"){

		// allocate size of block to 16 bytes
		block = new unsigned char[16];
		// set cipher to be DES
		cipher = new AES();

		// check if the set key was valid
		if(!cipher->setKey(key)){
			return 1;
		}

		// arguments decide to encrypt/decrypt
		if(string(argv[3]) == "ENC"){

				while(!feof(infile)){
						// clear the memory for room for the block
						memset(block, '\0', 16);

						// makes sure we are reading 16 blocks
						if(fread(block, 1, 16, infile) == 0){
							break;
						}
						// encrypt the block
						block = cipher->encrypt(block);

						// write the block to file
						fwrite(block, sizeof(char), 16, outfile);
				}
			}
		else if(string(argv[3]) == "DEC"){

			while(!feof(infile)){
					// clear the memory for room for the block
					memset(block, '\0', 16);

					// makes sure we are reading 16 bytes
					if(fread(block, 1, 16, infile) == 0){
						break;
					}
					// encrypt the block
					block = cipher->decrypt(block);
					// write the block to file
					fwrite(block, sizeof(char), 16, outfile);
			}
	}
}
	else {
			cout << "Invalid Cipher name: " << endl;
			cout << "AES: Advanced Encryption Standard" << endl;
			cout << "DES: Data Encryption Standard" << endl;
			return 1;

	}

	fclose(infile);
	fclose(outfile);
	return 0;
}
