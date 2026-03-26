# Program name
NAME := iter

# Directories
SRCDIR := src
OBJDIR := obj
INCDIR := include

# Compiler and Flags
CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
CXXFLAGS	+= -std=c++20
CXXFLAGS	+= -MMD
CXXFLAGS	+= -MP
CXXFLAGS	+= -g
CPPFLAGS	:= -I $(INCDIR)

# Source files
SRCS :=	main.cpp \

# Objects and Dependencies
SRCPATH := $(addprefix $(SRCDIR)/,$(SRCS))
OBJS := $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCPATH:.cpp=.o))
DEPS := $(OBJS:.o=.d)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp Makefile
	@mkdir -p $(dir $@)
	@echo $(BLUE)Compiling $@$(RESET)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo $(GREEN)$(NAME) compiled$(RESET)

.PHONY: clean
clean:
	@echo $(BRIGHT_RED)Removing $(OBJDIR)$(RESET)
	@rm -rf $(OBJDIR)
	@echo $(BRIGHT_RED)$(OBJDIR) removed$(RESET)

.PHONY: fclean
fclean: clean
	@echo $(RED)Removing $(NAME)$(RESET)
	@rm -rf $(NAME)
	@echo $(RED)$(NAME) removed$(RESET)

.PHONY: re
re: fclean all

-include $(DEPS)

# Colors
BLACK	:= "\e[0;30m"
RED		:= "\e[0;31m"
GREEN	:= "\e[0;32m"
YELLOW	:= "\e[0;33m"
BLUE	:= "\e[0;34m"
PURPLE	:= "\e[0;35m"
CYAN	:= "\e[0;36m"
WHITE	:= "\e[0;37m"

BRIGHT_BLACK	:= "\e[0;90m"
BRIGHT_RED		:= "\e[0;91m"
BRIGHT_GREEN	:= "\e[0;92m"
BRIGHT_YELLOW	:= "\e[0;93m"
BRIGHT_BLUE		:= "\e[0;94m"
BRIGHT_PURPLE	:= "\e[0;95m"
BRIGHT_CYAN		:= "\e[0;96m"
BRIGHT_WHITE	:= "\e[0;97m"

RESET	:= "\e[0m"