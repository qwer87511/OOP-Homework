// ��u�G 105590036 ���T�� HW8
// ��@ class ���~�ӡA�H�`�ٵ{���X�A�F��{���X�����ƧQ��
#include "Email.h"
#include "File.h"

bool ContainsKeyword(const Document& docObject, string keyword)
{   // �ˬd�O�_�]�t����r
    if (docObject.GetText().find(keyword) != string::npos)
        return true;

    return false;
}
int main()
{
    Email emailObj;
    return ContainsKeyword(emailObj, "c++");
}