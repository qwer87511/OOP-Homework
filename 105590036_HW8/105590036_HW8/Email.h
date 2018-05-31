#pragma once
#include "Document.h"

class Email : public Document
{
    public:
        // constructors
        Email();
        Email(string, string, string, string);
        // setters
        void SetSender(string);
        void SetRecipient(string);
        void SetTitle(string);
        // getters
        string GetSender() const;
        string GetRecipient() const;
        string GetTitle() const;
    private:
        // properties
        string _sender;
        string _recipient;
        string _title;
};
