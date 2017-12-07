@echo off
mode con cols=65 lines=35

cd %cd%

call sortwords.exe sort.in sort.out

echo Please push down to close the window.
pause>nul