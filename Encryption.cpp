#include <iostream>
#include <string>
using namespace std;

// XOR Encryption (core logic)
string xorEncryptDecrypt(string data, char key) {
    for (int i = 0; i < data.size(); i++) {
        data[i] = data[i] ^ key;
    }
    return data;
}

// Caesar Cipher (shift letters)
string caesarEncrypt(string text, int shift) {
    for (char &c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }
    return text;
}

string caesarDecrypt(string text, int shift) {
    return caesarEncrypt(text, 26 - shift);
}

// Combined Encryption
string encrypt(string message, int shift, char key) {
    string step1 = caesarEncrypt(message, shift);
    string step2 = xorEncryptDecrypt(step1, key);
    return step2;
}

// Combined Decryption
string decrypt(string encrypted, int shift, char key) {
    string step1 = xorEncryptDecrypt(encrypted, key);
    string step2 = caesarDecrypt(step1, shift);
    return step2;
}

// Simulated system
void runSystem() {
    int choice;
    string message;
    int shift = 3;
    char key = 'K';

    while (true) {
        cout << "\n==== Secure Message System ====\n";
        cout << "1. Send (Encrypt Message)\n";
        cout << "2. Receive (Decrypt Message)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter message: ";
            getline(cin, message);

            string encrypted = encrypt(message, shift, key);
            cout << "Encrypted Message: " << encrypted << endl;

        } else if (choice == 2) {
            cout << "Enter encrypted message: ";
            getline(cin, message);

            string decrypted = decrypt(message, shift, key);
            cout << "Decrypted Message: " << decrypted << endl;

        } else if (choice == 3) {
            cout << "Exiting...\n";
            break;

        } else {
            cout << "Invalid choice!\n";
        }
    }
}

int main() {
    runSystem();
    return 0;
}
