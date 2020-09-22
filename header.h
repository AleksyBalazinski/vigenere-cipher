#pragma once
#include <string>
std::string caesar_encrypt(std::string_view text, int const shift);
std::string caesar_decrypt(std::string_view text, int const shift);
std::string build_vigenere_table();
std::string vigenere_encrypt(std::string_view text, std::string_view key);
std::string vigenere_decrypt(std::string_view text, std::string_view key);
