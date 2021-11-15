NAME = test

HEADERS_FILE = headers

HEADERS = \
			headers/ft.hpp \
			headers/externals.hpp \
			headers/Vector.hpp \
			headers/Is_integral.hpp \
			headers/Enable_if.hpp \
			headers/Iterator_traits.hpp \
			headers/Base_iterator.hpp \
			headers/Reverse_iterator.hpp

SRCS = \
		srcs/test_vector_modifier_functions.cpp
		# srcs/test_vector_capacity_functions.cpp

OBJS = ${SRCS:.cpp=.o}

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	clang++ $(OBJS) -o $(NAME)

$(OBJS): %.o: %.cpp $(HEADERS)
	clang++ -Wall -Wextra -Werror -std=c++98 -I$(HEADERS_FILE) -c $< -o $@
	#clang++ -std=c++98 -I$(HEADERS_FILE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
