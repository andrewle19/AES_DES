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

	unsigned char *cipherText; // store cipherText Dynamically


	// store cipherText Dynamically HEAP based on plain text size
	cipherText = new unsigned char[plainTextLength];
	//cipherText = (unsigned char *)malloc(sizeof(unsigned char)*plainTextLength); C WAY


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
	// calculate cipher text length
	int cipherTextLength = strlen((char*)cipherText);

	unsigned char *plainText;

	// Allocate plainText space dynamically
	plainText = new unsigned char[cipherTextLength];

	// dec_out = (unsigned char *)malloc(sizeof(unsigned char)*cipherTextLength); CWAY


	// DECRYPT THE ciphertext
	AES_ecb_encrypt(cipherText, plainText, &decEncKey, AES_DECRYPT);
	printf("Decrypted: %s\n",plainText);


	return plainText;
}
