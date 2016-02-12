#ifndef PROBLEM5_HPP
#define PROBLEM5_HPP

#include <vector>
#include <tuple>

namespace Problem5 {
  // level, x, y
  using ThreeDimCharArray = std::vector<std::vector<std::vector<char16_t>>>;
  // level, x, y
  using Position = std::tuple<uint32_t, uint32_t, uint32_t>;

  int32_t TIME_UNIT = 5;

  enum Figure { PRINCE = (char16_t) '1', PRINCESS = (char16_t) '2' };
  enum Direction { EAST, WEST, SOUTH, NORTH, UP, DOWN };

  struct Solution {
    uint64_t amountOfTime;
    std::vector<Direction> directions;
    bool isPossible;
  };

  Solution savePrincess(ThreeDimCharArray grid);
  std::vector<std::shared_ptr<Solution>>
  savePrincessRecursion(const Position princePosition,
                        std::shared_ptr<Solution> solutuon,
                        const ThreeDimCharArray grid);
  Position getFigurePosition(Figure figure, ThreeDimCharArray grid);
}

#endif /* !PROBLEM5_HPP */
