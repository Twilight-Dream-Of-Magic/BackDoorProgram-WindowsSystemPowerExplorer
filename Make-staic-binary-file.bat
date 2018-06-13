@echo off

color 1A

cd /d %~dp0

cls

if exist ".\\BackDoorProgram-WindowsSystemPowerExplorer.cpp" (

goto Compile

) else (

echo "Error: source code file lost or file not exist this path !"

pause

goto End
	
)

:Compile

echo "---------- Code Compile Start ----------"

:: g++.exe -shared -o
:: -fexec-charset=GB2312

g++.exe -O2 -c -Wall ".\\BackDoorProgram-WindowsSystemPowerExplorer.cpp" -o ".\\Objectives\\Release\\BackDoorProgram-WindowsSystemPowerExplorer_Static.o"

echo "---------- Code Compiling ----------"

:: g++.exe -finput-charset=UTF-8

g++.exe -static -Wall ".\\Objectives\\Release\\BackDoorProgram-WindowsSystemPowerExplorer_Static.o" -o ".\\Binary\\Release\\BackDoorProgram-WindowsSystemPowerExplorer_Static.exe"

echo "---------- Code Compile End ----------"

pause

goto End

:End

cls

exit