//
// Parameters.hpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 10:19:02 2015 Joris Bertomeu
// Last update Tue May 19 10:34:44 2015 Joris Bertomeu
//

#ifndef		_PARAMETERS_HH_
# define	_PARAMETERS_HH_

# include	<stdexcept>

class		Parameters
{
private:
  int		_ac;
  char		**_argv;
  int		_width;
  int		_height;

public:
  explicit	Parameters() {

  }

  virtual	~Parameters() {

  }

  void		setParameters(int ac, char **argv)  {
    this->_ac = ac;
    this->_argv = argv;
    if (this->_ac != 3)
      throw std::logic_error("Usage : ./bomberman <width> <height>");
    //PENSER A CHECK QUE C'EST UNE TAILLE VALIDE
    this->_width = atoi(this->_argv[1]);
    this->_height = atoi(this->_argv[2]);
  }
};

#endif