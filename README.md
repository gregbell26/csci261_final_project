# Rock Paper Scissors RPG
I will be writing a RPG game with two main sections, a gym and a final battle arena. The game will track the adventures of a human player as they go from some shleb who has never played rock paper scissors before to a power being ready to take on the evil Dr. Paper who wants to harvest and destroy all the scissors in the world so he can be invincible. The user will be able to train with people in the gym and purchase power ups that might help them in later fights. However, the more they train, the better the Dr. Paper will be as he will learn the player’s habits. The user will interact with the game in a pokemon-esk user interface that will be drawn to terminal.


# Update
So that didn't quite work out! During the development process, I realized major issues with the library I wanted to use to actually display the user interface to the user. 
So.. I shifted gears to make the library that I wanted.

Basically this project is a command line renderer by the name of Console Buddy. It allows images to be read from the disk (currently only PPM P3 is supported), and renders them on the console.

In its current state, there are many issues. However, as this was developed in 2 weeks for Windows 10, many concessions have been made to ensure a working alpha for Windows 10. 

There are a few issues of note: 
- On all non windows systems, the 'pixels' render as question marks. This is due to how different compilers handle the char type. On Windows, it is an 8 bit number where as on basically every other platform it is a 7 bit number. Furture implementations will use unicode over acsii to avoid this issue.
- On Windows 11, the buffer does not clear correctly. Microsoft changed thier implementation of the alernate screen buffer in the SDK without updating thier documantion. More research is required as to how to fix this issue.
- On some consoles that have TrueColor support, the colors render incorrectly. More research is required to fix this issue but I think it partially stems from the overflow issue with ascii and how I am sending escape sequences to the terminal.
- For some reason, when loading textures from files, only the last one is rendered. I beleive this is evidence of a memory issue but more investation is required. 
- This is super inefficient with memory. A major overhaul into how the memory is managed internally is required. 

As I stated before, due to the short development cycle of this project and that only one platform had to be supported, and that these issues are inconsolal for the proof of concept, I am ok with them for this demo. With that said, I intend to continue development of this project and flesh out its functionality after re-designing the architecture. This development will take place in a different repo.
