//
// Sound.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:10:43 2015 Joris Bertomeu
// Last update Fri Jun 12 16:37:28 2015 Jérémy Mediavilla
//

#ifndef				_SOUND_HH_
# define			_SOUND_HH_

# include			<string>
# include			<fmod.h>

class				Sound
{
public:
  typedef enum			soundType
    {
      UNKNOWN			= 0,
      WALK			= 1,
      EXPLOSION			= 2,
      WALK_STOP			= 3,
      DESTRUCTION		= 4,
      DEAD			= 5,
      AMBIANT			= 6,
      JUMP			= 7
    }				SoundType;

protected:
  std::string			_filename;
  bool				_online;
  SoundType			_type;
  FMOD_SOUND			*_rawSound;

public:
  explicit			Sound(const Sound::SoundType &type, const bool &online, const std::string &filename) {
    this->_filename = filename;
    this->_online = online;
    this->_type = type;
    // if (this->_type == Sound::AMBIANT)
    //   FMOD_System_CreateSound();
    // else
    //   FMOD_System_CreateSound();
  }

  virtual			~Sound() {

  }

  std::string			getFilename() const {
    return (this->_filename);
  }

  bool				getOnline() const {
    return (this->_online);
  }

  SoundType			getType() const {
    return (this->_type);
  }

  void				setFilename(const std::string &filename) {
    this->_filename = filename;
  }

  void				setOnline(const bool & online) {
    this->_online = online;
  };

  void				setType(const SoundType &type) {
    this->_type = type;
  };
};

#endif				/* _SOUND_HH_ */
