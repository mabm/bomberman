//
// RenderManager.hh for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 10:49:21 2015 Joris Bertomeu
// Last update Tue May 19 11:31:03 2015 Joris Bertomeu
//

#ifndef			_RENDERMANAGER_HH_
# define		_RENDERMANAGER_HH_

# include		<SoundManager.hh>
# include		<TextureManager.hh>
# include		<GraphicManager.hh>
# include		<AScene.hh>

class			RenderManager
{
protected:
  SoundManager		_soundManager;
  TextureManager	_textureManager;
  GraphicManager	_GraphicManager;

public:
  explicit		RenderManager();
  virtual		~RenderManager();
  bool			initialize(const glm::vec2 &, const std::string &);
  bool			start();
  bool			update();
  void			draw(const AScene &);
};

#endif			/* _RENDERMANAGER_HH */