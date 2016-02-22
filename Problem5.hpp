#ifndef PROBLEM5_HPP
#define PROBLEM5_HPP

#include <memory>
#include <ostream>
#include <tuple>
#include <unordered_map>
#include <vector>

namespace Problem5 {
  bool _DEBUG_ = false;
  // level, x, y
  using ThreeDimCharArray = std::vector<std::vector<std::vector<char>>>;
  // level, x, y
  using Position = std::tuple<int32_t, int32_t, int32_t>;
  uint64_t TIME_UNIT = 5;
  enum Figure
  {
    PRINCE = (char) '1', PRINCESS = (char) '2',
    SPACE = (char) '.', COLUMN = (char) 'o'
  };
  enum Direction { EAST, WEST, SOUTH, NORTH, DOWN };
  class State
  {
  public:
    Position position;
    std::vector<Direction> directions;
  };
  class Solution
  {
  public:
    uint64_t amountOfTime;
    std::vector<Direction> directions;
    bool isPossible;
  };
  std::shared_ptr<Solution> savePrincess(const ThreeDimCharArray& grid);

  Position getFigurePosition(const Figure figure, const ThreeDimCharArray& grid)
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
  };
  inline const std::string toString(const Direction& direction)
  {
    switch (direction)
    {
      case EAST: return "EAST";
      case WEST: return "WEST";
      case SOUTH: return "SOUTH";
      case NORTH: return "NORTH";
      case DOWN: return "DOWN";
      default: return "";
    }
  };
  void moveEast(State& dest, const State& src)
  {
    auto level = std::get<0>(src.position);
    auto x = std::get<1>(src.position);
    auto y = std::get<2>(src.position);
    auto directions = src.directions;
    directions.push_back(Direction::EAST);
    dest = { std::make_tuple(level, x + 1, y), directions };
  };
  void moveWest(State& dest, const State& src)
  {
    auto level = std::get<0>(src.position);
    auto x = std::get<1>(src.position);
    auto y = std::get<2>(src.position);
    auto directions = src.directions;
    directions.push_back(Direction::WEST);
    dest = { std::make_tuple(level, x - 1, y), directions };
  };
  void moveNorth(State& dest, const State& src)
  {
    auto level = std::get<0>(src.position);
    auto x = std::get<1>(src.position);
    auto y = std::get<2>(src.position);
    auto directions = src.directions;
    directions.push_back(Direction::NORTH);
    dest = { std::make_tuple(level, x, y - 1), directions };
  };
  void moveSouth(State& dest, const State& src)
  {
    auto level = std::get<0>(src.position);
    auto x = std::get<1>(src.position);
    auto y = std::get<2>(src.position);
    auto directions = src.directions;
    directions.push_back(Direction::SOUTH);
    dest = { std::make_tuple(level, x, y + 1), directions };
  };
  void moveDown(State& dest, const State& src)
  {
    auto level = std::get<0>(src.position);
    auto x = std::get<1>(src.position);
    auto y = std::get<2>(src.position);
    auto directions = src.directions;
    directions.push_back(Direction::DOWN);
    dest = { std::make_tuple(level + 1, x, y), directions };
  };
  void mkSolution(Solution& solution, const std::vector<Direction>& directions)
  {
    solution.directions = directions;
    solution.amountOfTime = directions.size() * TIME_UNIT;
    solution.isPossible = directions.size() == 0 ? false : true;
  };
  std::ostream& operator<<(std::ostream& os, const Position& position)
  {
    os << "("
       << std::get<0>(position) << ", "
       << std::get<1>(position) << ", "
       << std::get<2>(position) << "), ";
    return os;
  };
  std::ostream& operator<<(std::ostream& os, const Direction& direction)
  {
    return os << toString(direction);
  }
  template<typename T>
  std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector)
  {
    os << "[";
    for (auto&& x : vector)
    {
      os << x << ",";
    }
    os << "]";
    return os;
  };
  std::ostream& operator<<(std::ostream& os, const State& state)
  {
    os << "position: " << state.position << "\n";
    os << "directions: " << state.directions << "\n";
    return os;
  };
  std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Solution>& solution)
  {
    os << "solution: {" << "\n";
    os << "is possible   : " << solution.get()->isPossible << "\n";
    os << "amount of time: " << solution.get()->amountOfTime << "\n";
    os << solution.get()->directions << "\n";
    os << "}";
    return os;
  };
}

#endif /* !PROBLEM5_HPP */
