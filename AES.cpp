#include "AES.h"

/**
 * Sets the key to use
 * @param key - the first byte of this represents whether
 * to encrypt or to decrypt. 00 means encrypt and any other
 * value to decrypt.  Then come the bytes of the 128-bit key
 * (should be 16 of them).
 * @return - True if the key is valid and False otherwise
 */
bool AES::setKey(const unsigned char* aes_key)
{
	// get the count of the aes_key
	int keycount = strlen((char*)aes_key);

	// check if the key count is 17 if not key is not valid
	if(keycount != 17){
		cout << "key is not valid" << endl;
		return false;
	}

	// extract actual key from the char byte array (get rid of index 1)
	unsigned char buffer[16];

	// extract actual key to buffer
	for(int i = 1; i < keycount; i++){
			buffer[i-1] = aes_key[i];
	}

	// if first byte is 0 means encryption
	if(aes_key[0] == '0') {

		cout << "Encrypt" << endl;

		// set the encrypt key checks if it sets properly
		if(AES_set_encrypt_key(buffer,128,&decEncKey) != 0){
			{
				cout << "key was invalid" << endl;
				return false;
			}
	}

}
	// first byte is anything but 0 means we decrypt
	else{
		cout << "Decrypt" << endl;

		if(AES_set_decrypt_key(buffer,128,&decEncKey) != 0){
			cout << "Key was invalid" << endl;
			return false;
		}

	}

	return true;

}

/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
unsigned char* AES::encrypt(const unsigned char* plainText)
{

	// calculate plain text length
	int plainTextLength = strlen((char*)plainText);
	unsigned char aes_input[]= "helloworld123456";

	printf("%s\n",plainText );
	unsigned char *cipherText; // store cipherText Dynamically
	// store cipherText Dynamically
	cipherText = (unsigned char *)malloc(sizeof(unsigned char)*plainTextLength);


	// USe AES to encrypt the plaintext to cipher text
	AES_ecb_encrypt(plainText, cipherText,&decEncKey, AES_ENCRYPT);

	return cipherText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
unsigned char* AES::decrypt(const unsigned char* cipherText)
{
	int cipherTextLength = strlen((char*)cipherText);
	unsigned char aes_input[]= "helloworld123456";
	unsigned char *dec_out;
	dec_out = (unsigned char *)malloc(sizeof(unsigned char)*cipherTextLength);

	AES_ecb_encrypt(cipherText, dec_out, &decEncKey, AES_DECRYPT);
	printf("%s\n", dec_out );
	//TODO: 1. Dynamically allocate a block to store the plaintext.
	//	2. Use AES_ecb_encrypt(...) to decrypt the text (please see the URL in setKey(...)
	//	and the aes.cpp example provided.
	// 	3. Return the pointer to the plaintext

	return dec_out;
}
