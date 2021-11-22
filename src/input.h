#ifndef INPUT_H
#define INPUT_H

#include "player.h"

class Input {
 public:
  void Handle(bool &running, Player &user, Player &program) const;
  void Start(bool &start, bool &running) const;

 private:
  void ChangeDirection(Player &player, Player::Direction input, Player::Direction opposite) const;
};

#endif
