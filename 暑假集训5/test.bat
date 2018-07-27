@echo off
echo Problem Test
echo Data %1

set date1=%time:~0,8%
echo start:%time%
M.exe
echo end:%time%
set date2=%time:~0,8%
>%tmp%\tmp_datediff.vbs echo wscript.echo DateDiff^("s","%date1%","%date2%"^)
for /f "delims=" %%a in ('cscript //nologo %tmp%\tmp_datediff.vbs') do set diff=%%a
echo Ïà²îµÄÃëÊı£º%diff%
del %tmp%\tmp_datediff.vbs
pause
	
