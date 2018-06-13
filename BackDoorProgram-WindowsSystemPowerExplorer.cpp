#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;


void DisplayProgramHelp()
{

	std :: cout << "" << endl;

	std :: cout << "Command: /HELP or /help or -DISPLAYHELP or -displayhelp or --DISPLAYCOMMANDHELP or --displaycommandhelp \n����: /HELP or /help or -DISPLAYHELP or -displayhelp or --DISPLAYCOMMANDHELP or --displaycommandhelp" << endl;
	std :: cout << "Function: Show command help for this program. \n����: ��ʾ���������������" << endl;

	std :: cout << "#" << endl;

	std :: cout << "Command: -WINOFF or -winoff or --POWEROFF or --poweroff \n����: -WINOFF �� -winoff �� --POWEROFF �� --poweroff" << endl;
	std :: cout << "Function: Stop the Windows system and turn off the power. \n����:ֹͣWindowsϵͳ���رյ�Դ" << endl;

	std :: cout << "#" << endl;

	std :: cout << "Command: Command: -WINREBOOT or -winreboot or --REBOOTSTRAP or --rebootstrap \n����: -WINREBOOT �� -winreboot �� --REBOOTSTRAP �� --rebootstrap" << endl;
	std :: cout << "Function: Restart boot Windows system. \n����:����Windowsϵͳ" << endl;

	std :: cout << "#" << endl;

	std :: cout << "Command: -WINLOCK or -winlock or --LOGOUTUSER or --logoutuser \n ����: -WINLOCK �� -winlock �� --LOGOUTUSER �� --logoutuser" << endl;
	std :: cout << "Function: Windows system log out the current user. \n����:Windowsϵͳע����ǰ�û�" << endl;

	std :: cout << "#" << endl;

	std :: cout << "This program is compiled by Twilight-Dream-Of-Magic" << endl;

	std :: cout << "" << endl;


	system("Pause");

}


void WidowsSystemShutDown()
{

	//DisplayProgramHelp();

	std :: cout << "From Progress: WindowsSystem --> Shut Down" << endl;
	Sleep(1000);

	HANDLE handle_Token;
	TOKEN_PRIVILEGES token_ps;

    std :: cout << "Work Progressing: 25%" << endl;
	Sleep(1000);

	if(!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,&handle_Token))
    {
        return;
    }

    std :: cout << "Work Progressing: 50%" << endl;
	Sleep(1000);

	LookupPrivilegeValue(NULL,SE_SHUTDOWN_NAME,&token_ps.Privileges[0].Luid);
	//Get local unique means to set access token permissions for a specific Windows system ��ȡ����Ψһ���ֶΣ����������ض�Windowsϵͳ�ķ�������Ȩ��

    std :: cout << "Work Progressing: 75%" << endl;
	Sleep(1000);

	token_ps.PrivilegeCount = 1;
	token_ps.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(handle_Token,FALSE,&token_ps,0,(PTOKEN_PRIVILEGES)NULL,0);
	//Elevated Windows system token access ����Windowsϵͳ���Ƶķ���Ȩ��

    std :: cout << "Work Progressing: 100%" << endl;
	Sleep(1000);

	ExitWindowsEx(EWX_SHUTDOWN|EWX_FORCE,0);
	//Stop the Windows system and turn off the power ֹͣWindowsϵͳ���رյ�Դ
}

void WidowsSystemResetBoot()
{

	//DisplayProgramHelp();

	std :: cout << "From Progress: WindowsSystem --> Reset Boot" << endl;
	Sleep(1000);

	HANDLE handle_Token;
	TOKEN_PRIVILEGES token_ps;

	std :: cout << "Work Progressing: 25%" << endl;
	Sleep(1000);

	if(!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,&handle_Token))
	{
        return;
	}

	std :: cout << "Work Progressing: 50%" << endl;
	Sleep(1000);

	LookupPrivilegeValue(NULL,SE_SHUTDOWN_NAME,&token_ps.Privileges[0].Luid);

	std :: cout << "Work Progressing: 75%" << endl;
	Sleep(1000);

	token_ps.PrivilegeCount = 1;
	token_ps.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(handle_Token,FALSE,&token_ps,0,(PTOKEN_PRIVILEGES)NULL,0);

	std :: cout << "Work Progressing: 100%" << endl;
	Sleep(1000);

	ExitWindowsEx(EWX_REBOOT|EWX_FORCE,0);
	//Restart boot Windows system ����Windowsϵͳ
}

