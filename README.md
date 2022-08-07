# unnamed stealth game

Currently without all the stealth

## what is it?

This is a malgamation of two separate projects I spun up to try different things.

The first was having multiple or 'separate' screens in one window. Think mini-map, or character stats.

I wanted something a bit more involved than a simple health bar, but it's still nothing too complex. The 'action-text'
on the right hand side of the screen is an example of that.

The second project was to help organise my code better through the use of game state. I have previously used an enum for this,
but wanted something with a bit more structure. I am still using an enum, but now have it linked to a State abstract class,
and for each class which inherits that class, they have their own update and draw methods.

This means in the 'main.cpp' file a very clean switch statement can be used, and since the enum typed state var inside of the superclass
State is static, all 'state' classes share the current state of the game, and can see what it is, and change it if needed! Phew!

## So... now what?

Honestly? Not sure. I've acheived what I set out to do, so my plan now is to add in a game-loop of sorts so that it's a bit more well-rounded
than some systems thrown together!

## What's it built with?

C++ and Raylib-CPP

If you want to run it, download it and a copy of raylib-cpp-starter here on GitHub, add the Makefile and type 'make' I've only tested it
on Linux, but it should run on any system with Raylib installed.
