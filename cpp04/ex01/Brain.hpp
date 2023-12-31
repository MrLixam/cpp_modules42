#ifndef __BRAIN__
# define __BRAIN__

#include <string>

class Brain
{
	public:
		Brain(void);
		~Brain(void);
		Brain(Brain &copy);
		Brain& operator=(const Brain& x);
		void setIdea(size_t n, std::string idea);
		void showIdeas(void) const;
	private:
		std::string ideas[100];
};

#endif