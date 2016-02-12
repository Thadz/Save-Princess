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

#include "Problem5.hpp"
#include <iostream>

Problem5::Solution Problem5::savePrincess(const ThreeDimCharArray grid)
{
  std::shared_ptr<Solution> p_solution(new Solution);
  p_solution.get()->amountOfTime = 0u;
  p_solution.get()->directions = std::vector<Direction>();
  p_solution.get()->isPossible = false;

  auto princePosition = getFigurePosition(Figure::PRINCE, grid);
  auto princessPosition = getFigurePosition(Figure::PRINCESS, grid);

  // If princess stands above prince, then it is impossible
  if (std::get<0>(princessPosition) < std::get<0>(princePosition)) {
    return *p_solution.get();
  }

  return *p_solution.get();
}

std::vector<std::shared_ptr<Problem5::Solution>>
Problem5::savePrincessRecursion(const Position currentPrincePosition,
                                std::shared_ptr<Problem5::Solution> currentSolution,
                                const ThreeDimCharArray grid)
{
  // base cases
  
  // induction
  // auto solutions = std::vector<Solution>();

  return std::vector<std::shared_ptr<Solution>>();
}

Problem5::Position Problem5::getFigurePosition(Figure figure,
                                               const ThreeDimCharArray grid)
{
  // assuming grid is well-formed
  for (auto i = 0; i != grid.size(); ++i)
  {
    for (auto j = 0; j != grid.at(0).size(); ++j)
    {
      for (auto k = 0; k != grid.at(0).at(0).size(); ++k)
      {
        if (grid.at(i).at(j).at(k) == figure)
        {
          return std::make_tuple(i, j, k);
        }
      }
    }
  }
  return std::make_tuple(0, 0, 0);
}

int main()
{
  //Please implement this, it only returns an empty Solution object.
  //Please delete this, its just an example of the structure of the grid.
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
  return 0;
}
