NAME = pathfinder

CFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic

INC = inc/pathfinder.h inc/libmx.h

INCS = pathfinder.h libmx.h

SRC = src/main.c src/mx_path_error_first.c src/mx_path_error.c src/mx_path_error2.c src/mx_path_error3.c src/mx_path_array.c src/mx_new_line.c src/mx_path_error_output.c src/mx_path_print.c src/mx_path_print2.c src/mx_sort_way.c src/mx_find_path.c src/mx_init_array.c src/mx_free_array2.c src/mx_free_array3.c src/mx_atoi.c src/mx_dextra_alg.c src/mx_write_zero.c src/mx_displace_left.c

SRCS = main.c mx_path_error_first.c mx_path_error.c mx_path_error2.c mx_path_error3.c mx_path_array.c mx_new_line.c mx_path_error_output.c mx_path_print.c mx_path_print2.c mx_sort_way.c mx_find_path.c mx_init_array.c mx_free_array2.c mx_free_array3.c mx_atoi.c mx_dextra_alg.c mx_write_zero.c mx_displace_left.c

LIB = libmx/libmx.a

LIBS = libmx.a

POBJS = main.o mx_path_error_first.o mx_path_error.o mx_path_error2.o mx_path_error3.o mx_path_array.o mx_new_line.o mx_path_error_output.o mx_path_print.o mx_path_print2.o mx_sort_way.o mx_find_path.o mx_init_array.o mx_free_array2.o mx_free_array3.o mx_atoi.o mx_dextra_alg.o mx_write_zero.o mx_displace_left.o

LOBJS = mx_printchar.o mx_print_unicode.o mx_printstr.o mx_print_strarr.o mx_printint.o mx_pow.o mx_sqrt.o mx_nbr_to_hex.o mx_hex_to_nbr.o mx_itoa.o mx_foreach.o mx_binary_search.o mx_bubble_sort.o mx_quicksort.o mx_strlen.o mx_swap_char.o mx_str_reverse.o mx_strdel.o  mx_del_strarr.o mx_get_char_index.o mx_strdup.o mx_strndup.o mx_strcpy.o mx_strncpy.o mx_strcmp.o mx_strcat.o mx_strstr.o mx_get_substr_index.o mx_count_substr.o mx_count_words.o mx_strnew.o mx_strtrim.o mx_del_extra_spaces.o mx_strsplit.o mx_strjoin.o mx_file_to_str.o mx_read_line.o mx_replace_substr.o mx_memset.o mx_memcpy.o mx_memccpy.o mx_memcmp.o mx_memchr.o mx_memrchr.o mx_memmem.o mx_memmove.o mx_realloc.o mx_create_node.o mx_push_front.o mx_push_back.o mx_pop_front.o mx_pop_back.o mx_list_size.o mx_sort_list.o mx_isspace.o mx_def_end.o mx_def_start.o mx_isdigit.o mx_isalpha.o

POBJ = obj/main.o obj/mx_path_error_first.o obj/mx_path_error.o obj/mx_path_error2.o obj/mx_path_error3.o obj/mx_path_array.o obj/mx_new_line.o obj/mx_path_error_output.o obj/mx_path_print.o obj/mx_path_print2.o obj/mx_sort_way.o obj/mx_find_path.o obj/mx_init_array.o obj/mx_free_array2.o obj/mx_free_array3.o obj/mx_atoi.o obj/mx_dextra_alg.o obj/mx_write_zero.o obj/mx_displace_left.o

OBJ_DIR = obj
all: install clean

install: 
	@make -C libmx
	@cp $(SRC) .
	@cp $(INC) .
	@cp $(LIB) .
	@mkdir -p obj
	@clang $(CFLAG) -c $(SRCS)
	@cp $(POBJS) obj
	@clang $(CFLANG) -o $(NAME) $(POBJS) -L./libmx -lmx
	
uninstall: clean
	@rm -rf $(NAME)
	@make -sC libmx uninstall

clean:
	@rm -rf $(SRCS)
	@rm -rf $(INCS)
	@rm -rf $(LIBS)
	@rm -rf ./obj
	@rm -rf $(POBJS)
	@rm -rf $(LOBJS)
	@make -sC libmx clean
	@rm -rf libmx.a __.SYMDEF\ SORTED inc/libmx.h.gch

reinstall: uninstall install
	