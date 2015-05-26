//
// GameContext.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 12:47:58 2015 Joris Bertomeu
// Last update Tue May 26 09:49:15 2015 Joris Bertomeu
//

#include	<GameContext.hh>

GameContext::GameContext()
{

}

GameContext::~GameContext()
{

}

bool	GameContext::initialize(RenderManager *rm, const glm::vec2 &windowSize)
{
  this->_renderManager = rm;
  this->_sceneManager.setRenderManager(rm);
  this->_cameraManager.initialize(rm, windowSize);
  return (true);
}

Scene	*GameContext::getCurrentScene() const
{
  return (this->_sceneManager.getCurrentScene());
}

bool		GameContext::addScene(const std::string &path)
{
  return (this->_sceneManager.loadSceneFromFile(SceneManager::MAP, path));
}
