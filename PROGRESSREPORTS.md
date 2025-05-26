# Progress Reports

### 26/05/25 (ver 0.1.2)
- Added the logic for the *Merchant* event and optimized the way it gives two objects to be simpler. Needs only to replace the placeholder rewards, and add a fallback if they already have the objects.
- Added events to the gameplay description in the *README* file.
- Added a default value of 1000ms to the *sleep* function to make it easier to add breaks.
- Learnt that ***reset*** is how you go back to one of your ealier commits (undoing all commits after that) because I commited the wrong files.

### 25/05/25 (ver 0.1.1)
- Layed out all the basic logic for the *Dungeon* event and improvent and balanced it a bit from how it was before. Now need to add all the details for the monsters, rewards and ui.
- I think im going to need to add another abstract and child class for better scalability. A abstract *character* class from which the *players* and new *monsters* classes can extend from.

### 24/05/25 (ver 0.1.0)
- After about 4 hours I finally got the github to work! I added a *progress reports*, *change log* and *readme* alongside all the header and source files
- Since the project is still very bare bones I'll focus more on building it out before diving into github again
- Aim to do 3-8 hours a week on this since I just started some CS50 courses which I'm making the higher priority

## Begining state of Project
- Just started rewriting my origin program into a file system which is new to me
- Started refactoring all the major systems into Classes for easier use as the project expands
- Have transitioned most of the basic functions into their respective files and made some minor improvements for scalability but almost none of the old objects have been added yet
- Yet to transitioned all the game loop logic and the events
- Hope to build a large strategic game and then transition it to a GUI system
