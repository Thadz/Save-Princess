// Description
// The Prince of Persia has been thrown onto the top level of Jaffar's
// underground labyrinth. The labyrinth consists of h levels strictly on top of
// each other. Each level is split into m by n areas. Some areas have columns
// that support ceiling, some areas are free. The Prince can move only to free
// areas. To move to the level below the Prince can break the floor underneath
// him and jump down if there is no column underneath. Every move takes the
// Prince 5 seconds. A Princess is waiting for the Prince at the lowest level.
// Write a program that will help the Prince to save the Princess as fast as
// possible by finding the shortest path between them and outputting time it
// took the Prince to find the Princess. The structure of the labyrinth is given
// bellow. The Prince’s location is marked with '1', the Princess’s location is
// marked with '2'. ‘.’ - marks a free spot and ‘o’ marks a column.

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

#include "Problem5.hpp"

std::shared_ptr<Problem5::Solution> Problem5::savePrincess(const ThreeDimCharArray& grid)
{
  auto princePosition = getFigurePosition(Figure::PRINCE, grid);
  // assume princess is always below prince
  auto solution = std::make_shared<Solution>();
  State state { princePosition };
  std::vector<State> states = { state };
  // not using unordere_set because vector
  // is usally faster with the aid of cache
  std::vector<State> rejected = {};
  // BFS for the shortest path search.
  while (!states.empty())
  {
    auto s = states.front();
    states.erase(states.begin());
    auto level = std::get<0>(s.position);
    auto x = std::get<1>(s.position);
    auto y = std::get<2>(s.position);
    // base cases; if the position is out of range or at column then reject;
    // if the position matches the princess', the return;
    // otherwise at the empty area, safely proceed.
    if (0 > level || static_cast<int32_t>(grid.size())       == level ||
        0 > x     || static_cast<int32_t>(grid[0].size())    == x     ||
        0 > y     || static_cast<int32_t>(grid[0][0].size()) == y     ||
        Figure::COLUMN == grid[level][x][y])
    {
      rejected.push_back(s);
      continue;
    }
    if (Figure::PRINCESS == grid[level][x][y])
    {
      mkSolution(*solution.get(), s.directions);
      return solution;
    }
    // induction; try different moves.
    State east;
    moveEast(east, s);
    states.push_back(east);
    State west;
    moveWest(west, s);
    states.push_back(west);
    State north;
    moveNorth(north, s);
    states.push_back(north);
    State south;
    moveSouth(south, s);
    states.push_back(south);
    State down;
    moveDown(down, s);
    states.push_back(down);
  }
  return solution;
}

int main()
{
  // Please implement this, it only returns an empty Solution object.
  // Please delete this, its just an example of the structure of the grid.
  Problem5::ThreeDimCharArray grid
    {
      {
        { '1', '.', '.' },
        { 'o', 'o', '.' },
        { '.', '.', '.' }
      },
      {
        { 'o', 'o', 'o' },
        { '.', '.', 'o' },
        { '.', 'o', 'o' }
      },
      {
        { 'o', 'o', 'o' },
        { 'o', '.', '.' },
        { 'o', '.', '2' }
      }
    };
  auto solution = Problem5::savePrincess(grid);
  std::cout << solution << "\n";
  return 0;
}
