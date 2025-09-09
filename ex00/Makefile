NAME = megaphone

SRCS = megaphone.cpp

OBJCS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJCS)
	$(CXX) $(CXXFALGS) -o $(NAME) $(OBJCS)

%.o: %.cpp
	$(CXX) $(CXXFALGS) -c $< -o $@

clean:
	rm -f $(OBJCS)
fclean: clean
	rm -f $(NAME)
re: flclean all

.PHONY: all clean flclean re
