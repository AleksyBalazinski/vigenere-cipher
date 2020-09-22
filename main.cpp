#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

int main()
{
    std::cout << "1 - create file with encrypted passwords in given location\n";
    std::cout << "2 - decrypt file in given location\n";
    int choice = 0;
    std::cin >> choice;
    switch (choice)
    {
    case 1: 
    {
        std::cout << "Enter path of a directory (make sure it exists)\n";
        std::string path, path_formated, file_name;
        std::cin >> path;
        std::cout << "Enter file name with extension .txt (encrypted passwords will be stored there)\n";
        std::cin >> file_name;
        int cnt = 0;
        for (auto c : path)
        {
            if (c == '\\') cnt++;
        }
        path_formated.reserve(path.length() + cnt + file_name.length() + 1);
        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == '\\') path_formated += "\\\\";
            else path_formated += path[i];
        }
        path_formated += '\\' + file_name;
        //std::cout << path_formated;
        std::ofstream myfile;
        std::cout << "Enter passwords (with descriptions)\n";
        std::string plaintext;
        std::cin >> plaintext;
        std::cout << "Create your key (you will need it to decrypt the passwords!)\n";
        std::string key;
        std::cin >> key;
        std::string ciphertext;
        ciphertext = vigenere_encrypt(plaintext, key);
        myfile.open(path_formated);
        myfile << ciphertext;
        myfile.close();
        std::cout << "\nOperation successful\n\t" << plaintext << " --> " << ciphertext << "\n";
        break;
    }
    case 2:
    {
        std::cout << "Enter full path of your file\n";
        std::string path, path_formated;
        std::cin >> path;
        int cnt = 0;
        for (auto c : path)
        {
            if (c == '\\') cnt++;
        }
        path_formated.reserve(path.length() + cnt);
        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == '\\') path_formated += "\\\\";
            else path_formated += path[i];
        }
        //std::cout << path_formated;
        std::ifstream myfile;
        myfile.open(path_formated);
        std::string ciphertext;
        getline(myfile, ciphertext);
        std::string key;
        std::string plaintext;
        std::cout << "Enter your key: " << key;
        std::cin >> key;
        plaintext = vigenere_decrypt(ciphertext, key);
        std::cout << "\nOperation successful\n\t" << ciphertext << " --> " << plaintext << "\n";
        myfile.close();
        break;
    }
    default:
    {
        std::cout << "Error\n";
    }
    }
}
