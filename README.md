# JGraph

Disclaimer: I run it on the lab machines.

TO RUN:
- add jgraph to your path (note: must log out and back in for change to take effect)
  - append "export PATH="$PATH:/home/jplank/bin/LINUX-X86_64" to the end of "~/z.sh.path"
- run `make`
- make sure maze.sh is executable (`chmod +x maze.sh`)
- run `./maze.sh <length> <width>`

Misc. Notes:
- I originally wanted to make an interactive 3D game, but the idea was eventually pared
		down into a maze generator/solver. Being able to walk through the maze manually
		is something I would like to implement in the future (maybe even 3D!).
