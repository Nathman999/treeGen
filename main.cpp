#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <random>

std::random_device rd;


class treeBranch {
private:
public:
	treeBranch *parent = nullptr;
	float angle = 1.6;
	float length = 0.0;
	sf::Vector2f pos = sf::Vector2f(0.0, 0.0);
	std::vector<treeBranch *> child;
	treeBranch() {
		*this = treeBranch(250.0, 0.0, 100.0, 90.0);
	}
	treeBranch(float x, float y, float length, float angle) {
		this->pos.x = x;
		this->pos.y = y;
		std::cout << this->pos.x << " " << x << "\n";
		this->length = length;
		this->angle = angle;
	}

	treeBranch *giveBirth(float off) {
		treeBranch *newChild = new treeBranch(pos.x + std::cos(angle)*length, pos.y + std::sin(angle)*length, length * 0.8, angle + off);
		newChild->parent = this; //TODO move this to constructor
		this->child.push_back(newChild);
		return newChild;
	}

	void generate(int gen) {
		if(gen > 0) {
			this->giveBirth(-0.5)->generate(gen - 1);
			this->giveBirth(0.5)->generate(gen - 1);
		}
	}
	void parseTree(sf::VertexArray *vA) {
		vA->append(sf::Vector2f(this->pos.x, this->pos.y));
		vA->append(sf::Vector2f(pos.x + std::cos(angle)*length, pos.y + std::sin(angle)*length)); //

		for(int i = 0; i < child.size(); i++) {
			this->child[i]->parseTree(vA);
		}

	}
};

int main() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	window.setFramerateLimit(1);

	sf::VertexArray lines = sf::VertexArray(sf::Lines, 0);
	treeBranch tree(250, 0, 70, 1.57);
	tree.generate(2);
	tree.parseTree(&lines);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		//DRAW
		window.draw(lines);

		//END DRAW
		window.display();
	}

	return 0;
}