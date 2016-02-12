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

// To compile use ``g++ -std=c++11 Problem5.cpp -Wall``

#include <algorithm>
#include <iostream>
#include "Problem5.hpp"

Problem5::Solution Problem5::savePrincess(const ThreeDimCharArray grid)
{
  Solution solution;
  solution.amountOfTime = 0u;
  solution.directions = std::vector<Direction>();
  solution.isPossible = false;

  auto princePosition = getFigurePosition(Figure::PRINCE, grid);
  auto princessPosition = getFigurePosition(Figure::PRINCESS, grid);

  // If princess stands above prince, then it is impossible.
  // can we jump? It seems impossible based on the description.
  if (std::get<0>(princessPosition) < std::get<0>(princePosition)) {
    return solution;
  }

  auto pool = std::vector<std::tuple<Position, Solution>>();
  pool.push_back(std::make_tuple(princePosition, solution));
  auto rejected = std::vector<Position>();
  auto results = std::vector<Solution>();
  while (pool.size() != 0)
  {
    auto p = pool.back();
    pool.pop_back();
    std::cout << "pool size: " << pool.size() << "\n";
    std::cout << "rejected size: " << rejected.size() << "\n";
    // base cases
    auto currentPrincePosition = std::get<0>(p);
    auto level = std::get<0>(currentPrincePosition);
    auto x = std::get<1>(currentPrincePosition);
    auto y = std::get<2>(currentPrincePosition);

    std::cout << level << ", " << x << ", " << y << "\n";

    auto currentSolution = std::get<1>(p);
    if ( std::find(rejected.begin(), rejected.end(), currentPrincePosition)
         != rejected.end() ||
        level < 0 || level > grid.size() ||
        x < 0 || x > grid.at(0).size() ||
        y < 0 || y > grid.at(0).at(0).size() ||
        grid.at(level).at(x).at(y) == Figure::COLUMN) {
      std::cout << "rejected" << "\n";
      rejected.push_back(currentPrincePosition);
      continue;
    }
    if (grid.at(level).at(x).at(y) == Figure::PRINCESS) {
      std::cout << "got it" << "\n";
      Solution result;
      std::memcpy(&result, &currentSolution, sizeof(Solution));
      result.isPossible = true;
      results.push_back(result);
    }
    // induction; prince is at a free space
    // try different moves
    std::cout << "induction" << "\n";
    auto pp_e = std::make_shared<std::tuple<Position, Solution>>();
    auto p_e = *pp_e.get();
    std::memcpy(&p_e, &p, sizeof(std::tuple<Position, Solution>));
    currentPrincePosition = std::get<0>(p_e);
    level = std::get<0>(currentPrincePosition);
    x = std::get<1>(currentPrincePosition);
    y = std::get<2>(currentPrincePosition);
    currentPrincePosition = std::make_tuple(level, x, y + 1);
    currentSolution = std::get<1>(p_e);
    currentSolution.amountOfTime += 5;
    currentSolution.directions.push_back(Direction::EAST);
    p_e = std::make_tuple(currentPrincePosition, currentSolution);
    pool.push_back(p_e);

    auto pp_w = std::make_shared<std::tuple<Position, Solution>>();
    auto p_w = *pp_w.get();
    std::memcpy(&p_w, &p, sizeof(std::tuple<Position, Solution>));
    currentPrincePosition = std::get<0>(p_w);
    level = std::get<0>(currentPrincePosition);
    x = std::get<1>(currentPrincePosition);
    y = std::get<2>(currentPrincePosition);
    currentPrincePosition = std::make_tuple(level, x, y - 1);
    currentSolution = std::get<1>(p_w);
    currentSolution.amountOfTime += 5;
    currentSolution.directions.push_back(Direction::WEST);
    p_w = std::make_tuple(currentPrincePosition, currentSolution);
    pool.push_back(p_w);

    auto pp_s = std::make_shared<std::tuple<Position, Solution>>();
    auto p_s = *pp_s.get();
    std::memcpy(&p_s, &p, sizeof(std::tuple<Position, Solution>));
    currentPrincePosition = std::get<0>(p_s);
    level = std::get<0>(currentPrincePosition);
    x = std::get<1>(currentPrincePosition);
    y = std::get<2>(currentPrincePosition);
    currentPrincePosition =  std::make_tuple(level, x + 1, y);
    currentSolution = std::get<1>(p_s);
    currentSolution.amountOfTime += 5;
    currentSolution.directions.push_back(Direction::SOUTH);
    p_s = std::make_tuple(currentPrincePosition, currentSolution);
    pool.push_back(p_s);

    auto pp_n = std::make_shared<std::tuple<Position, Solution>>();
    auto p_n = *pp_n.get();
    std::memcpy(&p_n, &p, sizeof(std::tuple<Position, Solution>));
    currentPrincePosition = std::get<0>(p_n);
    level = std::get<0>(currentPrincePosition);
    x = std::get<1>(currentPrincePosition);
    y = std::get<2>(currentPrincePosition);
    currentPrincePosition =  std::make_tuple(level, x - 1, y);
    currentSolution = std::get<1>(p_n);
    currentSolution.amountOfTime += 5;
    currentSolution.directions.push_back(Direction::NORTH);
    p_n = std::make_tuple(currentPrincePosition, currentSolution);
    pool.push_back(p_n);

    auto pp_d = std::make_shared<std::tuple<Position, Solution>>();
    auto p_d = *pp_d.get();
    std::memcpy(&p_d, &p, sizeof(std::tuple<Position, Solution>));
    currentPrincePosition = std::get<0>(p_d);
    level = std::get<0>(currentPrincePosition);
    x = std::get<1>(currentPrincePosition);
    y = std::get<2>(currentPrincePosition);
    currentPrincePosition =  std::make_tuple(level + 1, x, y);
    currentSolution = std::get<1>(p_d);
    currentSolution.amountOfTime += 5;
    currentSolution.directions.push_back(Direction::DOWN);
    p_d = std::make_tuple(currentPrincePosition, currentSolution);
    pool.push_back(p_d);
  }

  if (results.size() == 0) return solution;
  return *std::min_element(results.begin(), results.end(), compareBetterSolution);
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
  auto solution = Problem5::savePrincess(grid);
  std::cout << solution.amountOfTime << "\n";
  return 0;
}
