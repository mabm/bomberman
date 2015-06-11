//
// Event.cpp for  in /home/mari_f/testtt/includes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Wed Jun  3 13:43:17 2015 mari_f
// Last update Thu Jun 11 16:17:03 2015 Valérian Polizzi
//

#include		<GameEvent.hh>
#include		<Pavement.hh>
#include		<MainMenu.hh>

GameEvent::GameEvent()
{
  this->_events[SDLK_UP] = &GameEvent::up;
  this->_events[SDLK_DOWN] = &GameEvent::down;
  this->_events[SDLK_LEFT] = &GameEvent::left;
  this->_events[SDLK_RIGHT] = &GameEvent::right;
  // this->_events[SDLK_SPACE] = &GameEvent::space;
       		// this->_events[SDL_BUTTON_LEFT] = &GameEvent::click;
}

GameEvent::~GameEvent()
{

}

bool			GameEvent::isCatch(gdl::Input &input, Scene* scene, CameraManager& camera)
{
  this->_camera = camera;
  for (std::map<int, GameEvent::eventHandler>::iterator found = this->_events.begin(); found != this->_events.end(); found++)
    {
      if (input.getKey((*found).first))
	{
	  (this->*this->_events[(*found).first])(scene);
	  return (true);
	}
      if (input.getKey(SDL_BUTTON_LEFT))
	{
	  std::cout << "x :" << input.getMousePosition().x << std::endl;
	  std::cout << "y : " << input.getMousePosition().y << std::endl;
	  return (true);
	}
    }
  return (false);
}

void			GameEvent::updatePlayerCamera(const glm::vec3 & point)
{
  this->_camera.moveTo(this->_camera.getDefaultPos() + point, point);
}

void			GameEvent::up(Scene* scene)
{
  std::list<AEntity*>	list;
  glm::vec3		bomberman_position_old;
  int			height;

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
      	{
      	  bomberman_position_old = dynamic_cast<Bomberman*>((*it))->getPos();
      	  dynamic_cast<Bomberman*>((*it))->moveFront();
      	  if (dynamic_cast<Bomberman*>((*it))->getHitbox()->checkCollision(scene))
      	    dynamic_cast<Bomberman*>((*it))->setPos(bomberman_position_old);
      	  this->updatePlayerCamera((*it)->getPos());
      	}
    }

  height = dynamic_cast<MainMenu*>(scene)->getCursor()->getPos().y;
  if (height >= 300)
    height = (300 - (300 * dynamic_cast<MainMenu*>(scene)->getListSize()));
  else
    height += 300;
  dynamic_cast<MainMenu*>(scene)->getCursor()->setPos(glm::vec3(-500, height, 0));
  std::cout << height << std::endl;
}

void			GameEvent::click(Scene* scene)
{
  (void)scene;

}

void			GameEvent::down(Scene* scene)
{
  std::list<AEntity*>	list;
  glm::vec3		bomberman_position_old;
  int			height;

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	{
	  bomberman_position_old = dynamic_cast<Bomberman*>((*it))->getPos();
	  dynamic_cast<Bomberman*>((*it))->moveBack();
	  if (dynamic_cast<Bomberman*>((*it))->getHitbox()->checkCollision(scene))
      	    dynamic_cast<Bomberman*>((*it))->setPos(bomberman_position_old);
	  this->updatePlayerCamera((*it)->getPos());
	}
    }

  height = dynamic_cast<MainMenu*>(scene)->getCursor()->getPos().y;
  if (height <= 300 - (300 * dynamic_cast<MainMenu*>(scene)->getListSize()))
    height = 300;
  else
    height -= 300;
  dynamic_cast<MainMenu*>(scene)->getCursor()->setPos(glm::vec3(-500, height, 0));
}


void			GameEvent::right(Scene* scene)
{
  std::list<AEntity*>	list;
  glm::vec3		bomberman_position_old;

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	{
	  bomberman_position_old = dynamic_cast<Bomberman*>((*it))->getPos();
	  dynamic_cast<Bomberman*>((*it))->moveRight();
	  if (dynamic_cast<Bomberman*>((*it))->getHitbox()->checkCollision(scene))
      	    dynamic_cast<Bomberman*>((*it))->setPos(bomberman_position_old);
	  this->updatePlayerCamera((*it)->getPos());
	}
    }

}

void			GameEvent::left(Scene* scene)
{
  std::list<AEntity*>	list;
  glm::vec3		bomberman_position_old;

  list = scene->getEntities();
  for (std::list<AEntity*>::iterator it = list.begin(); it != list.end();
       it++)
    {
      if ((*it)->getType() == AEntity::BOMBERMAN)
	{
	  bomberman_position_old = dynamic_cast<Bomberman*>((*it))->getPos();
	  dynamic_cast<Bomberman*>((*it))->moveLeft();
	  if (dynamic_cast<Bomberman*>((*it))->getHitbox()->checkCollision(scene))
      	    dynamic_cast<Bomberman*>((*it))->setPos(bomberman_position_old);
	  this->updatePlayerCamera((*it)->getPos());
	}
    }
}
