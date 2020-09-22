# vigenere-cipher
Encrypts text (assumably passwords) inserted by a user and saves its encrypted version to a newly created txt file located in a given localization. 
Conversly, it can also decrypt text from a txt file in a user-given localization.
### Encryption method
Text is encrypted using The Vigenère cipher. In order to decipher an encrypted file *a key* will be needed. It specified by a user during the encryption process and thus it's important not to forget it. Click [here](https://en.wikipedia.org/wiki/Vigenère_cipher) for more information.
### Is it totally safe method for keeping my sensitive data?
Definitely not. It was made for fun (inspired by a problem from a textbook "The Modern C++ Challenge" by M. Bancila).
### Side note
Do not create a key which is longer than the whole text you want to encrypt. This may result in an undefied behavior.
