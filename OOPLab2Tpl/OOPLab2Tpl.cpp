﻿#include <iostream>
#include <string>

// Функція для шифрування введеного тексту
void Crypt(std::string text[4], unsigned short rez[4][16]) {
    short i, j, l;

    // Запит на введення 4 рядків тексту від користувача
    for (int i = 0; i < 4; i++) {
        std::cout << "enter line " << i + 1 << ":";
        std::getline(std::cin, text[i]);
    }

    // Вивід введеного тексту
    std::cout << "You entered:\n";
    for (i = 0; i < 4; i++) {
        while (text[i].length() < 16) {
            text[i] += ' '; // Доповнення кожного рядка пробілами до довжини 16 символів
        }
    }

    // Вивід доповненого тексту
    for (i = 0; i < 4; i++) {
        std::cout << text[i] << std::endl;
    }

    // Шифрування тексту
    std::cout << "\nCrypted info:\n";
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 16; j++) {
            unsigned char c;
            unsigned short r, t, b;
            r = 0;
            c = text[i][j];

            // Встановлення частини результуючого числа за допомогою бітових операцій
            r |= i;

            int asciiValue = static_cast<int>(c);
            int higherPart = asciiValue >> 4;
            int lowerPart = asciiValue & 0xF;
            r |= (higherPart << 2);

            t = 1;
            b = 0;
            for (l = 0; l < 5; l++) {
                if (r & t) {
                    if (b == 0) b = 1; else b = 0;
                }
                t <<= 1;
            }

            r |= b << 6;

            r |= (lowerPart << 7);
            r |= (j << 11);

            t = 1;
            b = 0;
            for (l = 6; l < 16; l++) {
                if (r & t) {
                    if (b == 0) b = 1; else b = 0;
                }
                t <<= 1;
            }
            r |= b << 15;

            rez[i][j] = r; // Збереження результату шифрування у масиві rez
            std::cout << std::hex << rez[i][j] << " "; // Вивід шифрованих даних
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string text[4];
    unsigned short rez[4][16];
    Crypt(text, rez);
    return 0;
}
