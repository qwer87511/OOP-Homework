#include "Document.h"

// constructor
Document::Document()
{
}
Document::Document(string text) : _text(text)
{
}
// setter
void Document::SetText(string text)
{
    this->_text = text;
}
// getter
string Document::GetText() const
{
    return this->_text;
}