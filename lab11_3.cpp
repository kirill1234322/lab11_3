// lab11_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	HANDLE hEvent = CreateEvent(0, TRUE, FALSE, TEXT("lab11_3.exe"));
	if (hEvent)
	{
		if (GetLastError() != ERROR_ALREADY_EXISTS)
		{
			const int numOfProc = 3;

			PROCESS_INFORMATION pi[numOfProc];

			TCHAR szCmdLine[MAX_PATH] = { 0 };
			GetModuleFileName(0, szCmdLine, MAX_PATH);

			for (int i = 0; i < 3; i++)
			{
				STARTUPINFO si;
				memset(&si, 0, sizeof(si));
				if (!CreateProcess(szCmdLine, 0, 0, 0, FALSE, CREATE_NEW_CONSOLE, 0, 0, &si, &pi[i]))
					
				cout << "Ошибка создания процесса\n" << endl;
			}

			for (int i = 0; i < numOfProc; i++)
			{
				if (pi[i].hProcess)
				{
					WaitForSingleObject(pi[i].hProcess, INFINITE);
				}
			}
		}
		else
		{

			for (int i = 0; i <= 10; i++)
			{
				WaitForSingleObject(hEvent, 1000);
				cout << i <<" ";
			}
			WaitForSingleObject(hEvent, 20000);

			Sleep(3000);
		}
	}
	

}

