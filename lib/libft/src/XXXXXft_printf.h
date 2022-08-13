
#ifndef FT_PRINTF_H // Conditional compilation
#define FT_PRINTF_H // Macro definition

# include <stdlib.h> //size_t, NULL
# include <stdarg.h> // All the macros to use variable args (va_list)
//# include <unistd.h>

# define HEX_BASE_LOWER	"0123456789abcdef"
# define HEX_BASE_UPPER	"0123456789ABCDEF"
# define DEC_BASE		"0123456789"
# define STR_NULL		"(null)"
# define PTR_NULL		"(nil)"
# define INI_PTR		"0x"
# define NEG_PTR		"FFFFFFFF"

int		ft_printf(const char* str, ...);

int		ft_print_char(char c);
int		ft_print_string(char* str);
int		ft_print_dec_int(long nbr);
int		ft_print_pointer(void* ptr);
int		ft_print_hexa(unsigned int nbr, char spec);

size_t	ft_strlen(const char* s);
void	ft_putchar(char c);
int		ft_putstr(char* str);
void	ft_free(char* ptr);
char* ft_itoa_base(unsigned long long nbr, char* base);

#endif
