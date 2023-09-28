NAME		=	Abstract

CCP			=	c++

CPPFLAGS		=	-std=c++98 -Werror -Wall -Wextra

SRCS		=	main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp
				
OBJS		=	$(SRCS:.cpp=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CCP) $(CPPFLAGS) $(OBJS) -o $(NAME)
clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all