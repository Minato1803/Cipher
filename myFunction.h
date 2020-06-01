#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//chung
void delBlank(string s);
void tolowerText(string &s);

//Caesar
string CaesarCipher(string s, int shift);
		/*plain : NguyenDucKhai
		  shift = 3
		  cipher: QjxbhqGxfNkdl*/

//Playfair
string checkEven(string s);
int checkTrans(int a);
void Table(string key, char T[5][5]);
void search(char T[5][5], char a, char b, int arr[]) ;
string PlayfairCipher(string s, char T[5][5],bool Choose);
		/*plain : NguyenDucKhai
		  key   : Nhan
		  cipher: BDTZDHIQNPABFZ*/
		  
//Vigenere
string makeEqualKey(string s, string key);
string VigenereCipher(string s, string key, bool Choose);
		/*plain : Nguyen Duc Khai
		  key   : Nhan
		  cipher: Anulru Dhp Rhnv*/
		  
//Trans
string TransEncrypt(string key, string text);
string TransDecrypt(string key, string text);
		/*plain : Nguyen Duc Khai
		  key   : 4132
		  cipher: YUANECIUDHGNK*/
		  
//  test ket qua bang trang https://www.dcode.fr/tools-list#dcode	  
