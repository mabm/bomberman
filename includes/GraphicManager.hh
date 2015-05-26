//
// SoundManager.hh for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 10:55:51 2015 Joris Bertomeu
// Last update Mon May 25 17:22:58 2015 Geoffrey Merran
//

#ifndef			_GRAPHICMANAGER_HH_
# define		_GRAPHICMANAGER_HH_

# include		<string>
# include		<stdexcept>
# include		<unistd.h>

# include		<glm/glm.hpp>
# include		<glm/gtc/matrix_transform.hpp>

# include		<GraphicContext.hh>

class			GraphicManager
{
private:
  GraphicContext	_context;

public:
  explicit		GraphicManager();
  virtual		~GraphicManager();
  bool			initialize(const glm::vec2 &, const std::string &);
  void			stop();
};

#endif			/* _GRAPHICMANAGER_HH_ */
