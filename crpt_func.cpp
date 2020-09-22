#include <string_view>
#include "Header.h"

std::string caesar_encrypt(std::string_view text, int const shift)
{
    std::string str;
    str.reserve(text.length());
    for (auto const& c : text)
    {
        str += ' ' + (c - ' ' + shift) % 95;
    }

    return str;
}

std::string caesar_decrypt(std::string_view text, int const shift)
{
    std::string str;
    str.reserve(text.length());
    for (auto const& c : text)
    {
        str += ' ' + (c - ' ' - shift) % 95;
    }

    return str;
}


std::string build_vigenere_table()
{
    std::string table;
    table.reserve(95 * 95);
    std::string row;
    row.reserve(95);
    for (int c = 32; c <= 126; c++) row += c;
    for (int i = 0; i < 95; ++i)
        table += caesar_encrypt(row, i);

    return table;
}

std::string vigenere_encrypt(std::string_view text, std::string_view key)
{
    std::string str;
    str.reserve(text.length());

    std::string table = build_vigenere_table();

    for (int i = 0; i < text.length(); ++i)
    {
        int row = key[i % key.length()] - ' ';
        int col = text[i] - ' ';

        str += table[row * 95 + col];
    }

    return str;
}

std::string vigenere_decrypt(std::string_view text, std::string_view key)
{
    std::string str;
    str.reserve(text.length());

    std::string table = build_vigenere_table();

    for (int i = 0; i < text.length(); ++i)
    {
        int row = key[i % key.length()] - ' ';

        for (int col = 0; col < 95; col++)
        {
            if (table[row * 95 + col] == text[i])
            {
                str += ' ' + col;
                break;
            }
        }
    }

    return str;
}
