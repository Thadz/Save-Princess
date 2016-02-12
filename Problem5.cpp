// Description
// The Prince of Persia has been thrown onto the top level of Jaffar's underground labyrinth. The labyrinth consists of h levels strictly on top of each other. Each level is split into m by n areas. Some areas have columns that support ceiling, some areas are free. The Prince can move only to free areas. To move to the level below the Prince can break the floor underneath him and jump down if there is no column underneath. Every move takes the Prince 5 seconds. A Princess is waiting for the Prince at the lowest level. Write a program that will help the Prince to save the Princess as fast as possible by finding the shortest path between them and outputting time it took the Prince to find the Princess. The structure of the labyrinth is given bellow. The Prince’s location is marked with '1', the Princess’s location is marked with '2'. ‘.’ - marks a free spot and ‘o’ marks a column.



/*Given a grid, return a solution object.
*
* A solution object is a struct that contains the following.
* = amountOfTime == an int stating how much time it took to complete the maze.
* = directions == an array of Directions that dictates the path through the maze.
* = isPossible == a boolean that says *if* there is a path through the maze.
*
* A Direction is an enum with six states {EAST, WEST, SOUTH,
* NORTH, UP, DOWN} you can access this via Problem5::Direction::NORTH etc.
*
* A ThreeDimCharArray is a std::vector<std::vector<std::vector>>>.
*/

// #include "Problem5.hpp"

// Problem5::Solution Problem5::savePrincess(ThreeDimCharArray grid)
// {
//   //Please implement this, it only returns an empty Solution object.
//   //Please delete this, its just an example of the structure of the grid.
//   char simple_grid[3][3][3] =
//     {
//       {
//         { '1', '.', '.' },
//         { 'o', 'o', '.' },
//         { '.', '.', '.' }
//       },
//       {
//         { 'o', 'o', 'o' },
//         { '.', '.', 'o' },
//         { '.', 'o', 'o' }
//       },
//       {
//         { 'o', 'o', 'o' },
//         { 'o', '.', '.' },
//         { 'o', '.', '2' }
//       }
//     };
//   Solution sn;
//   sn.amountOfTime = 0;
//   sn.directions = std::vector<Direction>();
//   sn.isPossible = true;
//   return sn;
// }

int main()
{
  return 0;
}
