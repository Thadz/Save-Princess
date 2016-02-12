#ifndef PROBLEM5_HPP
#define PROBLEM5_HPP

#include <vector>
#include <tuple>

namespace Problem5 {
  // level, x, y
  using ThreeDimCharArray = std::vector<std::vector<std::vector<char16_t>>>;
  // level, x, y
  using Position = std::tuple<int32_t, int32_t, int32_t>;

  int32_t TIME_UNIT = 5;

  enum Figure
  { 
    PRINCE = (char16_t) '1', PRINCESS = (char16_t) '2',
    SPACE = (char16_t) '.', COLUMN = (char16_t) 'o'
  };
  enum Direction { EAST, WEST, SOUTH, NORTH, UP, DOWN };

  struct Solution
  {
    uint64_t amountOfTime;
    std::vector<Direction> directions;
    bool isPossible;
  };

  Solution savePrincess(ThreeDimCharArray grid);
  Position getFigurePosition(Figure figure, ThreeDimCharArray grid);
  bool compareBetterSolution(const Solution s1, const Solution s2)
  {
    return s1.amountOfTime < s2.amountOfTime;
  };
}

#endif /* !PROBLEM5_HPP */
