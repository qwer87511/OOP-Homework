#include "stdafx.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

//
// �ե󪺤@���T�O�ѤU�C���ݩʶ�����C
// �ܧ�o���ݩʪ��ȧY�i�ק�ե󪺬���
// ��T�C
//
[assembly:AssemblyTitleAttribute(L"GitTutorial")];
[assembly:AssemblyDescriptionAttribute(L"")];
[assembly:AssemblyConfigurationAttribute(L"")];
[assembly:AssemblyCompanyAttribute(L"")];
[assembly:AssemblyProductAttribute(L"GitTutorial")];
[assembly:AssemblyCopyrightAttribute(L"Copyright (c)  2018")];
[assembly:AssemblyTrademarkAttribute(L"")];
[assembly:AssemblyCultureAttribute(L"")];

//
// �ե󪺪�����T�ѤU�C�|�ӭȩҲզ�: 
//
//      �D�n����
//      ���n����
//      �իؽs��
//      �׭q�s��
//
// �z�i�H���w�Ҧ����ȡA�]�i�H�̷ӥH�U���覡�A�ϥ� '*' �N�׭q�M�իؽs��
// ���w���w�]��: 

[assembly:AssemblyVersionAttribute("1.0.*")];

[assembly:ComVisible(false)];

[assembly:CLSCompliantAttribute(true)];