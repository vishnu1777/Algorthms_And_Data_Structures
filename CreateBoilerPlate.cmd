@echo off
set /p target= "Enter the folder name you want to copy:"
ROBOCOPY /s "D:\Algorthms_And_Data_Structures\BoilerPlate-Test" "D:\Algorthms_And_Data_Structures\%target%" /mir