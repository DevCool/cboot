#ifndef _IO_H_
#define _IO_H_

/* putch:  puts a character on the screen */
static void
putch (char c, unsigned char color)
{
	__asm__ __volatile__ ("int $0x10"::"a"(0x0e00 | c), "b"(0x0000 | color));
}
/* putchar:  puts a character on the screen; with color gray on black */
#define putchar(c) putch(c, 0x07)

/* move:  moves cursor to x,y position */
static void
move (unsigned char x, unsigned char y)
{
	__asm__ __volatile__ ("int $0x10"
			::"a"(0x0200), "b"(0x0007), "d"((y << 8) | x));
}

/* print_color:  prints a string in color */
static void
print_color (const char *s, unsigned char color)
{
	while (*s) {
		putch(*s++, color);
	}
}
/* print:  prints a string normal color */
#define print(msg) print_color(msg, 0x07)

/* getch:  get character from keyboard */
static char
getch (void)
{
	char ch;
	__asm__ __volatile__ ("int $0x16":"=a"(ch):"a"(0x0000));
	__asm__ __volatile__ ("int $0x16"::"a"(0x0100));
	return ch;
}

/* getche_color:  get character from keyboard; put to screen in color */
static char
getche_color (unsigned char color)
{
	char ch;
	ch = getch();
	putch(ch, color);
	return ch;
}
#define getche() getche_color(0x07)

/* draw_pixel:  draws a pixel at specified location */
static void
draw_pixel (unsigned short x, unsigned short y, short unsigned int color)
{
	__asm__ __volatile__ ("int $0x10"::"a"(0x0c00 | color), "c"(y), "d"(x));
}

#endif
