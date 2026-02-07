@echo off
:: 1. Crea la carpeta bin si no existe
if not exist "bin" mkdir "bin"

:: 2. Mueve forzosamente todos los .exe a bin
move /Y *.exe bin\

:: 3. Mensaje de confirmación
echo Exes movidos a bin correctamente.