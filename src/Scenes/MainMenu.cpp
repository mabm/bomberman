//
// MainMenu.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src/Scenes
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Mon Jun  8 09:29:53 2015 Valérian Polizzi
<<<<<<< HEAD
// Last update Mon Jun  8 11:41:31 2015 Valérian Polizzi
=======
// Last update Tue Jun  9 20:52:02 2015 Geoffrey Merran
>>>>>>> 95c9de52006b0fcd4c9e5d018875eaa648609eb7
//

#include	<MainMenu.hh>

MainMenu::MainMenu()
{
<<<<<<< HEAD
    this->_p1 = new Pavement(glm::vec3(0, 300, 0), std::string("play.tga"));
    this->_p1->setScale(glm::vec3(800, 200, 60));
    this->_p2 = new Pavement(glm::vec3(0, 0, 0), std::string("wall_texture.tga"));
    this->_p2->setScale(glm::vec3(800, 200, 60));
=======
    this->_p1 = new Pavement(glm::vec3(100, 200, 0), "wall_texture.tga");
    this->_p1->setScale(glm::vec3(800, 200, 60));
>>>>>>> 95c9de52006b0fcd4c9e5d018875eaa648609eb7
    this->addEntity(this->_p1);
    this->addEntity(this->_p2);
}

MainMenu::~MainMenu()
{

}
