NAME := Bureaucrat
NICKNAME := Bureaucrat
CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -g -fsanitize=address -std=c++17
SRC :=	main.cpp \
		Bureaucrat.cpp \
		Form.cpp
		
HDR := Bureaucrat.hpp
OBJ := $(SRC:.cpp=.o)

GREEN := \033[32;1m
YELLOW := \033[33;1m
RED := \033[31;1m
BOLD := \033[1m
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "%b%s%b" "$(YELLOW)$(BOLD)" "Compiling $(NICKNAME)..." "$(RESET)"
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@printf "\t\t%b%s%b\n" "$(GREEN)$(BOLD)" "[OK]" "$(RESET)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

open: $(NAME)
	@./$(NAME)

clean:
	@echo "$(RED)$(BOLD)Cleaning $(NICKNAME)...$(RESET)"
	@rm -f $(OBJ)

fclean:
	@echo "$(RED)$(BOLD)Fully cleaning $(NICKNAME)...$(RESET)"
	@rm -f $(NAME) $(OBJ)

re: fclean $(NAME)

.PHONY: all clean fclean re
