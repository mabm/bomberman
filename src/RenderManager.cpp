//
// RenderManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 14:23:22 2015 Joris Bertomeu
// Last update Wed Jun  3 16:33:02 2015 Geoffrey Merran
//

#include <RenderManager.hh>

RenderManager::RenderManager()
{

}

RenderManager::~RenderManager()
{

}

bool			RenderManager::initialize(const glm::vec2 &windowSize, const std::string &name)
{
  if (!this->_graphicManager.initialize(windowSize, name))
    return (false);
  return (true);
}

bool			RenderManager::start()
{
  return (true);
}

bool			RenderManager::update()
{
  return (true);
}

void			RenderManager::draw(Scene *scene)
{
  scene->draw(*this);
  this->_graphicManager.flush();
}

void			RenderManager::stop()
{
  this->_graphicManager.stop();
}

GraphicManager		RenderManager::getGraphicManager() const
{
  return (this->_graphicManager);
}

ModelManager		RenderManager::getModelManager() const
{
  return (this->_modelManager);
}
