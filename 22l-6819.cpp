#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

// Function to remove a word from a string
void eraseWordFromString(string& str, const string& word)
{
    size_t pos = str.find(word);

    while (pos != string::npos)
    {
        str.erase(pos, word.length());

        if (pos < str.length() && str[pos] == ' ') 
        {
            str.erase(pos, 1);
        }

        pos = str.find(word, pos);
    }
}

// Function to count word frequencies in a file
void countWordFrequencies(const string& filename) 
{
    unordered_map<string, int> wordFrequency;

    ifstream file(filename);
    stringstream buffer;
    buffer << file.rdbuf();
    string fileContent = buffer.str();
    file.close();

    string word;
    istringstream iss(fileContent);
    
    while (iss >> word)
    {
        word.erase(remove_if(word.begin(), word.end(), [](char c) 
            {
            return !isalnum(c) && c != '\'';
            }), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (!word.empty())
        {
            wordFrequency[word]++;
        }
    }

    cout << "Number of unique words in the text: " << wordFrequency.size() << endl;

    cout << "Enter a word to get its frequency or press enter to exit: " << endl;
    string userInput;
    while (getline(cin, userInput))
    {
        if (userInput.empty())
        {
            cout << "Exiting the program..." << endl;
            break;
        }
        else if (userInput[0] == '-') 
        {
            string wordToDelete = userInput.substr(1);
            if (wordFrequency.erase(wordToDelete) == 1) 
            {
                cout << "\"" << wordToDelete << "\" has been removed." << endl;
            }
            else
            {
                cout << "\"" << wordToDelete << "\" does not exist." << endl;
            }
            eraseWordFromString(fileContent, wordToDelete);
        }
        else
        {
            transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
            int freq = wordFrequency.count(userInput) ? wordFrequency[userInput] : 0;
            cout << "\"" << userInput << "\" appears " << freq << " times." << endl;
        }
    }

    ofstream outFile(filename);
    outFile << fileContent;
    outFile.close();
}

int main()
{
    string fileName = "input.txt"; // Change this to your input file
    countWordFrequencies(fileName);
    return 0;
}
