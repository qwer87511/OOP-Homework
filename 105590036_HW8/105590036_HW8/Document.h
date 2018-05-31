#pragma once
#include <string>
using namespace std;

class Document
{
    public:
        // constructors
        Document();
        Document(string);
        // setters
        void SetText(string);
        // getters
        string GetText() const;
    protected:
        // properties
        string _text;
};