## Structure 
````
Control -> Handles switching from running mode (displaying clock) to configuration mode (entering passwords)
Networking -> provides functionality for sending and receiving data opening and connecting to WiFi
ClockControl -> Handles the actual clock displaying 
Misc->Misc functionality like helpers e.g. EEPROM Storage abstraction
````
## Helpful Stuff
1. code structure: Fast alles ist mit namespaces und functions und structs global namespaces und singleton pattern gemacht 
1. pointer werden vermieden
1. die wortuhr.drawio.png gibt nen groben überblick über imports. Solltest du mal was importieren und der haut dir massig errors liegt es wahrscheinlich an nem circular import und cpps unfähigkeit diese zu preventen (Ja es ist über macros möglich. mach ichs, vielleicht). Einfach die imports scannen
1. Ich versuche so viel wie möglich zu testen. Das testing framework hat den bug das es keine functions in namespaces ausführt. das Danger Zone in der misc_test.cpp ist dafür da da es 1. lange dauert und 2. den EEPROM nach und nach kaputt macht. Deswegen ist das ständige ausführen nicht zu empfehlen im notfall einfach die test runner auskommentieren. 
1. Alles wurde in header files definiert und implementiert um linker errors zu vermeiden 
1. Stand jetzt benutze ich für alles nicht statische (SSIDS oder so) die arduino String da die auf dem stack ist und man nifty Operationen mit machen kann. die c_str() Funktion konvertiert eine Arduino string zu nem const char*
1. Lad dir das drawio vscode plugin runter damit kannst du in vscode Änderungen an drawio machen meines Wissens auch an pngs
1. Wenn du nen problem mit irgendwas hast wie bugs etc mach nen issue auf und schreibe es mir per WhatsApp oder so. Das ticket aber nicht vergessen sonst vergesse ich das ich was tun muss