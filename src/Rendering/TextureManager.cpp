//
// TextureManager.cpp for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Tue May 26 17:47:30 2015 Geoffrey Merran
// Last update Sun Jun 14 03:53:39 2015 Geoffrey Merran
//

#include <TextureManager.hh>

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

bool	TextureManager::initialize()
{
  return (true);
}

bool	TextureManager::addTexture(const Texture &texture)
{
  (void) texture;
  return (true);
}

bool	TextureManager::addTextureFromFile(const std::string & name, const std::string &filename)
{
  std::map<std::string, Texture* >::iterator it = this->_textures.find(name);
  if (it != this->_textures.end())
    {
      delete this->_textures[name];
    }
  this->_textures[name] = new Texture(filename);
  return (true);
}

Texture*				TextureManager::getTexture(const std::string & name)
{
  std::map<std::string, Texture* >::iterator it = this->_textures.find(name);
  if (it == this->_textures.end())
    return (NULL);
  return (this->_textures[name]);
}

std::map<std::string, Texture *>	TextureManager::getTextures()
{
  return (this->_textures);
}
