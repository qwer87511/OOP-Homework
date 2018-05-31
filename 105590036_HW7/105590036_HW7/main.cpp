#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

bool CheckSyntax(string sentence, int size)
{   // 檢查語法
    if (!isupper(sentence[0]))
    {   // 需大寫開頭
        cout << "需以大寫字母開頭" << endl << endl;
        return false;
    }

    for (int i = 1; i < size; ++i)
    {   // 只能為英文或空白
        if (!isalpha(sentence[i]) && sentence[i] != ' ')
        {
            cout << "只能輸入英文或空白" << endl << endl;
            return false;
        }
    }

    return true;
}
string GetSentence()
{   // get sentence
    while (1)
    {
        cout << "Please input a sectence: ";
        string sentence;
        getline(cin, sentence);

        if (CheckSyntax(sentence, sentence.size()))
            return sentence;
    }
}
string TranslatePigLatin(string word)
{   // translate
    if (string("AaEeIiOoUu").find(word[0]) == string::npos) //開頭非母音
        word = word.substr(1) + word[0] + "ay";
    else //母音開頭
        word += "way";

    return word;
}
string ToPigLatin(string sentence)
{
    string pigLatin; //存放翻譯結果
    int len = sentence.find_last_not_of(' ') + 1; // *****為防止後面有多的空格，長度設為最後一個空格*****
    int head; // 單字開頭之index
    int rear(-1); // 單字結尾之index

    while (rear != len) // 結尾為最後一個單字時離開
    {
        head = sentence.find_first_not_of(' ', rear + 1); // 從前一個單字後的下一個位置開始，尋找第一個非空白者為單字開頭(過濾多的空白)
        rear = sentence.find(' ', head); // 單字結尾為開頭後第一個空白處

        if (rear == string::npos) rear = len; // 若沒有找到空白表示剩下最後一個單字

        pigLatin += TranslatePigLatin(sentence.substr(head, rear - head)) + " "; // 逐字翻譯
    }

    return pigLatin;
}
string ToUpperLeading(string str)
{   // 轉成大寫字母開頭，其餘小寫
    int len = str.size();
    str[0] = toupper(str[0]);

    for (int i = 1; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }

    return str;
}
int main()
{
    while (1)
    {
        string sentence = GetSentence(); // read input

        if (sentence == "Exit") break; // exit

        string pigLatin = ToPigLatin(sentence); // transform Pig Latin
        cout << "Pig Latin sentence: " << ToUpperLeading(pigLatin) << endl << endl; // to upper leading, others are lower
    }

    system("pause");
    return 0;
}