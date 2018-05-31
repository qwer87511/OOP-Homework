// 資工二 105590036 黃俊維 HW8
// 實作 class 的繼承，以節省程式碼，達到程式碼之重複利用
#include "Email.h"
#include "File.h"

bool ContainsKeyword(const Document& docObject, string keyword)
{   // 檢查是否包含關鍵字
    if (docObject.GetText().find(keyword) != string::npos)
        return true;

    return false;
}
int main()
{
    Email emailObj;
    return ContainsKeyword(emailObj, "c++");
}