#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;


void DisplayProgramHelp()
{

	std :: cout << "" << endl;

	std :: cout << "Command: /HELP or /help or -DISPLAYHELP or -displayhelp or --DISPLAYCOMMANDHELP or --displaycommandhelp \n命令: /HELP or /help or -DISPLAYHELP or -displayhelp or --DISPLAYCOMMANDHELP or --displaycommandhelp" << endl;
	std :: cout << "Function: Show command help for this program. \n功能: 显示这个程序的命令帮助" << endl;

	std :: cout << "#" << endl;

	std :: cout << "Command: -WINOFF or -winoff or --POWEROFF or --poweroff \n命令: -WINOFF 或 -winoff 或 --POWEROFF 或 --poweroff" << endl;
	std :: cout << "Function: Stop the Windows system and turn off the power. \n功能:停止Windows系统，关闭电源" << endl;

	std :: cout << "#" << endl;

	std :: cout << "Command: Command: -WINREBOOT or -winreboot or --REBOOTSTRAP or --rebootstrap \n命令: -WINREBOOT 或 -winreboot 或 --REBOOTSTRAP 或 --rebootstrap" << endl;
	std :: cout << "Function: Restart boot Windows system. \n功能:重启Windows系统" << endl;

	std :: cout << "#" << endl;

	std :: cout << "Command: -WINLOCK or -winlock or --LOGOUTUSER or --logoutuser \n 命令: -WINLOCK 或 -winlock 或 --LOGOUTUSER 或 --logoutuser" << endl;
	std :: cout << "Function: Windows system log out the current user. \n功能:Windows系统注销当前用户" << endl;

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
	//Get local unique means to set access token permissions for a specific Windows system 获取本地唯一的手段，用来设置特定Windows系统的访问令牌权限

    std :: cout << "Work Progressing: 75%" << endl;
	Sleep(1000);

	token_ps.PrivilegeCount = 1;
	token_ps.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(handle_Token,FALSE,&token_ps,0,(PTOKEN_PRIVILEGES)NULL,0);
	//Elevated Windows system token access 提升Windows系统令牌的访问权限

    std :: cout << "Work Progressing: 100%" << endl;
	Sleep(1000);

	ExitWindowsEx(EWX_SHUTDOWN|EWX_FORCE,0);
	//Stop the Windows system and turn off the power 停止Windows系统，关闭电源
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
	//Restart boot Windows system 重启Windows系统
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
	//Windows system log out the current user Windows系统注销当前用户
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

