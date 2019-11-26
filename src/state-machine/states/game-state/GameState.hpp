#ifndef SUPERMARIOBROS3_GAMESTATE_HPP
#define SUPERMARIOBROS3_GAMESTATE_HPP


#include <memory>
#include "../../StateMachine.hpp"

class GameState : public State
{
public:
  explicit GameState(std::shared_ptr<StateMachine> &machine);

  void onStart() override;

  void update() override;

  void onStop() override;
};


#endif //SUPERMARIOBROS3_GAMESTATE_HPP
