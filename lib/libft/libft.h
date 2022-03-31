/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:18:57 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/03/31 01:19:09 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ***** Part 1 - Libc Functions ***** */

/**
 * @brief Checks if c is an alphabetic character in ASCII
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		ft_isalpha(int c);

/**
 * @brief Checks if c is a digit in ASCII
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		ft_isdigit(int c);

/**
 * @brief Checks for an alphanumeric character in ASCII
 *
 * @param c  Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		ft_isalnum(int c);

/**
 * @brief Checks whether c is a 7-bit unsigned char value that fits into the
 * ASCII character set
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		ft_isascii(int c);

/**
 * @brief Checks if C is a printable character in ASCII
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		ft_isprint(int c);

/**
 * @brief Calculates the length of the string s, excluding the terminatig null
 * byte
 *
 * @param s Constant string to be analysed
 * @return size_t Returns the number of bytes in the string s
*/
size_t	ft_strlen(const char *s);

/**
 * @brief Writes len bytes of value c (converted to an unsigned char) to the
 * string dest. Undefined behaviour from memset(), resulting from storage
 * overflow, will occur if len is greater than the length of the buffer dest.
 * The behaviour is also undefined if dest is an invalid pointer
 *
 * @param dest Starting address of memory to be filled
 * @param c Value to be filled
 * @param len The buffer size in bytes
 * @return *void Returns its first argument
*/
void	*ft_memset(void *dest, int c, size_t len);

/**
 * @brief Sets the first len bytes of the area starting at s to zero
 *
 * @param s Starting address
 * @param len The buffer size in bytes
 * @return void None
*/
void	ft_bzero(void *s, size_t len);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 * areas must not overlap
 *
 * @param dest Pointer to destination memory area address
 * @param src Pointer to source memory area address
 * @param n Buffer size in bytes
 * @return void* Returns dest
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 * areas may overlap: copying takes place as though the bytes in src are first
 * copied into a temporary array that does not overlap src or dest, and the
 * bytes are then copied from the temporary array to dest
 *
 * @param dest Pointer to destination memory area
 * @param src Pointer to source memory area
 * @param n Buffer size in bytes
 * @return void* Returns dest
*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Copies up to (size - 1) bytes from the NUL-terminated string src to
 * dest, NUL-terminating the result
 *
 * @param dest Destination string
 * @param src Source string
 * @param size Buffer size in bytes
 * @return size_t Returns the length of src
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Appends the NUL-terminated string src to the end of dst. It will
 * append at most (size - strlen(dest) - 1) bytes, NUL-terminating the result
 *
 * @param dest Destination pointer to memory area
 * @param src Source pointer to memory area
 * @param size Buffer size in bytes
 *
 * @return size_t Initial length of dest + length of src
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size);

/**
 * @brief Converts the letter c to lowercase, if possible
 *
 * @param c Letter to be converted
 * @return int  Returns the converted letter, or c if the convertion was not
 * possible
*/
int		ft_tolower(int c);

/**
 * @brief Converts the letter c to uppercase, if possible
 *
 * @param c Letter to be converted
 * @return int  Returns the converted letter, or c if the convertion was not
 * possible
*/
int		ft_toupper(int c);

/**
 * @brief Returns a pointer to the first occurrence of the character in the
 * string s
 *
 * @param s The source string
 * @param c The character to be found
 * @return char* Returns the pointer to c if found or NULL if not
*/
char	*ft_strchr(const char *s, int c);

/**
 * @brief Returns a pointer to the last occurrence of the character in the
 * string s
 *
 * @param s The source string
 * @param c The character to be found
 * @return char* Returns the pointer to c if found or NULL if not
*/
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Compares the first n bytes of s1 and s2
 *
 * @param s1 Pointer to the first string
 * @param s2 Pointer to the second string
 * @param n Number of bytes to be compared
 * @return int Returns an integer less than, equal to, or greather than zero if
 * s1 is found, respectively, to be less than, to match, or be greater than s2
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s for the
 * first instance of c. Both c and the bytes of the memory area pointed to by s
 * are interpreted as unsigned char
 *
 * @param s Source pointer to memory area
 * @param c The character to be searched
 * @param n Buffer size in bytes
 * @return void* Returns a pointer to the matching byte, if one is found. If no
 * matching byte if found, the result is unspecified
*/
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of the memory areas s1 and s2
 *
 * @param s1 First string pointer to memory area
 * @param s2 Second string pointer to memory area
 * @param n Buffer size in bytes
 * @return int Returns an integer less than, equal to, or greater than zero if
 * the first n bytes of s1 is found, respectively, to be less than, to match, or
 * be greater than the first n bytes of s2.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Locates the first occurence of the null-terminated string little in
 * the null-terminated string big
 *
 * @param big The bigger string that can contain little
 * @param little The substring in big
 * @param n The buffer size in bytes
 * @return char* If little is an empty string, big is returned; if little occurs
 * nowhere in big, NULL is returned; otherwise a pointer to the first character
 * of the first occurance of little is returned
*/
char	*ft_strnstr(const char *big, const char *little, size_t n);

/**
 * @brief Converts a character string to an integer value. The function stops
 * reading str at the first character that it cannot recognize as part of a
 * number. It ignores leading white-space characters. It does not recognize
 * decimal points or expoents
 *
 * @param str Pointer to character string
 * @return int The converted value
*/
int		ft_atoi(const char *str);

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each and
 * returns a pointer to the allocated memory. The memory is set to zero. If
 * nmemb or size is 0, then calloc returns either NULL, or a unique pointer
 * value that can later be succesfully passed to free()
 *
 * @param nmemb Number of elements in the array
 * @param size Size in bytes for each element
 * @return void* Returns a pointer to the allocated memory. On error, it will
 * return NULL
