#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct node
{
	string key;
	string data;
	node *next;
};

class metaphone
{
private:
	int ind = 0;
	
	node *hashTable[100];
public:
	metaphone()
	{
		for (int i = 0; i < 100; i++)
		{
			hashTable[i] = NULL;
		}
	}
	void fillHashTable(char read[], int n)
	{
		char *read2 = new char[n];
		for (int i = 0; i < n; i++)
		{
			read2[i] = read[i];
		}
		char *modifiedArray = metaphoneAlgo(read);
		string s1(modifiedArray);
		string s2(read2);
		int ind = hashFunc(s1);
		node* nn = new node;
		nn->next = hashTable[ind];
		hashTable[ind] = nn;
		nn->data = s2;
		nn->key = s1;
	}
	void matchingWords(char input[])
	{
		char *modifiedArray = metaphoneAlgo(input);
		string s1(modifiedArray);
		int ind = hashFunc(s1);
		node * temp = hashTable[ind];
		while (temp != NULL)
		{
			if (temp->key == s1)
			{
				cout << temp->data <<"\t";
			}
			cout << temp->data<<endl;
			temp = temp->next;
		}
		cout << endl;
	}
	char * metaphoneAlgo(char inputArray[])
	{

		for (int l = 0; l<5; l++)
		{
			int i = 0;
			if (((inputArray[i] == 'k' || inputArray[i] == 'K' || inputArray[i] == 'g' || inputArray[i] == 'G' || inputArray[i] == 'p' || inputArray[i] == 'P') && (inputArray[i + 1] == 'n' || inputArray[i + 1] == 'N')) || ((inputArray[i] == 'a' || inputArray[i] == 'A') && (inputArray[i + 1] == 'e' || inputArray[i + 1] == 'E')) || ((inputArray[i] == 'w' || inputArray[i] == 'W') && (inputArray[i] == 'r' || inputArray[i] == 'R')))
			{
				for (i = 0; inputArray[i] != '\0'; i++)
				{
					inputArray[i] = inputArray[i + 1];
				}
			}
			for (int i = 0; inputArray[i] != '\0'; i++)
			{
				if ((inputArray[i] != 'c' || inputArray[i] != 'C') && inputArray[i] == inputArray[i + 1])
				{
					for (int j = i + 1; inputArray[j] != '\0'; j++)
					{

						inputArray[j] = inputArray[j + 1];
					}
				}
				if (((inputArray[i] == 'c' || inputArray[i] == 'C') && (((inputArray[i + 1] == 'i' || inputArray[i + 1] == 'I') && (inputArray[i + 2] == 'a' || inputArray[i + 2] == 'A')) || (inputArray[i + 1] == 'h' || inputArray[i + 1] == 'H'))))
				{
					inputArray[i] = 'x';
				}
				else if ((inputArray[i] == 'c' || inputArray[i] == 'C') && ((inputArray[i + 1] == 'i' || inputArray[i + 1] == 'I') || (inputArray[i + 1] == 'e' || inputArray[i + 1] == 'E') || (inputArray[i + 1] == 'y' || inputArray[i + 1] == 'Y')))
				{
					inputArray[i] = 's';
				}
				else if ((inputArray[i] == 's' || inputArray[i] == 'S') && (inputArray[i + 1] == 'c' || inputArray[i + 1] == 'C') && ((inputArray[i + 2] == 'i' || inputArray[i + 2] == 'I') || (inputArray[i + 2] == 'e' || inputArray[i + 2] == 'E') || (inputArray[i + 2] == 'y' || inputArray[i + 2] == 'Y')))
				{
					for (int j = i + 1; inputArray[j] != '\0'; j++)
					{
						inputArray[j] = inputArray[j + 1];
					}
				}
				else
				{
					if (inputArray[i] == 'c' || inputArray[i] == 'C')
					{
						inputArray[i] = 'k';
					}
				}
				if ((inputArray[i] == 'd' || inputArray[i] == 'D') && (inputArray[i + 1] == 'g' || inputArray[i + 1] == 'G') && (inputArray[i + 2] == 'e' || inputArray[i + 2] == 'E' || inputArray[i + 2] == 'i' || inputArray[i + 2] == 'I' || inputArray[i + 2] == 'y' || inputArray[i + 2] == 'Y'))
				{
					inputArray[i] = 'j';
				}
				else if (inputArray[i] == 'd' || inputArray[i] == 'D')
				{
					inputArray[i] = 't';
				}
				if ((inputArray[i] == 'm' || inputArray[i] == 'M') && (inputArray[i + 1] == 'b' || inputArray[i + 1] == 'B') && (inputArray[i + 2] == '\0'))
				{
					inputArray[i + 1] = '\0';
				}
				if ((inputArray[i] == 'g' || inputArray[i] == 'G') && (((inputArray[i + 1] == 'h' || inputArray[i + 1] == 'H') && (inputArray[i + 2] != '\0') && (inputArray[i + 2] != 'a' && inputArray[i + 2] != 'A') && (inputArray[i + 2] != 'e' && inputArray[i + 2] != 'E') && (inputArray[i + 2] != 'i' && inputArray[i + 2] != 'I') && (inputArray[i + 2] != 'o' && inputArray[i + 2] != 'O') && (inputArray[i + 2] != 'u' && inputArray[i + 2] != 'U')) || (inputArray[i + 1] == 'n' || inputArray[i + 1] == 'N')))
				{
					for (int j = i; inputArray[j] != '\0'; j++)
					{
						inputArray[j] = inputArray[j + 1];
					}
				}
				if ((inputArray[i] == 'd' || inputArray[i] == 'D') && (inputArray[i + 1] == 'g' || inputArray[i + 1] == 'G') && (inputArray[i + 2] == 'e' || inputArray[i + 2] == 'E'))
				{
					for (int j = i + 1; inputArray[j] != '\0'; j++)
					{
						inputArray[j] = inputArray[j + 1];
					}
				}
				if ((inputArray[i] == 'g' || inputArray[i] == 'G') && (inputArray[i + 1] != 'g' || inputArray[i + 1] != 'G') && ((inputArray[i + 1] == 'e' || inputArray[i + 1] == 'E') || (inputArray[i + 1] == 'i' || inputArray[i + 1] == 'I') || (inputArray[i + 1] == 'y' || inputArray[i + 1] == 'Y')))
				{
					inputArray[i] = 'j';
				}
				else if (inputArray[i] == 'g' || inputArray[i] == 'G')
				{
					inputArray[i] = 'k';
				}
				if (((inputArray[i] == 'a' || inputArray[i] == 'A') || (inputArray[i] == 'e' || inputArray[i] == 'E') || (inputArray[i] == 'i' || inputArray[i] == 'I') || (inputArray[i] == 'o' || inputArray[i] == 'O') || (inputArray[i] == 'u' || inputArray[i] == 'U')) && (inputArray[i + 1] == 'h' || inputArray[i + 1] == 'H') && ((inputArray[i + 2] != 'a' && inputArray[i + 2] != 'A') && (inputArray[i + 2] != 'e' && inputArray[i + 2] != 'E') && (inputArray[i + 2] != 'i' && inputArray[i + 2] != 'I') && (inputArray[i + 2] != 'o' && inputArray[i + 2] != 'O') && (inputArray[i + 2] != 'u' && inputArray[i + 2] != 'U')))
				{
					for (int j = i + 1; inputArray[j] != '\0'; j++)
					{
						inputArray[j] = inputArray[j + 1];
					}
				}
				if ((inputArray[i] == 'c' || inputArray[i] == 'C' || inputArray[i] == 's' || inputArray[i] == 'S' || inputArray[i] == 'p' || inputArray[i] == 'P' || inputArray[i] == 't' || inputArray[i] == 'T' || inputArray[i] == 'g' || inputArray[i] == 'G') && (inputArray[i + 1] == 'h' || inputArray[i + 1] == 'H') && (inputArray[i + 2] == 'h' || inputArray[i + 2] == 'H'))
				{
					for (int j = i + 2; inputArray[j] != '\0'; j++)
					{
						inputArray[j] = inputArray[j + 1];
					}
				}
				if ((inputArray[i] == 'c' || inputArray[i] == 'C') && (inputArray[i + 1] == 'k' || inputArray[i + 1] == 'K'))
				{
					for (int j = i + 1; inputArray[j] != '\0'; j++)
					{
						inputArray[j] = inputArray[j + 1];
					}
				}
				if ((inputArray[i] == 'p' || inputArray[i] == 'P') && (inputArray[i + 1] == 'h' || inputArray[i + 1] == 'H'))
				{
					inputArray[i] = 'f';
				}
				if ((inputArray[i] == 's' || inputArray[i] == 'S') && ((inputArray[i + 1] == 'h' || inputArray[i + 1] == 'H') || ((inputArray[i + 1] == 'i' || inputArray[i + 1] == 'I') && ((inputArray[i + 2] == 'o' || inputArray[i + 2] == 'O') || (inputArray[i + 2] == 'a' || inputArray[i + 2] == 'A')))))
				{
					inputArray[i] = 'x';
				}
				if ((inputArray[i] == 't' || inputArray[i] == 'T') && (inputArray[i + 1] == 'i' || inputArray[i + 1] == 'I') && ((inputArray[i + 2] == 'a' || inputArray[i + 2] == 'A') || (inputArray[i + 2] == 'o' || inputArray[i + 2] == 'O')))
				{
					inputArray[i] = 'x';
				}
				if ((inputArray[i] == 't' || inputArray[i] == 'T') && (inputArray[i + 1] == 'h' || inputArray[i + 1] == 'H'))
				{
					inputArray[i] = '0';
					for (int j = i + 1; inputArray[j] != '\0'; j++)
					{
						inputArray[j] = inputArray[j + 1];
					}
				}
				if ((inputArray[i] == 'w' || inputArray[i] == 'W' || inputArray[i] == 'y' || inputArray[i] == 'Y') && ((inputArray[i + 1] != 'a' && inputArray[i + 1] != 'A') && (inputArray[i + 1] != 'e' && inputArray[i + 1] != 'E') && (inputArray[i + 1] != 'i' && inputArray[i + 1] != 'I') && (inputArray[i + 1] != 'o' && inputArray[i + 1] != 'O') && (inputArray[i + 1] != 'u' && inputArray[i + 1] != 'U')))
				{
					for (int j = i; inputArray[j] != '\0'; j++)
					{
						inputArray[j] = inputArray[j + 1];
					}
				}
				if (inputArray[i] == 'z' || inputArray[i] == 'Z')
				{
					inputArray[i] = 's';
				}
				if (inputArray[i] == 'v' || inputArray[i] == 'V')
				{
					inputArray[i] = 'f';
				}
				if (inputArray[i] == 'q' || inputArray[i] == 'Q')
				{
					inputArray[i] = 'k';
				}
				if (i != 0)
				{
					if ((inputArray[i] == 'a' || inputArray[i] == 'A' || inputArray[i] == 'e' || inputArray[i] == 'E' || inputArray[i] == 'i' || inputArray[i] == 'I' || inputArray[i] == 'o' || inputArray[i] == 'O' || inputArray[i] == 'u' || inputArray[i] == 'U'))
					{
						for (int j = i; inputArray[j] != '\0'; j++)
						{
							inputArray[j] = inputArray[j + 1];
						}
					}
				}
			}
		}
		return inputArray;
	}
	int hashFunc(string s)
	{
		int n = s.length();
		char * word = new char[n];
		for (int i = 0; i < n; i++)
		{
			word[i] = '\0';
		}
		int ind1 = 0;
		strcpy_s(word, n + 1, s.c_str());
		for (int i = 0; word[i] != '\0'; i++)
		{
			ind1 = ind1 + int(word[i]);
		}
		ind1 = ind1 % 100;
		return ind1;
	}
	int factorial(int n)
	{
		int a = n;
		for (int i = 0; n > 1; i++)
		{
			a = a * (n - 1);
			n--;
		}
		return a;
	}
	void display()
	{
		int count = 1;
		for (int i = 0; hashTable[i] != NULL; i++)
		{
			node * temp;
			temp = hashTable[i];
			while (temp != NULL)
			{
				cout << count<<"\t";
				cout << temp->data << "\t" << temp->key << endl;
				temp = temp->next;
				count++;
			}
			
			
		}
	}
};
int main()
{

	string word; int ind, j = 0; string s; char *inputArray,c;
	metaphone m;
	// File Read
	char read [50];
	for (int i = 0; i < 50; i++)
	{
		read[i] = '\0';
	}
	ifstream infile;
	infile.open("I:/mainDictionary.txt");
	if (infile.fail())
	{
		cout << "Error reading file " << endl;
	}
	else
	{
		while (!infile.eof())
		{
			infile.get(c);
			if (c == ' ')
			{
				m.fillHashTable(read,3*j);
				j = 0;
				ind = 0;
			}
			else
			{
				read[j] = c;
				j++;
			}
		}
	}
	//m.display();
	cout << endl;
	infile.close();
	// User Input
	cin >> word;
	int n = word.length();
	char * input = new char[n];
	for (int i = 0; i < n; i++)
	{
		input[i] = '\0';
	}
	
	strcpy_s(input, n + 1, word.c_str());
	m.matchingWords(input);
	/*ind = m.metaphoneAlgo(input);
	cout << ind << endl;*/
	system("pause");
}