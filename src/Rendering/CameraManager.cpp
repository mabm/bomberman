//
// CameraManager.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:05:59 2015 Joris Bertomeu
<<<<<<< HEAD
// Last update Mon Jun  8 10:37:37 2015 Valérian Polizzi
=======
// Last update Tue Jun  9 20:27:28 2015 Geoffrey Merran
>>>>>>> 95c9de52006b0fcd4c9e5d018875eaa648609eb7
//

#include	<CameraManager.hh>
#include	<iostream>

CameraManager::CameraManager() : _pos(glm::vec3(0, 0, 800)), _point(glm::vec3(0, 0, 0)), _defaultPos(_pos)
{
  // _pos.y = 600
  this->_renderManager = NULL;
}

CameraManager::~CameraManager()
{

}

bool			CameraManager::initialize(RenderManager *rm, const glm::vec2 &windowSize)
{
  this->_renderManager = rm;
  this->_projection = glm::perspective(60.0f, static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y), 0.1f, 5000.0f);
  std::cout << "Camera Initialized" << std::endl;
  this->moveTo(this->_pos, this->_point);
  return (true);
}

bool			CameraManager::moveTo(const glm::vec3 &pos, const glm::vec3 & point)
{
  this->_transformation = glm::lookAt(pos, point, glm::vec3(0, 1, 0));
  this->_renderManager->getGraphicManager().getContext().getShaders().bind();
  this->_renderManager->getGraphicManager().getContext().getShaders().setUniform("view", this->_transformation);
  this->_renderManager->getGraphicManager().getContext().getShaders().setUniform("projection", this->_projection);
  this->_pos = pos;
  this->_point = point;
  return (true);
}

const glm::vec3 &    	CameraManager::getPos() const
{
  return (this->_pos);
}

const glm::vec3 &    	CameraManager::getPoint() const
{
  return (this->_point);
}

const glm::vec3 &	CameraManager::getDefaultPos() const
{
  return (this->_defaultPos);
}
