NAME		=	Interface

CCP			=	c++

CPPFLAGS		=	-std=c++98 -Werror -Wall -Wextra

SRCS		=	main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
				
OBJS		=	$(SRCS:.cpp=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CCP) $(CPPFLAGS) $(OBJS) -o $(NAME)
clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all
