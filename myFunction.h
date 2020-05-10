#pragma once
#include <iostream>
#include <string>
using namespace std;

//chung
void delBlank(string s);
void tolowerText(string &s);

//Caesar
string CaesarCipher(string s, int shift);

//Playfair
string checkEven(string s);
int checkTrans(int a);
void Table(string key, char T[5][5]);
void search(char T[5][5], char a, char b, int arr[]) ;
string PlayfairCipher(string s, char T[5][5],bool Choose);

//Vigenere
string makeEqualKey(string s, string key);
string VigenereCipher(string s, string key, bool Choose);

