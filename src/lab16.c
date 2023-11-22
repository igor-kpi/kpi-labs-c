#include <windows.h>
#include <conio.h>
#include <stdbool.h>

void writeCell(HANDLE con, SHORT x, SHORT y) {
	CHAR_INFO c = {0};
	c.Char.AsciiChar = ' ';
	c.Attributes |= BACKGROUND_GREEN;
	COORD size = {1, 1};
	COORD pos = {0};
	SMALL_RECT writeRegion = {x, y, x, y};
	WriteConsoleOutputA(con, &c, size, pos, &writeRegion);
	Sleep(1);
}

#define setRow(axis, x, y) \
for (int i = 0; i < axis##Amplitude; i++) { \
    int xVal = x;                           \
    int yVal = y;                           \
    if (xVal > width || yVal > height) {    \
        end = true;                         \
        break;                              \
    };                                      \
    writeCell(con, xVal, yVal);             \
}                                           \
axis##Amplitude++;

int lab16() {
	HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO info = {0};
	GetConsoleScreenBufferInfo(con, &info);
	SHORT width = info.srWindow.Right - info.srWindow.Left;
	SHORT height = info.srWindow.Bottom - info.srWindow.Top;

	SetConsoleCursorPosition(con, (COORD) {0});

	DWORD written;
	FillConsoleOutputCharacterA(con, ' ', (width + 1) * (height + 1),
	                            (COORD) {0, 0}, &written);

	enum Direction {
		RightToLeft,
		TopToBottom,
		LeftToRight,
		BottomToTop
	};
	enum Direction dir = RightToLeft;
	int xAmplitude = 1, yAmplitude = 1;
	if (width > height) {
		yAmplitude = 1;
		xAmplitude = width - height;
	} else if (height > width) {
		xAmplitude = 1;
		yAmplitude = height - width;
	}
	COORD center = {width / 2, height / 2};
	int x = center.X + xAmplitude / 2, y = center.Y + yAmplitude / 2;
	boolean end = false;
	while (!end) {
		switch (dir) {
			case RightToLeft: {
				setRow(x, x--, y);
				dir = TopToBottom;
				break;
			}
			case TopToBottom: {
				setRow(y, x, y++);
				dir = LeftToRight;
				break;
			}
			case LeftToRight: {
				setRow(x, x++, y);
				dir = BottomToTop;
				break;
			}
			case BottomToTop: {
				setRow(y, x, y--);
				dir = RightToLeft;
				break;
			}
		}
	}

	getch();
	SetConsoleCursorPosition(con, (COORD) {info.srWindow.Right, info.srWindow.Bottom});

	return 0;
}