void WidowsSystemLogoutUser()
{

	//DisplayProgramHelp();

    std :: cout << "From Progress: WindowsSystem --> Logout User" << endl;
	Sleep(1000);

	HANDLE handle_Token;
	TOKEN_PRIVILEGES token_ps;

    std :: cout << "Work Progressing: 25%" << endl;
	Sleep(1000);

	if(!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,&handle_Token))
	{
		return;
	}

	std :: cout << "Work Progressing: 50%" << endl;
	Sleep(1000);

	LookupPrivilegeValue(NULL,SE_SHUTDOWN_NAME,&token_ps.Privileges[0].Luid);

	std :: cout << "Work Progressing: 75%" << endl;
	Sleep(1000);

	token_ps.PrivilegeCount = 1;
	token_ps.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(handle_Token,FALSE,&token_ps,0,(PTOKEN_PRIVILEGES)NULL,0);

	std :: cout << "Work Progressing: 100%" << endl;
	Sleep(1000);

	ExitWindowsEx(EWX_LOGOFF|EWX_FORCE,0);
	//Windows system log out the current user Windowsϵͳע����ǰ�û�
}

int main(int argc, char* argv[])
{

	if(!strcmp(argv[1],"-WINOFF"))
	{
		WidowsSystemShutDown();
	}
	if(!strcmp(argv[1],"-WINREBOOT"))
	{
		WidowsSystemResetBoot();
	}
	if(!strcmp(argv[1],"-WINLOCK"))
	{
		WidowsSystemLogoutUser();
	}

	if(!strcmp(argv[1],"-winoff"))
	{
		WidowsSystemShutDown();
	}
	if(!strcmp(argv[1],"-winreboot"))
	{
		WidowsSystemResetBoot();
	}
	if(!strcmp(argv[1],"-winlock"))
	{
		WidowsSystemLogoutUser();
	}

	if(!strcmp(argv[1],"--POWEROFF"))
	{
		WidowsSystemShutDown();
	}
	if(!strcmp(argv[1],"--REBOOTSTRAP"))
	{
		WidowsSystemResetBoot();
	}
	if(!strcmp(argv[1],"--LOGOUTUSER"))
	{
		WidowsSystemLogoutUser();
	}

	if(!strcmp(argv[1],"--poweroff"))
	{
		WidowsSystemShutDown();
	}
	if(!strcmp(argv[1],"--rebootstrap"))
	{
		WidowsSystemResetBoot();
	}
	if(!strcmp(argv[1],"--logoutuser"))
	{
		WidowsSystemLogoutUser();
	}

	if(argc = 2 && strcmp(argv[1],"/HELP") == 0)
	{
		DisplayProgramHelp();
	}
	if(argc = 2 && strcmp(argv[1],"-DISPLAYHELP") == 0)
	{
		DisplayProgramHelp();
	}
	if(argc = 2 && strcmp(argv[1],"--DISPLAYCOMMANDHELP") == 0)
	{
		DisplayProgramHelp();
	}

	if(argc = 2 && strcmp(argv[1],"/help") == 0)
	{
		DisplayProgramHelp();
	}
	if(argc = 2 && strcmp(argv[1],"-displayhelp") == 0)
	{
		DisplayProgramHelp();
	}
	if(argc = 2 && strcmp(argv[1],"--displaycommandhelp") == 0)
	{
		DisplayProgramHelp();
	}

  return 0;
}

