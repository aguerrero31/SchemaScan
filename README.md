# SchemaScan

WORK IN PROGRESS, not yet functional

 An Electronics Schematic (.pdf) parser written primarily in C++. Contains a library (SchemaScanLib), a Console Application (SchemaScanConsole), and a GUI Application (SchemaScan, not yet implemented). This was created to aid in searching electronics schematics for specific parts (or whatever you want, really).

 Features:
 - Scanning and parsing of Electronics Schematics (.pdf files)
 - Data caching using JSON to speed up search times and avoid long scanning times each time the app is used
 - Options to re-scan and or overwrite current cached files
 - Searching for cached or scanned schematics
 - More coming soon!

 Currently the GUI app will be Windows only, but I have plans for Linux/Mac in the future.

 Cache path is currently set to user/AppData/Local/SchemaScan/cache for Windows

 Library Requirements:
 - PoDoFo
 - hashlib2plus
 - nlohmann json
