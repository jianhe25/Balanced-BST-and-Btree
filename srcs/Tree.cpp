// Tree.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "Form1.h"


using namespace Tree;
using namespace System::Windows::Forms;

struct DATA
{
	int x, y, pos;
};

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	
	Application::Run(gcnew Form1());
	return 0;
}
