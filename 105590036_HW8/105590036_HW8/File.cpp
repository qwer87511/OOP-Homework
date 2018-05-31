#include "File.h"

//constructor
File::File()
{
}
File::File(string pathName, string text) : _pathName(pathName), Document(text)
{
}
// setter
void File::SetPathName(string pathName)
{
    this->_pathName = pathName;
}
// getter
string File::GetPathName() const
{
    return this->_pathName;
}