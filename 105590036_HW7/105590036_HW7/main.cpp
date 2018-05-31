#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

bool CheckSyntax(string sentence, int size)
{   // �ˬd�y�k
    if (!isupper(sentence[0]))
    {   // �ݤj�g�}�Y
        cout << "�ݥH�j�g�r���}�Y" << endl << endl;
        return false;
    }

    for (int i = 1; i < size; ++i)
    {   // �u�ର�^��Ϊť�
        if (!isalpha(sentence[i]) && sentence[i] != ' ')
        {
            cout << "�u���J�^��Ϊť�" << endl << endl;
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
    if (string("AaEeIiOoUu").find(word[0]) == string::npos) //�}�Y�D����
        word = word.substr(1) + word[0] + "ay";
    else //�����}�Y
        word += "way";

    return word;
}
string ToPigLatin(string sentence)
{
    string pigLatin; //�s��½Ķ���G
    int len = sentence.find_last_not_of(' ') + 1; // *****������᭱���h���Ů�A���׳]���̫�@�ӪŮ�*****
    int head; // ��r�}�Y��index
    int rear(-1); // ��r������index

    while (rear != len) // �������̫�@�ӳ�r�����}
    {
        head = sentence.find_first_not_of(' ', rear + 1); // �q�e�@�ӳ�r�᪺�U�@�Ӧ�m�}�l�A�M��Ĥ@�ӫD�ťժ̬���r�}�Y(�L�o�h���ť�)
        rear = sentence.find(' ', head); // ��r�������}�Y��Ĥ@�ӪťճB

        if (rear == string::npos) rear = len; // �Y�S�����ťժ�ܳѤU�̫�@�ӳ�r

        pigLatin += TranslatePigLatin(sentence.substr(head, rear - head)) + " "; // �v�r½Ķ
    }

    return pigLatin;
}
string ToUpperLeading(string str)
{   // �ন�j�g�r���}�Y�A��l�p�g
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