#include "Email.h"

// constructor
Email::Email()
{
}
Email::Email(string sender, string recipient, string title, string text)
    : _sender(sender), _recipient(recipient), _title(title), Document(text)
{
}
// setter
void Email::SetSender(string sender)
{
    this->_sender = sender;
}
void Email::SetRecipient(string recipient)
{
    this->_recipient = recipient;
}
void Email::SetTitle(string title)
{
    this->_title = title;
}
// getter
string Email::GetSender() const
{
    return this->_sender;
}
string Email::GetRecipient() const
{
    return this->_recipient;
}
string Email::GetTitle() const
{
    return this->_title;
}