//
// GameEngine.cpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 09:32:34 2015 Joris Bertomeu
// Last update Wed Jun 10 21:40:33 2015 Joris Bertomeu
//

#include <GameEngine.hh>

GameEngine::GameEngine(int ac, char **argv) : _running(1)
{
  try {
    this->_parameters.setParameters(ac, argv);
  } catch (const std::exception &e) {
    throw std::logic_error(e.what());
  }
}

GameEngine::~GameEngine()
{

}

bool	GameEngine::initialize()
{
  if (!this->_renderManager.initialize(this->_parameters.getSize(), std::string("Bomberman")))
    return (false);
  this->_renderManager.getSoundManager().addSoundFromFile("assets/sounds/music.mp3", Sound::AMBIANT);
  this->_renderManager.getSoundManager().getSoundOf(Sound::AMBIANT);
  if (!this->_gameContext.initialize(&(this->_renderManager), this->_parameters.getSize(), &this->_running))
    return (false);
  return (true);
}

bool	GameEngine::update()
{
  this->_renderManager.update(this->_input);
  this->_gameContext.updateScene(this->_input);
  return (true);
}

void	GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.50f, 0.50f, 0.50f, 1.0f);
  glClearDepth(1.0f);
  this->_renderManager.draw(this->_gameContext.getCurrentScene());
  this->_renderManager.delay();
}

bool	GameEngine::run()
{
  while (this->_running)
    {
      this->update();
      this->draw();
    }
  this->_renderManager.stop();
  return (true);
}
