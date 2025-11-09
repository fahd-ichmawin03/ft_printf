
#include "ft_printf.h"

int	pf_verify(char c);
int	ft_putchar(int c);

int	pf_print(va_list *ap, char spec, int count)
{
	if (spec == 'c')
		count = ft_putchar(va_arg(*ap, int));
	else if (spec == '%')
		count = ft_putchar('%');
	else if (spec == 's')
		count = ft_putstr(va_arg(*ap, char *));
	else if (spec == 'i' || spec == 'd')
		count = ft_putnbr(va_arg(*ap, int), 0);
	else if (spec == 'u')
		count = ft_putunbr(va_arg(*ap, unsigned int), 0);
	else if (spec == 'x')
		count = ft_putnbr_hexa(va_arg(*ap, unsigned int), 0);
	else if (spec == 'X')
		count = ft_putnbr_hexa(va_arg(*ap, unsigned int), -32);
	else if (spec == 'p')
		count = ft_ptr(va_arg(*ap, unsigned long long), 0);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] && pf_verify(format[i + 1]))
		{
			count += pf_print(&ap, format[++i], 0);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

int	pf_verify(char c)
{
	char	*spec;

	spec = "cspdiuxX%";
	while (*spec)
	{
		if (*spec == c)
			return (1);
		spec++;
	}
	return (0);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int     real_count;
    int     fake_count;
    char    *str = "Hello, world!";
    char    *null_str = NULL;
    int     n = -12345;
    unsigned int u = 4294967296;
    void    *ptr = &n;

    printf("===== 🔍 TEST DE COMPARAISON printf VS ft_printf =====\n\n");

    // 1️⃣ Test de base
    real_count = printf("printf : Salut %s !\n", "Fahd");
    fake_count = ft_printf("ft_printf : Salut %s !\n\n", "Fahd");
    printf("count -> printf: %d | ft_printf: %d\n\n", real_count, fake_count);

    // 2️⃣ Test avec caractères et pourcentages
    real_count = printf("printf : %% | %c | %c\n", 'A', 'Z');
    fake_count = ft_printf("ft_printf : %% | %c | %c\n\n", 'A', 'Z');
    printf("count -> printf: %d | ft_printf: %d\n\n", real_count, fake_count);

    // 3️⃣ Test nombres signés
    real_count = printf("printf : %d | %i | %+d | % d\n", n, n, n, n);
    fake_count = ft_printf("ft_printf : %d | %i | %+d | % d\n\n", n, n, n, n);
    printf("count -> printf: %d | ft_printf: %d\n\n", real_count, fake_count);

    // 4️⃣ Test unsigned
    real_count = printf("printf : unsigned = %u\n", u);
    fake_count = ft_printf("ft_printf : unsigned = %u\n\n", u);
    printf("count -> printf: %d | ft_printf: %d\n\n", real_count, fake_count);

    // 5️⃣ Test hexadécimal minuscule et majuscule
    real_count = printf("printf : hex = %x | HEX = %X\n", 305441741, 305441741);
    fake_count = ft_printf("ft_printf : hex = %x | HEX = %X\n\n", 305441741, 305441741);
    printf("count -> printf: %d | ft_printf: %d\n\n", real_count, fake_count);

    // 6️⃣ Test pointeurs
    real_count = printf("printf : ptr = %p | null = %p\n", ptr, NULL);
    fake_count = ft_printf("ft_printf : ptr = %p | null = %p\n\n", ptr, NULL);
    printf("count -> printf: %d | ft_printf: %d\n\n", real_count, fake_count);

    // 7️⃣ Test chaînes nulles et longues
    real_count = printf("printf : str = %s | null = %s\n", str, null_str);
    fake_count = ft_printf("ft_printf : str = %s | null = %s\n\n", str, null_str);
    printf("count -> printf: %d | ft_printf: %d\n\n", real_count, fake_count);

    // 8️⃣ Test combinaison complexe
    real_count = printf("printf : %c %s %p %d %u %x %X %%\n",
                        'F', "test", ptr, -42, 42u, 4242, 4242);
    fake_count = ft_printf("ft_printf : %c %s %p %d %u %x %X %%\n\n",
                        'F', "test", ptr, -42, 42u, 4242, 4242);
    printf("count -> printf: %d | ft_printf: %d\n\n", real_count, fake_count);

    // 9️⃣ Test limite d'entier
    real_count = printf("printf : INT_MIN = %d | INT_MAX = %d\n", -2147483648, 2147483647);
    fake_count = ft_printf("ft_printf : INT_MIN = %d | INT_MAX = %d\n\n", -2147483648, 2147483647);
    printf("count -> printf: %d | ft_printf: %d\n\n", real_count, fake_count);

    // 🔟 Test mélange de tout
    real_count = printf("printf : %c %s %i %u %x %p %% %s\n", 
                        'A', "Mix", 123, 123u, 0x123ab, &n, "fin");
    fake_count = ft_printf("ft_printf : %c %s %i %u %x %p %% %s\n\n", 
                        'A', "Mix", 123, 123u, 0x123ab, &n, "fin");
    printf("count -> printf: %d | ft_printf: %d\n\n", real_count, fake_count);

    return 0;
}
