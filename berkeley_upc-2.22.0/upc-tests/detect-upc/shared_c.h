/* This header contains UPC keywords as C identifiers/tags */

/* As variable name */
extern int shared[8];

/* As struct tag and members */
struct shared {
	int	relaxed;
	int	strict;
};

/* As union tag and members */
union relaxed
{
	int	shared;
	float	strict;
};

/* As formal parameter name */
extern void dummy(int shared, int relaxed, int strict);

