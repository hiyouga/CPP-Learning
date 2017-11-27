@echo off
mode con cols=60 lines=20
title MinGW CPP compiler by hiyouga
color 09
echo Welcome to MinGW CPP compiler by hiyouga
echo Now is: %date:~0,10% %time:~0,8%
echo.
cd %cd%
echo Compiling...
if %~x1 == .cpp (
	g++ %~d1%~p1%~n1%~x1 -o %~n1
) else (
	gcc %~d1%~p1%~n1%~x1 -o %~n1
)
if %errorlevel% == 1 (
	color 0c
	echo Compiler error!
) else (
	color 0a
	echo Complete!
	echo.
	call %~d1%~p1%~n1.exe
	color 0d
)
echo.
echo.
echo Please push down to close the window.
pause>nul