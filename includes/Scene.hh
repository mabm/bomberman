//
// Scene.hh for  in /home/mediav_j/mabm/bomberman/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Jun  1 15:29:00 2015 Jérémy Mediavilla
// Last update Tue Jun  9 11:21:15 2015 Joris Bertomeu
//

#ifndef			_SCENE_HH_
# define		_SCENE_HH_

# include		<list>

class			Scene;

# include		<AEntity.hh>
# include		<RenderManager.hh>

class			Scene
{
private:
  std::list<AEntity*>	_entityList;

public:
  explicit		Scene();
  virtual		~Scene();
  bool			addEntity(AEntity *);
  void			listAllEntities() const;
  std::list<AEntity *>	getEntities();
  void			draw(RenderManager & rm);
};

#endif		// _SCENE_HH_
