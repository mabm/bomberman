/*
** parserXml.h for  in /home/mediav_j/mabm/bomberman/parserXML
** 
** Made by Jérémy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Fri May 22 15:07:06 2015 Jérémy Mediavilla
** Last update Tue May 26 12:26:07 2015 Jérémy Mediavilla
*/

#ifndef		_PARSERXML_H_
# define	_PARSERXML_H_

# include <stdlib.h>
# include <libxml/parser.h>
# include <libxml/tree.h>
# include <string.h>

# define PARAMETERS_TAG	"parameters"
# define TEXTURE_TAG	"texture_pack"
# define SOUND_TAG	"sound_pack"
# define COMMON_TAG	"common"
# define ENTITY_TAG	"entities"

typedef struct	s_tag
{
  char		*name;
  int		nb;
  int		*lines;
}		t_tag;

#endif		/* _PARSERXML_H_ */