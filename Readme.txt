Andrew Le email: andrewle19@csu.fullerton.edu
Steve Sanchez email: sanchez25@csu.fullerton.edu
Eric Fratzke email: eric.fratzke@csu.fullerton.edu
Syed Hussani email: syedhussaini@csu.fullerton.edu
Cesar Carrillo email: cesar8@csu.fullerton.edu

Programming language we used was C++.

No Extra Credit Implemented


How to Execute Program
1. Run make in terminal
2. Input this command.
./cipher <CIPHER NAME> <KEY> <ENC/DEC> <INPUT FILE> <OUTPUT FILE>

	-CIPHER NAME = AES or DES
	-KEY = 16 chars representing 64-bit hexadecimal number for DES or 128-bit number for AES


Example Command
./cipher "00123456789abcdef" AES ENC input.txt cipher.txt
./cipher "0123456789abcdef" DES ENC input.txt cipher.txt
