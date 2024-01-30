@echo off
REM The line above prevents commands from being printed before execution

REM Type 'for /?' in command prompt for detailed help about for's options
REM Note that you should use double % sign in scripts, and single % sign in command prompt
REM For's variables should always be single-letter
SET FILENAME=YourFileName
g++ %FILENAME%.cpp -o %FILENAME%.exe
for %%t in (*.in) do (
  REM There are special forms of accessing for's variable, see `for /?`
  word <%%t >%%~nt.out || exit /b
  REM a || b means 'run a, if it fails, run b'.
  REM In the next line, if 'fc' (file compare) fails,
  REM then 'exit /b' is called (closes current batch script, but not the command prompt)
  fc %%~nt.out %%~nt.ans || echo Test case failed for %%~nt
)
echo All test done