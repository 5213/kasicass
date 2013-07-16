#include "ExportVertex.hpp"

// ������������
// name, filename
// ei, ���ڱ�����������
// i, ���ڵ���3dmax��һЩ�ӿ�
// options, ͬSupportsOptions
// ����ֵ, IMPEXP_FAIL/IMPEXP_SUCCESS/IMPEXP_CANCEL
int ExportVertex::DoExport(const TCHAR *name, ExpInterface *ei, Interface *i, BOOL suppressPrompts, DWORD options)
{
    ::MessageBox(NULL, name, _T("Export it!"), MB_OK);
    return IMPEXP_SUCCESS;
}

// ���Plugin�Ƿ�֧��ĳ������
// options, Ŀǰֻ�� SCENE_EXPORT_SELECTED(����ѡ������) ��ôһ��ѡ��
BOOL ExportVertex::SupportsOptions(int ext, DWORD options)
{
    if (ext == 0 && options == SCENE_EXPORT_SELECTED)
        return TRUE;

    return FALSE;
}
