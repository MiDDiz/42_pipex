# Template 42

This is a skeleton for projects that use the [libft](https://www.github.com/MiDDiz/42_libft) and aditionally the [ft_printf](https://www.github.com/MiDDiz/ft_printf) function.
Its very easy to use and modify, like adding new libraries that you might want to use.

# What is included

* ## Makefile ready to fill up
  * Custom rules
  * Separate lib management
  * Cleaning cycle
  * Examples for adding new libraries and how to add rules to call their own Makefiles
* ## Folder management modularity
  * Main sourcecode and libraries separated
  * Usage of git modules
  * Capability to add new modules
  * Separated library sourcecode and binaries

## ⚠️Libraries makefiles need to be modified in order to spit the lib.a file outside the module parent folder⚠️
	ar -rcv $@ $^					--> Becomes --> 		ar -rcv ../../$@ $^

	${AR} ${RC} ${NAME} ${OBJS}		--> Becomes -->			${AR} ../../${RC} ${NAME} ${OBJS}
	