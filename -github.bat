@echo off
echo Name the commit:
set /p commit=
git add .
echo Committing
git commit -m "%commit%"
echo Pushing
git push -u origin master
echo Done