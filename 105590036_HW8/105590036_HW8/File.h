#pragma once
#include "Document.h"

class File : public Document
{
    public:
        // constructors
        File();
        File(string, string);
        // setters
        void SetPathName(string);
        // getters
        string GetPathName() const;
    private:
        // properties
        string _pathName;
};