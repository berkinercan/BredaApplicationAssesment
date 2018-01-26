# Game Theme : Reflections
This repository contains my attempt to write a game with C++ using SDL Library. 

# The Idea
My idea was to move around with a character and move mirrors to direct the laser source to it's destination. 

# The progress
I have managed to implement main character with the ability to move around.

In order to do that, I have followed the following reddit post; "https://www.reddit.com/r/learnprogramming/comments/3x7sqb/learn_to_make_a_2d_game_in_c/" 

It is a step by step video tutorial series that implements a game called "Cavestory". Even though Cavestory and my game have nothing in common, I found the tutorials well organized and educational. That why I have decided to code along until my ideas and cavestory start to differ.

I got stuck on the part, where I am supposed to draw a mirror on the map. Even though I have followed exactly the same steps to draw the player, I could not manage to draw a mirror on the screen. 

# Implementation Details 
For the implementation, I have used C++ as the programming language. For the assets, I have used the files on  "http://www.cavestory.org/download/cave-story.php". The Graphics Library that I have used is SDL2.0.

## The Classes:
* Input.cpp - responsible from reading the keyboard inputs with SDL Library
* Game.cpp - responsible from getting the inputs and calling the necessary movement functions for the player object.
* Player.cpp - represents the player object. It reads the png file for the character and animation details.

# Challenges
Attempting to implemet a game is a very detailed and rewarding task. The following tasks was very challenging for me;
* Using the Visual Studio IDE comprehensively (Tutorial shows the steps for Eclipse, I was not always the same steps for Visual Studio)
* Importing SDL Library and the linker setup
*  Drawing additional game objects. I believe I could have succeded on this challenge as well, If I could have more time. 
