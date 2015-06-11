//
// Texture.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:19:32 2015 Joris Bertomeu
// Last update Thu Jun 11 18:58:12 2015 Jérémy Mediavilla
//

#ifndef		_TEXTURE_HPP_
# define	_TEXTURE_HPP_

# include	<stdexcept>
# include	<string>
# include	<Model.hh>
# include	<Texture.hh>

class		Texture
{
private:
  std::string	_filename;
  gdl::Texture	_t;

public:
  explicit	Texture(const std::string &filename) {
    this->_filename = filename;
    if (!this->_t.load(filename))
      throw(std::logic_error("Error texture, can't load "  + filename));
  }

  virtual	~Texture(void) {

  }
  bool		save(std::fstream &fs) {
    fs << "TEXTURE" << std::endl;
  }
};

#endif		/* _TEXTURE_HPP_ */
