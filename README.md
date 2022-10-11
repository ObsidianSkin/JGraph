# JGraph

Disclaimer: I run it on the lab machines.

Description:
This program generates random mazes with JGraph.

[Sample 5x5 maze](maze5.jpg)

TO RUN:
- add jgraph to your path (note: must log out and back in for change to take effect)
  - append "export PATH="$PATH:/home/jplank/bin/LINUX-X86_64" to the end of "~/.zsh.path"
- run `make`
- make sure maze.sh is executable (`chmod +x maze.sh`)
- run `./maze.sh <length> <width>` to test custom mazes, or try `./maze.sh test` to generate 5 random mazes
- display image with `display <img>`
  - if I end up adding live updating, do `display -update 1 maze.jpg` to auto refresh the image

Misc. Notes:
- Black squares are the path and the whitespace is the walls.
- I originally wanted to make an interactive 3D game, but the idea was eventually pared
		down into a maze generator/solver. Being able to walk through the maze manually
		is something I would like to implement in the future (maybe even 3D!).

TODO:
- Maze generation limited to at most 5x5 right now presumably due to how I handle walls.
- Still working on the solving portion..
- Smooth live updates to display maze as it's generated.
