NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp

OBJ_DIR = .objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@cp $(NAME) ../

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo -e "\033[2J\033[H"
	@echo "\033[1;34mCompiling >\033[0m\033[1;32m< $<\033[0m"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME) ../$(NAME)

re: fclean all

c:clean
f:fclean
r:re

.PHONY: all clean fclean re