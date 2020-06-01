#include "myFunction.h"
#include <conio.h>
#include <Windows.h>

using namespace std;
void Menu();
void Caesar();
void Playfair();
void Vigenere();
void TransTech();


int main() {
	Menu();
	return 0;
}

void Menu()
{
	while(!_kbhit())
	{
		cout<<"1. Caesar Cipher"<<endl;
		cout<<"2. Playfair Cipher"<<endl;
		cout<<"3. Vigenere Cipher"<<endl;
		cout<<"4. Transposition Techniques"<<endl;
		char key = _getch();
		switch(key)
		{
			case '1':
			{
				Caesar();
				break;
			}
			case '2':
			{
				Playfair();
				break;
			}
			case '3':
			{
				Vigenere();
				break;
			}
			case '4':
			{
				TransTech();
				break;
			}	
			case 27:
			{
				system("cls");
				Menu();
				break;
			}	
		}
		
	}
	system("pause");
	
	
}

void Caesar()
{
	while(!_kbhit())
	{
		cout<<"=======Caesar========="<<endl;
		cout<<"1. Encrypt"<<endl;
		cout<<"2. Decypt"<<endl;
    	string result = ""; 
		string text = "";
		int shift;
		bool Choose = false;
		char keyButton = _getch();
		switch(keyButton)
		{
			case '1':
			{
				cout<<"=======Encrypt========="<<endl;
    			cout << "plain Text: "; 
    			getline(cin,text);
    			cout << "\nshift: ";
    			cin>>shift;
				Choose = true;
				cin.ignore();
				break;
			}
			case '2':
			{
				cout<<"=======Decrypt========="<<endl;
    			cout << "Cipher Text: "; 
    			getline(cin, text);
    			cout << "\nshift: ";
    			cin>>shift;
				cin.ignore();
				break;
			}
			case 27:
			{
				system("cls");
				Menu();
				break;
			}	
		}
		if(Choose ==false)
		{
			result = CaesarCipher(text,26-shift);
	   	 	cout << "\nPlain: " << result<<endl; 	
		} 
		else
		{
			result = CaesarCipher(text,shift);
	    	cout << "\nCipher: " << result<<endl; 
		}
	}
}
void Playfair()
{ 
	while(!_kbhit())
	{
		cout<<"=======PlayFair========="<<endl;
		cout<<"1. Encrypt"<<endl;
		cout<<"2. Decypt"<<endl;
	    char T[5][5]; 
		string text = "";
		string key = "";
		string result = ""; 
		bool Choose = false;
		char keyButton = _getch();
		switch(keyButton)
		{
			case '1':
			{
				cout<<"=======Encrypt========="<<endl;
    			cout << "plain Text: "; 
    			getline(cin,text);
    			cout << "\nkey: ";
    			getline(cin,key);
				Choose = true;
				break;
			}
			case '2':
			{
				cout<<"=======Decrypt========="<<endl;
    			cout << "Cipher Text: "; 
    			getline(cin, text);
    			cout << "\nkey: ";
    			getline(cin, key);
				break;
			}
			case 27:
			{
				system("cls");
				Menu();
				break;
			}	
		}
	    delBlank(key);
		tolowerText(key); 
	    Table(key, T); 
	  
	    // Plaintext  
	    delBlank(text);   
		tolowerText(text); 
	    text = checkEven(text);

//	    cout<<text<<endl;
//	for(int i = 0 ;i<5;i++)
//	{
//		for(int j= 0 ;j<5;j++)
//		{
//			cout<<T[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
		if(Choose ==false)
		{
			
	    	result = PlayfairCipher(text, T,Choose); 
	   	 	cout << "\nPlain: " << result<<endl; 
			
		} 
		else
		{
	    	result = PlayfairCipher(text, T,Choose); 
	    	cout << "\nCipher: " << result<<endl; 
		}
	}
}

void Vigenere()
{
	while(!_kbhit())
	{
		cout<<"=======Vigenere========="<<endl;
		cout<<"1. Encrypt"<<endl;
		cout<<"2. Decypt"<<endl;
		string text = "";
		string key = "";
		string result = ""; 
		bool Choose = false;
		char keyButton = _getch();
		switch(keyButton)
		{
			case '1':
			{
				cout<<"=======Encrypt========="<<endl;
    			cout << "plain Text: "; 
    			getline(cin,text);
    			cout << "\nkey: ";
    			getline(cin,key);
				Choose = true;
				break;
			}
			case '2':
			{
				cout<<"=======Decrypt========="<<endl;
    			cout << "Cipher Text: "; 
    			getline(cin, text);
    			cout << "\nkey: ";
    			getline(cin, key);
				break;
			}
			case 27:
			{
				system("cls");
				Menu();
				break;
			}	
		}
	    delBlank(key);
		tolowerText(key); 
		key = makeEqualKey(text,key);
	  
	    // Plaintext     
		tolowerText(text); 
		
		if(Choose ==false)
		{
			
	    	result = VigenereCipher(text, key,Choose); 
	   	 	cout << "\nPlain: " << result<<endl; 
		} 
		else
		{
	    	result = VigenereCipher(text, key,Choose); 
	    	cout << "\nCipher: " << result<<endl; 
		}
	}
} 

void TransTech()
{
	while(!_kbhit())
	{
		cout<<"=======Transposition Techniques========="<<endl;
		cout<<"1. Encrypt"<<endl;
		cout<<"2. Decypt"<<endl;
		string text = "";
		string key;
		string result = ""; 
		bool Choose = false;
		char keyButton = _getch();
		switch(keyButton)
		{
			case '1':
			{
				cout<<"=======Encrypt========="<<endl;
    			cout << "plain Text: "; 
    			getline(cin,text);
    			cout << "\nkey: ";
    			getline(cin,key);
				Choose = true;
				break;
			}
			case '2':
			{
				cout<<"=======Decrypt========="<<endl;
    			cout << "Cipher Text: "; 
    			getline(cin, text);
    			cout << "\nkey: ";
    			getline(cin, key);
				break;
			}
			case 27:
			{
				system("cls");
				Menu();
				break;
			}	
		}	  
		
		if(Choose ==false)
		{
			
	    	result = TransDecrypt(key,text); 
	   	 	cout << "\nPlain: " << result<<endl; 
		} 
		else
		{
	    	result = TransEncrypt(key,text); 
	    	cout << "\nCipher: " << result<<endl; 
		}
	}
}

