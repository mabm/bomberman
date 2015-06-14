//
// Bot.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Sun Jun 14 02:12:47 2015 Jérémy Mediavilla
//

#include <Bot.hh>

Bot::Bot(glm::vec3 pos, const std::string &name) : Bomberman(pos, name)
{
  std::cout << "New Bot created : <" << pos.x <<", "<< pos.y << ", "<< pos.z <<"> " << name << std::endl;
  this->_name = name;
  this->_type = BOT;
}

Bot::~Bot()
{

}

// std::string	Bot::getName() const
// {
//   return (this->_name);
// }


std::string	Bot::getColor() const
{
  return (this->_color);
}

void		Bot::setColor(const std::string &color)
{
  this->_color = color;
}

std::list<glm::vec2>		Bot::directTrajectory(int xStart, int yStart, int xEnd, int yEnd)
{
  std::list<glm::vec2> posList;

  float		a = 0;
  int		tmp = 0;
  int		dx;
  int		dy;
  int		x;
  int		y;

  dx = abs(xEnd - xStart);
  dy = abs(yEnd - yStart);
  std::cout << dx << " - " << dy << std::endl;
  if (xStart == xEnd)
    {
      if (yStart < yEnd + 1)
	while (yStart != yEnd + 1)
	  {
	    posList.push_back(glm::vec2(xStart, yStart));
	    yStart++;
	  }
      else
	while (yStart != yEnd)
	  {
	    posList.push_back(glm::vec2(xStart, yStart));
	    yStart--;
	  }
    }
  else if (yStart == yEnd)
    {
      if (xStart < xEnd + 1)
	while (xStart != xEnd + 1)
	  {
	    posList.push_back(glm::vec2(xStart, yStart));
	    xStart++;
	  }
      else
	while (xStart != xEnd + 1)
	  {
	    posList.push_back(glm::vec2(xStart, yStart));
	    xStart--;
	  }
    }
  else
    {
      if (dx >= dy && dx != 0 && dy != 0)
	{
	  if (xStart > xEnd)
	    {
	      tmp = xStart;
	      xStart = xEnd;
	      xEnd = tmp;

	      tmp = yStart;
	      yStart = yEnd;
	      yEnd = tmp;
	    }
	  a = ((float)(yEnd - yStart) / (xEnd - xStart));
	  for (int i = 0; i < (dx + 1); i++)
	    {
	      x = i + xStart;
	      y = yStart + (a * i);
	      posList.push_back(glm::vec2(x, y));
	    }
	}
      if (dx < dy && dy != 0 && dx != 0)
	{
	  if (yStart > yEnd)
	    {
	      tmp = yStart;
	      yStart = yEnd;
	      yEnd = tmp;

	      tmp = xStart;
	      xStart = xEnd;
	      xEnd = tmp;
	    }
	  a = ((float)(xEnd - xStart) / (yEnd - yStart));
	  for (int i = 0; i < (dy + 1); i++)
	    {
	      x = xStart + (i * a);
	      y = i + yStart;
	      posList.push_back(glm::vec2(x, y));
	    }
	}
      if (dx == 0)
	{
	  if (xStart > xEnd)
	    {
	      tmp = xStart;
	      xStart = xEnd;
	      xEnd = tmp;
	    }
	  for (int i = yStart; i < (yEnd + 1); i++)
	    {
	      x = xStart;
	      posList.push_back(glm::vec2(x, i));
	    }
	}
      if (dy == 0)
	{
	  if (yStart > yEnd)
	    {
	      tmp = yStart;
	      yStart = yEnd;
	      yEnd = tmp;
	    }
	  for (int i = xStart; i < (xEnd + 1); i++)
	    {
	      x = i;
	      y = yStart;
	      posList.push_back(glm::vec2(x, y));
	    }
	}
    }
  return (posList);
  (void)a;
}

