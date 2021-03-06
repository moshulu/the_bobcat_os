
#include <iostream>
#include <string>

using namespace std;

string encryptDecrypt(string toEncrypt) {
    char key[5] = {'B', 'A', 'L', 'L', 'Z'}; //Any chars will work
    string output = toEncrypt;
    
    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
    
    return output;
}

int main(int argc, const char * argv[])
{
    string input_line;
    getline(cin, input_line);
    cout << input_line;
    
    string encrypted = encryptDecrypt(input_line);
    cout << "Encrypted:" << encrypted << "\n";
    
    string decrypted = encryptDecrypt(encrypted);
    cout << "Decrypted:" << decrypted << "\n";
    
    return 0;
}
