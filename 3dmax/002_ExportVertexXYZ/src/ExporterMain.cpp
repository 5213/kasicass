#include "ExporterMain.hpp"
#include "VertexProcessor.hpp"

// ������������
// name, filename
// ei, ���ڱ�����������
// i, ���ڵ���3dmax��һЩ�ӿ�
// options, ͬSupportsOptions
// ����ֵ, IMPEXP_FAIL/IMPEXP_SUCCESS/IMPEXP_CANCEL
int KSMeshExporter::DoExport(const TCHAR *name, ExpInterface *ei, Interface *i, BOOL suppressPrompts, DWORD options)
{
	FILE *out = fopen(name, "w+");
	if (!out)
	{
		std::ostringstream emsg;
		emsg << "Can't open output file: " << name;
		::MessageBox(NULL, emsg.str().c_str(), "Error!", MB_OK);
		return IMPEXP_FAIL;
	}

	VertexProcessor processor(i->GetTime(), out);

	IScene *scene = ei->theScene;
    scene->EnumTree(&processor); 

	fclose(out);

    return IMPEXP_SUCCESS;
}

// ���Plugin�Ƿ�֧��ĳ������
// options, Ŀǰֻ�� SCENE_EXPORT_SELECTED(����ѡ������) ��ôһ��ѡ��
BOOL KSMeshExporter::SupportsOptions(int ext, DWORD options)
{
    if (ext == 0 && options == SCENE_EXPORT_SELECTED)
        return TRUE;

    return FALSE;
}