*/
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Returns a pointer to a new string which is a duplicate of the string
 * s. Memory for the new string is obtained with malloc
 *
 * @param s The string to be copied
 * @Return char* Returns a pointer to the duplicated string, or NULL if
 * insufficient memory was available
*/
char	*ft_strdup(const char *s);

/* ***** Part 2 - Additional Functions ***** */

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string s.
 * The substring begin at index 'start' and is of maximum size 'len'
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'
 * @param len The maximum length of the substring
 * @return char* The substring. NULL if the allocation fails
*/
char	*ft_substr(const char *s, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of 's1' and 's2'
 *
 * @param s1 The prefix string
 * @param s2 The suffix string
 * @return char* The new string. NULL if the allocation fails
*/
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates (with malloc (3)) and returns a copy of 's1' with the
 * characters specified in 'set'removed from the beginning and the end of the
 * string
 *
 * @param s1 The string to be trimmed
 * @param s2 The reference set of characters to trim
 * @return char* The trimmed string. NULL if the allocation fails
*/
char	*ft_strtrim(const char *s1, const char *set);

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings obtained by
 * splitting 's' using the character 'c' as a delimeter. The array must be ended
 * by a NULL pointer
 *
 * @param s The string to be split
 * @param c The delimeter character
 * @return char The array of new strings resulting from the split. NULL if the
 * allocation fails.
*/
char	**ft_split(const char *s, char c);

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the
 * integer received as an argument. Negative numbers msut be handled
 *
 * @param n The integer to convert
 * @return The string representing the integer received as argument. Negative
 * numbers must be handled.
*/
char	*ft_itoa(int n);

/**
 * @brief Applies the function 'f' to each character of the string 's' to create
 * a new string (with malloc(3)) resulting from successive applications of 'f'
 *
 * @param s The string on which to iterate
 * @param f The function to apply to each character
 * @return char The string created from the successive applications of 'f'.
 * Returns NULL of the allocation fails
*/
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/**
 * @brief Applies to the function f to each character of the string passed as
 * argument, and passing its index as first argument. Each character is passed
 * by address to f to be modified if necessary
 *
 * @param s The string on which to iterate
 * @param f The function to apply to each character
 * @return None
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Outputs the character 'c' to the given file descriptor
 *
 * @param c The character to output
 * @param fd The file descriptor on which to write
 * @return None
*/
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor
 *
 * @param s The string to output
 * @param fd The file descriptor on which to write
 * @return None
*/
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor, followed by a
 * newline
 *
 * @param s The string to output
 * @param fd The file descriptor on which to write
 * @return None
*/
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer 'n' to the given file descriptor
 *
 * @param n The integer to output
 * @param fd The file descriptor on which to write
 * @return None
*/
void	ft_putnbr_fd(int n, int fd);

/* ***** Bonus Functions ***** */

/**
 * @brief Allocates (with malloc(3)) and returns a new element. The variable
 * 'content' is initialized with the value of the parameter 'content'. The
 * variable 'next' is initialized to NULL
 *
 * @param content The content to create the new element with
 * @return t_list The new element
*/
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds the element 'new' at the beginning of the list
 *
 * @param lst The address of a pointer to the first link of a list
 * @param new The address of a pointer to the element to be added to the list
 * @return None
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of elements in a list
 *
 * @param lst The beginning of the list
 * @return int The length of the list
*/
int		ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of the list
 *
 * @param lst The beginning of the list
 * @return t_list The last element of the list
*/
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds the element 'new'at the end of the list
 *
 * @param lst The address of a pointer to the first link of a list
 * @param new The address of a pointer to the element to be added to the list
 * @return None
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a paremeter an element and frees the memory of the element's
 * content using the function 'del' given as a parameter and free the element.
 * The memory of 'next' must not be freed
 *
 * @param lst The element to free
 * @param del The address of the function used to delete the content
 * @return None
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * *@brief Deletes and frees the given element and every successor of that
 * element, using the function del and free(3). Finally, the pointer to list
 * must be set to NULL
 *
 * @param lst The address of a pointer to an element
 * @param del The address of the function used to delete the content of the
 * element
 * @return None
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' to the content of
 * each element
 *
 * @param lst The address of a pointer to an element
 * @param f The address of the function used to iterate on the list
 * @return None
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' to the content of
 * each element. Creates a new list resulting of the successive applications of
 * the function 'f', The 'del' function is used to delete the content of an
 * element if needed
 *
 * @param lst The address of a pointer to an element
 * @param f The address of the function used to iterate on the list
 * @param del The address of the function used to delete the content of an
 * element if needed
 * @return t_list The new list. NULL if the allocation fails
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/** ***** EXTRA FUNCTIONS ***** */

/**
 * @brief Write a function which returns a line read from a file descriptor
 *
 * @param fd File descriptor to read from
 * @return Read line or NULL if nothing else to read or an error accurred
*/
char		*get_next_line(int fd);

/**
 * @brief Free and assign NULL to 'ptr'
 *
 * @param ptr The pointer to reset
 * @return NULL
*/
void		*reset_ptr(void *ptr);

/**
 * @brief Write output to the standard to stdout
 *
 * @param input The format string
 * @return The n of printed characters
*/
int	ft_printf(const char *input, ...);

#endif
