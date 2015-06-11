//
// Scene.hh for  in /home/mediav_j/mabm/bomberman
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Tue Jun  9 19:35:50 2015 Jérémy Mediavilla
// Last update Thu Jun 11 01:10:40 2015 Joris Bertomeu
//

#ifndef			_SCENE_HH_
# define		_SCENE_HH_

# include		<list>
# include		<fstream>

class			Scene;

# include		<AEntity.hh>
# include		<RenderManager.hh>
# include		<CameraManager.hh>
# include		<IEvent.hh>
# include		<Sound.hpp>

class			Scene
{
protected:
  std::list<AEntity*>	_entityList;
  std::string		_name;
  IEvent*		_eventHandler;
  CameraManager*       	_cm;
  bool			_first;
  RenderManager		*_renderManager;

public:
  explicit		Scene(CameraManager* cm);
  virtual		~Scene();

  virtual void	       	initialize();
  bool			addEntity(AEntity *);
  std::list<AEntity *>	getEntities();
  void			updateEntities(gdl::Clock & clock);
  IEvent*		getEventHandler();
  void			setEventHandler(IEvent *);
  void			draw(RenderManager & rm);
  bool			save(RenderManager *);
  void			spacePress(SceneManager *sm);
  void			escapePress(SceneManager *sm);
  void			*getBomberman();
};

#endif		// _SCENE_HH_
