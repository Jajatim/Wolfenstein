# Wolfenstein

Multiplatform compile & run checklist :
- Win7      : 12/05/2019
- Win10     : 28/05/2019
- OSX       : 10/05/2019
- Linux     : (untested yet)

Tools needed :
- Compiler : gcc (with the help of make)
- Source manager : Git
- Extern libraries : SDL2 (installation not needed for Windows)

Tools used :
- Project platform : github (link : https://github.com/Jajatim/Wolfenstein)
- Text editors : VSCode Studio (Windows), Vim (OSX)


*********************************
*********** CHANGELOG ***********
*********************************

28/05/2019
Status :
Project is evolving fast and slowly gets ready for phase 1 (main tools only, no features) tests and validation.
I will be away for 4 months, so the project might stagnate for a little while as I'm not sure I'll find the time to work on it.

Update notes :
Main loop seems fine for now, game state change still some work (especially on the substate part), project architecture seems stable (although the .o files are annoying...), Makefile only needs a dependency check (.d files) that I don't know yet how to implement.
Config file and user input need validation, but looks correct for now.
Next large parts will be the options menu, and the ingame menu as they will raise questions on the main loop and game state change when being realized.
An interesting side project to work on now would be a map generator as the .map files are unreadable (also, maybe making them readable is maybe a good idea...) and different maps would be cool when I get bored of writing code. Also, game will some day need to be able to load different maps according to parameters, which would help when this part comes up.

*********************************

29/04/2019
Status :
Project has not begun yet...

Update notes :
This is the start of this project on Github. So far, not much has been done : a test program to try and work on raycasting (seems like it is working, though the code is unreadable...), and a rework program to try and make the project for real (not much added except the menu loop).
Both these programs were made on OSX and therefore may not compile on Windows and Linux...

Content :
- wolfnogit contains only a test file that was meant test the graphic thingy. R to make it rain, T to make it snow, WASD to move around.
- returntocastleoneohone contains the first try to rework this project into a real (and readable one). Depending on the team working, it will serve as a basis or be forgotten in the pool of old stuff behind the fridge.
