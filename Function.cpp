#include "myFunction.h"

void delBlank(string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i]==' ')
		{
			s[i] = s[i+1];
			for(int j = i+1;j<s.length()-1;j++)
			{
				s[j] = s[j+1];
			}
			s[s.length()-1] = '\0';
		}
	}
}
void tolowerText(string &s)
{
	for(int i = 0;i<s.length();i++)
	{
		s[i] = tolower(s[i]);
	}
}
//Caesar
string CaesarCipher(string s, int shift)
{
	for (int i=0;i<s.length();i++) 
    { 
        if (isupper(s[i])) 
            s[i] = char(int(s[i]+shift-65)%26 +65); 
  		else
        	s[i] = char(int(s[i]+shift-97)%26 +97); 
    }
    return s;
}


//Playfair   
string checkEven(string s) 
{ 
	int n = s.length();
    if (s.length() % 2 != 0) 
	{ 
        s+='x'; 
    } 
    return s; 
}

int checkTrans(int a)
{
	if(a == 5)
	{
		return 0;
	}
	else if(a == -1)
	{
		return 4;
	}
}

void Table(string key, char T[5][5]) 
{ 
    int i = 0, j = 0;
	int store[27] = {0};
    for (int i = 0; i < key.length(); i++) 
	{ 
        if (key[i] != 'j')
        {
            store[key[i] - 97] = 2; // luu vi tri chu cai trong key
		}
    } 

    store['j' - 97] = 1; // xoa chu cai j
  
    for (int k = 0; k < key.length(); k++) 
	{ 
        if (store[key[k] - 97] == 2) 
		{ 
            store[key[k] - 97] = 1; //xoa chu cai khoi alphabet
            T[i][j] = key[k]; 
            j++; 
            if (j == 5) 
			{ 
                i++; 
                j = 0; 
            } 
        } 
    } 
  
    for (int k = 0; k < 26; k++) 
	{ 
        if (store[k] == 0) {
            T[i][j] = (char)(k + 97); 
            j++; 
            if (j == 5) { 
                i++; 
                j = 0; 
            } 
        } 
    } 
} 

void search(char T[5][5], char a, char b, int arr[]) 
{ 
    if (a == 'j') 
		a = 'i'; 
    if (b == 'j') 
        b = 'i'; 
  
    for (int i = 0; i < 5; i++) 
	{ 
        for (int j = 0; j < 5; j++) 
		{ 
            if (T[i][j] == a) 
			{ 
                arr[0] = i; 
                arr[1] = j; 
            } 
            else if (T[i][j] == b) 
			{ 
                arr[2] = i; 
                arr[3] = j; 
            } 
        } 
    } 
}   
   
string PlayfairCipher(string s, char T[5][5],bool Choose) 
{ 
    int a[4] = {0}, step = 1; 
	if(Choose == false)
	{
		step = -1;
	}
    for (int i = 0; i < s.length(); i += 2) 
	{ 
  
        search(T, s[i], s[i + 1], a); 
  		//cout<<s[i]<<s[i+1]<<" ";
        if (a[0] == a[2]) //cung hang -> dich phai 1
		{ 
            s[i] = T[a[0]][checkTrans(a[1]+step)]; 
            s[i + 1] = T[a[2]][checkTrans(a[3]+step)]; 
        } 
        else if (a[1] == a[3]) //cung cot -> dich xuong 1
		{ 
            s[i] = T[checkTrans(a[0]+step)][a[1]]; 
            s[i + 1] = T[checkTrans(a[2]+step)][a[3]]; 
        } 
        else // khac -> thay the
		{ 
            s[i] = T[a[0]][a[3]]; 
            s[i + 1] = T[a[2]][a[1]]; 
        } 
    }
    return s;
} 

// vigenere
string makeEqualKey(string s, string key) 
{ 
	string result ="";
    int n = key.length(), i= 0, len = 0; 
    while(result.length() != s.length()) 
    { 
    	if(i==n)
    	{
    		i = 0;
		}
		if(s[len] == ' ')
		{
			result+=' ';
			len++;
		}
		else
		{
        	result+=key[i];
        	i++;
        	len++;
		}	 
    } 
    return result; 
}
string VigenereCipher(string s, string key, bool Choose) 
{ 
    for (int i = 0; i < s.length(); i++) 
    {  
    	if(s[i]>=97 && s[i]<= 122)
    	{
			cout<<s[i]<<" "<<key[i]<<" ";	
	    	if(Choose == false)
	    	{
	    		s[i] = ((s[i]-97) - (key[i]-97)) %26 + 97;
			}
			else
	        	s[i] = ((s[i]-97) + (key[i]-97))%26 + 97;
	        cout<<s[i]<<endl;	
		}
    } 
    return s; 
} 

