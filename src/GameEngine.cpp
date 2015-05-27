//
// GameEngine.cpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 09:32:34 2015 Joris Bertomeu
// Last update Wed May 27 04:33:36 2015 Joris Bertomeu
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
  if (!this->_gameContext.initialize(&(this->_renderManager), this->_parameters.getSize()))
    return (false);
  return (true);
}

bool	GameEngine::update()
{
  this->_renderManager.update();
  return (true);
}

void	GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.50f, 0.50f, 0.50f, 1.0f);
  glClearDepth(1.0f);
  this->_renderManager.draw(this->_gameContext.getCurrentScene());
}

bool	GameEngine::run()
{
  this->_gameContext.addScene("XMLfiles/ArchitectureXML.xml");

  SDL_Event	event;
  while (this->_running)
    {
      this->update();
      this->draw();
    }
  this->_renderManager.stop();
  return (true);
}
