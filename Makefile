NAME_STD = test_std
NAME_FT = test_ft

HEADERS_FILE = headers

HEADERS = \
			headers/ft.hpp \
			headers/Pair.hpp \
			headers/Map.hpp \
			headers/Equal.hpp \
			headers/Lexicographical_compare.hpp \
			headers/Stack.hpp \
			headers/externals.hpp \
			headers/Vector.hpp \
			headers/Is_integral.hpp \
			headers/Iterator_traits.hpp \
			headers/Base_iterator.hpp \
			headers/Reverse_iterator.hpp

SRC_FT = srcs/test_ft.cpp
SRC_STD = srcs/test_std.cpp

OBJ_FT = ${SRC_FT:.cpp=.o}
OBJ_STD = ${SRC_STD:.cpp=.o}

.PHONY: all clean fclean re

all: $(NAME_FT) $(NAME_STD)

$(NAME_FT): $(OBJ_FT) $(HEADERS)
	clang++ $(OBJ_FT) -o $(NAME_FT)

$(NAME_STD): $(OBJ_STD) $(HEADERS)
	clang++ $(OBJ_STD) -o $(NAME_STD)

$(OBJ_FT): %.o: %.cpp $(HEADERS)
	clang++ -Wall -Wextra -Werror -std=c++98 -I$(HEADERS_FILE) -c $< -o $@

$(OBJ_STD): %.o: %.cpp $(HEADERS)
	clang++ -Wall -Wextra -Werror -std=c++98 -I$(HEADERS_FILE) -c $< -o $@

clean:
	rm -f $(OBJ_FT) $(OBJ_STD)

fclean: clean
	rm -f $(NAME_FT) $(NAME_STD)

re: fclean all