void		Bot::ia(Scene *scene)
{
  Bomberman	*bomberman;
  std::list<glm::vec2> posList;
  
  bomberman = static_cast<Bomberman *>(scene->getBomberman());
  posList = this->directTrajectory(this->getPos().x, this->getPos().z, bomberman->getPos().x, bomberman->getPos().z);
  if (((posList.front().x == this->getPos().x && posList.front().y == this->getPos().z)) || (posList.back().x == bomberman->getPos().x && posList.back().y == bomberman->getPos().z))
    this->setPosList(posList);
  else
    {
      posList.reverse();
      this->setPosList(posList);
    }
}

void		Bot::update(gdl::Clock &clock, Scene *scene)
{
  glm::vec3	oldPos;

  if (!this->_first)
    {
      this->ia(scene);
      this->_first = false;
    }
  if (this->_posList.back().y < this->_pos.z && this->_posList.back().x > this->_pos.x)
    {
      
      printf("en haut à droite :%f - %f\n", this->calcAngle(glm::vec3(this->_pos.x, this->_pos.y, this->_pos.z + 50), this->_pos, glm::vec3(glm::vec3(this->_posList.back().x, 0, this->_posList.back().y))),       	  this->calcAngle(glm::vec3(glm::vec3(this->_posList.back().x, 0, this->_posList.back().y)),
      			  this->_pos, 
      			  glm::vec3(this->_pos.x, this->_pos.y, this->_pos.z + 50)));
      if (this->calcAngle(glm::vec3(this->_pos.x, this->_pos.y, this->_pos.z + 50),
      			  this->_pos, 
      			  glm::vec3(glm::vec3(this->_posList.back().x, 0, this->_posList.back().y))) >
      	  this->calcAngle(glm::vec3(glm::vec3(this->_posList.back().x, 0, this->_posList.back().y)),
      			  this->_pos, 
      			  glm::vec3(this->_pos.x + 50, this->_pos.y, this->_pos.z)))
      	{
      	  this->moveRight(clock);
      	  this->ia(scene);
      	}
      else
      	{
      	  this->moveFront(clock);
      	  this->ia(scene);
      	}
    }
  else if (this->_posList.back().y > this->_pos.z && this->_posList.back().x > this->_pos.x)
    {
      std::cout << "en bas a droite" << std::endl;
    }
  else if (this->_posList.back().y > this->_pos.z && this->_posList.back().x < this->_pos.x)
    {
      std::cout << "en bas a gauche" << std::endl;
    }
  else if (this->_posList.back().y < this->_pos.z && this->_posList.back().x < this->_pos.x)
    {
      std::cout << "en haut a gauche" << std::endl;
    }
}

void	        Bot::moveToPos(const glm::vec2 &pos)
{
  this->setPos(glm::vec3(pos.x, this->getPos().y, pos.y));
} 

void		Bot::setPosList(const std::list<glm::vec2> &pos)
{
  this->_posList = pos;
}

std::list<glm::vec2>	Bot::getPosList() const
{
  return (this->_posList);
}

void		Bot::popBack()
{
  this->_posList.pop_back();
}

void		Bot::popFront()
{
  this->_posList.pop_front();
}

float		Bot::calcAngle(const glm::vec3 &a, const glm::vec3 &b, const glm::vec3 &c)
{
  glm::vec2	vecAB;
  glm::vec2	vecBC;
  float		AB;
  float		BC;

  vecAB.x = b.x - a.x;
  vecAB.y = b.z - a.z;
  vecBC.x = c.x - b.x;
  vecBC.y = c.z - b.z;

  AB = sqrt(pow(b.x - a.x ,2) + pow(b.z - a.z ,2));
  BC = sqrt(pow(c.x - b.x ,2) + pow(c.z - b.z ,2));
  printf("AB = %f - BC = %f\n", AB, BC);
  return (cos((-1 * (vecAB.x * vecBC.x + vecAB.y * vecBC.y)) / (AB * BC)));
}
