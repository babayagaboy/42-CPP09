# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/14 20:00:02 by hgutterr          #+#    #+#              #
#    Updated: 2026/07/14 20:00:02 by hgutterr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= btc

CXX 		= c++
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98

SRCS		=	main.cpp \
				BitcoinExchange.cpp

OBJDIR		= obj
OBJS		= $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\nReady!"

$(OBJDIR)/%.o: %.cpp BitcoinExchange.hpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

noflags:
	$(CXX) $(SRCS) -o $(NAME)
	@echo "\nReady without flags!"

re: fclean all

.PHONY: all clean fclean re
