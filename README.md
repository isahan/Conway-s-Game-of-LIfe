Conway-s-Game-of-LIfe
=====================
The "game" is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.
One interacts with the Game of Life by creating an initial configuration and observing how it evolves.

I have the game set up to run on the command line.
You can choose the number of rows and columns you want for the game and it sets up a random collection of live and dead cells.
Then once you start, the Conway's game of Life rules start, which are:

Any live cell with fewer than two live neighbours dies, as if caused by under-population.
Any live cell with two or three live neighbours lives on to the next generation.
Any live cell with more than three live neighbours dies, as if by overcrowding.
Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.


I also have Unit tests that for simplicities sake, I have included in the main function, which show some of the patterns. 

