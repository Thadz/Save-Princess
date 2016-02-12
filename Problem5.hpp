#ifndef PROBLEM5_HPP
#define PROBLEM5_HPP

#include <vector>

namespace Problem5 {
  using TreeDimCharArray = std::vector<std::vector<std::vector>>;

  enum Direction { EAST, WEST, SOUTH, NORTH, UP, DOWN };

  struct Solution {
    int amountOfTime;
    std::vector<Direction> directions;
    bool isPossible;
  };

  Solution savePrincess(ThreeDimCharArray grid);
}

#endif /* !PROBLEM5_HPP */
