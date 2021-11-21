#ifndef INPUT_H
#define INPUT_H

#include "player.h"

// Input class that handles all keyboard presses
class Input {
 public:
  void Handle(bool &running, Player &user,Player &program) const;
  void Start(bool &start, bool &running) const;

 private:
  void ChangeDirection(Player &player, Player::Direction input, Player::Direction opposite) const;
  void Reset(Player &user, Player &program) const;
};

#endif
