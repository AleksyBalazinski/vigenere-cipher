#include <iostream>
#include <fstream>
#include "Header.h"

int main()
{
    repeat:
    std::cout << "1 - create file with encrypted passwords in given location\n";
    std::cout << "2 - decrypt file in given location\n";
    int choice = 0;
    std::cin >> choice;
    switch (choice)
    {
    case 1: 
    {
        std::cout << "Enter path of a directory (make sure it exists)\n";
        std::string path, file_name;
        std::cin >> path;
        std::cout << "Enter file name with extension .txt (encrypted passwords will be stored there)\n";
        std::cin >> file_name;
        int cnt = 0;
        path += '\\' + file_name;
        //std::cout << path;
        std::ofstream myfile;
        myfile.open(path);
        if (myfile.is_open())
        {
            std::cout << "Enter passwords (with descriptions)\n";
            std::string plaintext;
            std::cin >> plaintext;
            std::cout << "Create your key (you will need it to decrypt the passwords!)\n";
            std::string key;
            std::cin >> key;
            std::string ciphertext;
            ciphertext = vigenere_encrypt(plaintext, key);
            myfile << ciphertext;
            myfile.close();
            std::cout << "\nOperation successful\n\t" << plaintext << " --> " << ciphertext << "\n";
        }
        else std::cout << "\nOperation failed\n";
        break;
    }
    case 2:
    {
        std::cout << "Enter full path of your file\n";
        std::string path;
        std::cin >> path;
        int cnt = 0;
        //std::cout << path;
        std::ifstream myfile;
        myfile.open(path);
        if (myfile.is_open())
        {
            std::string ciphertext;
            getline(myfile, ciphertext);
            std::string key;
            std::string plaintext;
            std::cout << "Enter your key: " << key;
            std::cin >> key;
            plaintext = vigenere_decrypt(ciphertext, key);
            std::cout << "\nOperation successful\n\t" << ciphertext << " --> " << plaintext << "\n";
            myfile.close();
        }
        else std::cout << "\nOperation failed\n";
        break;
    }
    default:
    {
        std::cout << "Error\n";
    }
    }
    std::cout << "\n0 - close";
    std::cout << "\n1 - repeat\n";
    std::cin >> choice;
    if (choice)
    {
        system("cls");
        goto repeat;
    }
}
